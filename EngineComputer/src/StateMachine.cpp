#include <statemachine.h>
#include <globals.h>
#include <config.h>

uint32_t t0 = 0, timeIgnitionExpected = 0, timeLastHeartbeat = 0;
bool proceedFlag = false, manualProceedFlag = false, manualAbortFlag = false;
bool ignitorContinuityChecked = false, internalPowerVoltageChecked = false;
bool stateJustChanged = false;
inline void setAbortFlags();
inline void handleAborts();

void manualAbort()
{
    manualAbortFlag = true;
}
void manualProceed()
{
    manualProceedFlag = true;
}
void forceGoto(ENGINE_COMPUTER_STATE new_state)
{
    g.status.state = new_state;
}
void gotHeartbeat()
{
    timeLastHeartbeat = HAL_GetTick();
}
//set abort flags based on situation
inline void setAbortFlags()
{
    //fuel tank overpress
    if (g.tanks.fuel_tank_pressure > FUEL_TANK_PRESSURE_ABORT_LEVEL)
    {
        g.status.abort_flags |= ABORT_FLAGS_FUEL_TANK_OVERPRESS;
    }
    //ox tank overpress
    if (g.tanks.ox_tank_pressure > OX_TANK_PRESSURE_ABORT_LEVEL)
    {
        g.status.abort_flags |= ABORT_FLAGS_OX_TANK_OVERPRESS;
    }
    //fuel inj overpress
    if (g.engine.fuel_injector_pressure > FUEL_INJ_PRESSURE_ABORT_LEVEL)
    {
        g.status.abort_flags |= ABORT_FLAGS_FUEL_INJ_OVERPRESS;
    }
    //ox inj overpress
    if (g.engine.ox_injector_pressure > OX_INJ_PRESSURE_ABORT_LEVEL)
    {
        g.status.abort_flags |= ABORT_FLAGS_OX_INJ_OVERPRESS;
    }
    //ignition timeout
    if (g.status.state == ENGINE_COMPUTER_STATE_IGNITION_AUTOSEQ &&
        HAL_GetTick() > t0)
    //this abort can only happen in ignition autosequence
    //it happens if we're in the ignition autosequence past the t=0 point
    //if the operator gives a GO to proceed to the burn autosequence,
    //because they saw an ignition flame, we're safe.
    {
        g.status.abort_flags |= ABORT_FLAGS_IGNITION_TIMEOUT;
    }
    //link lost
    if (HAL_GetTick() > (timeLastHeartbeat + LINK_TIMEOUT_ABORT_LEVEL))
    //compares time to last heartbeat received with interval from config to determine whether to abort
    //doing this instead of a subtraction avoids rollover error
    {
        g.status.abort_flags |= ABORT_FLAGS_LINK_TIMEOUT;
    }
    //power fault
    if (g.status.voltage < VOLTAGE_ABORT_LEVEL)
    //any time system voltage is too low - does not matter if we're on battery or external power
    //this means it will abort if we switch from good external to a low battery internal
    {
        g.status.abort_flags |= ABORT_FLAGS_POWER_FAULT;
    }
    //manual abort
    if (manualAbortFlag)
    {
        g.status.abort_flags |= ABORT_FLAGS_MANUAL_ABORT;
        manualAbortFlag = false; //reset flag so we don't keep on running this
    }
}
//take action based on abort flag(s) to avert disaster(s)
inline void handleAborts()
{
    if (g.status.abort_flags & ABORT_FLAGS_FUEL_TANK_OVERPRESS)
    {
        //vent through main valve if fill line connected, since vent valve is then blocked
        if (g.tanks.fill_lines_detected & TANK_FLAGS_FUEL)
        {
            g.engine.fuel_main_valve_goal_position = 100;
            g.tanks.fuel_vent_valve_goal_position = 0;
        }
        else
        {
            g.engine.fuel_main_valve_goal_position = 0;
            g.tanks.fuel_vent_valve_goal_position = 100;
        }
    }
    //ox tank venting
    if (g.status.abort_flags & ABORT_FLAGS_OX_TANK_OVERPRESS)
    {
        //vent through main valve if fill line connected, since vent valve is then blocked
        if (g.tanks.fill_lines_detected & TANK_FLAGS_OX)
        {
            g.engine.ox_main_valve_goal_position = 100;
            g.tanks.ox_vent_valve_goal_position = 0;
        }
        else
        {
            g.engine.ox_main_valve_goal_position = 0;
            g.tanks.ox_vent_valve_goal_position = 100;
        }
    }
    //if the connection to the ground station is lost, get back manual control of all valves
    if (g.status.abort_flags & LINK_TIMEOUT_ABORT_LEVEL)
    {
        g.engine.fuel_main_valve_status &= ~VALVE_FLAGS_MANUAL_OVERRIDE;
        g.engine.ox_main_valve_status &= ~VALVE_FLAGS_MANUAL_OVERRIDE;
        g.tanks.fuel_vent_valve_status &= ~VALVE_FLAGS_MANUAL_OVERRIDE;
        g.tanks.ox_vent_valve_status &= ~VALVE_FLAGS_MANUAL_OVERRIDE;
    }
    //we don't worry about handling these aborts, since they should get fixed during g.engine shutdowns
    if (g.status.abort_flags & ABORT_FLAGS_FUEL_INJ_OVERPRESS)
        ;
    if (g.status.abort_flags & ABORT_FLAGS_OX_INJ_OVERPRESS)
        ;
    //should get resolved by doing ignition abort sequence
    if (g.status.abort_flags & ABORT_FLAGS_IGNITION_TIMEOUT)
        ;
    //don't need to do anything special if there's a manual abort
    if (g.status.abort_flags & ABORT_FLAGS_MANUAL_ABORT)
        ;
    //this one doesn't need much help either
    if (g.status.abort_flags & ABORT_FLAGS_POWER_FAULT)
        ;
}
void stateMachine()
{
    uint32_t t = HAL_GetTick();
    uint8_t valveAutoPositions[4] = {0, 0, 0, 0}; //when in auto control, valves will close most of the time. exceptions are during burn sequence
    //main state machine switch
    //each state does the following:
    //set proceed_state and abort_state to what they should be
    //set met_proceed_conditions flag if conditions met
    switch (g.status.state)
    {
    //normal states, in sequence used
    case ENGINE_COMPUTER_STATE_PREFLIGHT_CHECK:
    {
        //decide what next state will be if we can proceed or if we can abort
        g.status.state_proceed = ENGINE_COMPUTER_STATE_FUEL_PRESS;
        g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_GENERIC;
        if (g.engine.ignitor_flags & IGNITOR_FLAGS_CONTINUITY)
        {
            ignitorContinuityChecked = true;
        }
        if (g.status.power_source == POWER_SOURCE_INTERNAL && g.status.voltage > MIN_VOLTAGE_OK)
        {
            internalPowerVoltageChecked = true;
        }
        //decide whether to proceed
        if (manualProceedFlag &&                                //manual proceed required
            g.engine.fuel_injector_pressure < MAX_ZERO_PRESS && //all pressures 0
            g.engine.ox_injector_pressure < MAX_ZERO_PRESS &&
            g.tanks.fuel_tank_pressure < MAX_ZERO_PRESS &&
            g.tanks.ox_tank_pressure < MAX_ZERO_PRESS &&
            g.engine.thrust < MAX_ZERO_THRUST &&                    //thrust 0
            ignitorContinuityChecked &&                             //ignitor continuity was good
            !(g.engine.ignitor_flags & IGNITOR_FLAGS_CONTINUITY) && //ignitor is no longer armed though
            internalPowerVoltageChecked &&                          //internal battery voltage was good
            g.status.power_source == POWER_SOURCE_EXTERNAL &&       //we're on external power now though
            g.status.voltage > MIN_VOLTAGE_OK)                      //and external voltage is good too
        {
            proceedFlag = true;
        }
        break; //don't forget 'em or you'll have a bad day
    }
    case ENGINE_COMPUTER_STATE_FUEL_PRESS:
    {
        g.status.state_proceed = ENGINE_COMPUTER_STATE_OX_PRESS;
        g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_GENERIC;
        if (manualProceedFlag &&                              //manual proceed required
            g.tanks.fuel_tank_pressure > MIN_FUEL_PRESS_OK && //fuel tank pressurized to proper level
            g.tanks.fuel_tank_pressure < MAX_SAFE_FUEL_PRESS &&
            !(g.tanks.fill_lines_detected & TANK_FLAGS_FUEL)) //fuel tank fill line is disconnected
        {
            proceedFlag = true;
        }
        break;
    }
    case ENGINE_COMPUTER_STATE_OX_PRESS:
    {
        g.status.state_proceed = ENGINE_COMPUTER_STATE_IGNITION_AUTOSEQ;
        g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_GENERIC;
        if (manualProceedFlag &&                              //manual proceed required
            g.tanks.fuel_tank_pressure > MIN_FUEL_PRESS_OK && //fuel tank pressure still good
            g.tanks.fuel_tank_pressure < MAX_SAFE_FUEL_PRESS &&
            !(g.tanks.fill_lines_detected & TANK_FLAGS_FUEL) && //fuel fill line still off
            g.tanks.ox_tank_pressure > MIN_OX_PRESS_OK &&       //ox tank pressure good
            g.tanks.ox_tank_pressure < MAX_SAFE_OX_PRESS &&
            !(g.tanks.fill_lines_detected & TANK_FLAGS_OX) &&   //ox fill line off
            g.engine.fuel_injector_pressure < MAX_ZERO_PRESS && //fuel injector pressures zero
            g.engine.ox_injector_pressure < MAX_ZERO_PRESS &&
            g.engine.thrust < MAX_ZERO_THRUST &&                   //thrust 0
            (g.engine.ignitor_flags & IGNITOR_FLAGS_CONTINUITY) && //ignitor has continuity
            g.status.voltage > MIN_VOLTAGE_OK &&                   //voltage high enough
            g.status.power_source == POWER_SOURCE_INTERNAL)        //we're on internal power
        {
            proceedFlag = true;
        }
        break;
    }
    case ENGINE_COMPUTER_STATE_IGNITION_AUTOSEQ:
    {
        g.status.state_proceed = ENGINE_COMPUTER_STATE_BURN_AUTOSEQ;
        g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_DURING_BURN;
        if (stateJustChanged) //start the countdown
        {
            t0 = t + COUNTDOWN_TIME;
        }
        g.status.time = (t - t0) / 100; //set the countdown time in the struct
        //autosequence
        if (t > t0 - IGNITION_TIME)
        {
            //fire ignitor
            g.engine.ignitor_flags |= IGNITOR_FLAGS_FIRING;
        }
        if (t > t0 - ADD_OX_TIME)
        {
            //add trickle of oxidizer
            valveAutoPositions[VALVE_ID_OX_MAIN] = OX_IGN_AMT;
        }
        if (t > t0 - ADD_FUEL_TIME)
        {
            //add trickle of fuel
            valveAutoPositions[VALVE_ID_FUEL_MAIN] = FUEL_IGN_AMT;
        }
        if (manualProceedFlag)
        {
            proceedFlag = true; //go to burn sequence as soon as operator allows it because *they have seen the flame*
        }
        break;
    }
    case ENGINE_COMPUTER_STATE_BURN_AUTOSEQ:
    {
        g.status.state_proceed = ENGINE_COMPUTER_STATE_ENGINE_CUTOFF;
        g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_DURING_BURN; //hmmm should we hard or soft abort?
        //open main propellant valves
        valveAutoPositions[VALVE_ID_FUEL_MAIN] = 100;
        valveAutoPositions[VALVE_ID_OX_MAIN] = 100;
        //shut off the ignitor
        g.engine.ignitor_flags &= ~IGNITOR_FLAGS_FIRING;

        if (g.engine.fuel_injector_pressure < MAX_ZERO_PRESS &&
            g.engine.ox_injector_pressure < MAX_ZERO_PRESS &&
            g.tanks.fuel_tank_pressure < MAX_ZERO_PRESS &&
            g.tanks.ox_tank_pressure < MAX_ZERO_PRESS &&
            g.engine.thrust < MAX_ZERO_THRUST)
        {
            proceedFlag = true;
        }
        break;
    }
    case ENGINE_COMPUTER_STATE_ENGINE_CUTOFF:
    {
        g.status.state_proceed = ENGINE_COMPUTER_STATE_ENGINE_CUTOFF;
        g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_GENERIC;
        //close valves
        break;
    }
    //abort states
    case ENGINE_COMPUTER_STATE_ABORT_DURING_BURN:
    {
        g.status.state_proceed = ENGINE_COMPUTER_STATE_ABORT_GENERIC;   //leads into a generic abort after done
        g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_DURING_BURN; //can't abort from this - we need to finish solving the problem first
        //close all valves
        //don't proceed to regular abort until valves are closed
        if (g.engine.fuel_main_valve_position == 0 && g.engine.ox_main_valve_position == 0)
        {
            proceedFlag = true;
        }
        break;
    }
    //generic abort state. manual aborts and auto aborts not during critical states go here. all abort states lead here when they are done
    case ENGINE_COMPUTER_STATE_ABORT_GENERIC:
    {
        g.status.state_proceed = ENGINE_COMPUTER_STATE_ABORT_GENERIC; //can't proceed from an abort!
        g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_GENERIC;   //can't abort from an abort!
        handleAborts();
        break;
    }
    }
    stateJustChanged = false;
    //pick the next state
    setAbortFlags();
    //if any abort_flags are set, go to the correct state based on which state we're in now
    if (g.status.abort_flags)
    {
        g.status.state = g.status.state_abort;
        stateJustChanged = true;
    }
    //if no abort_flags are set, we can proceed if conditions are met
    else if (proceedFlag)
    {
        g.status.state = g.status.state_proceed; //change state
        proceedFlag = false;                     //reset the flag
        stateJustChanged = true;
    }
    //valves go to their auto positions whenever state changes
    if (stateJustChanged)
    {
        //for (int i = 0; i < 4; i++)
        //{
        g.valves[0]->releaseManualOverride();
        //}
    }

    //set valve auto positions as chosen by state
    //for (int i = 0; i < 4; i++)
    //{
    g.valves[0]->setAutoGoalPosition(valveAutoPositions[0]);
    //}
}