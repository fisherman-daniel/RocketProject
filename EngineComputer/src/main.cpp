#include <peripherals.h>
#include <pins.h>
#include <globals.h>
#include <rocketlink/mavlink.h>

#include <StateMachine.h>

#include <Valve.h>
#include <Pressure.h>
#include <Lights.h>
#include <Ignitor.h>
#include <FillLineSensors.h>

Globals g;

//function prototypes
void init_structs();
void fastLoop();
void slowLoop();
void uplink();
void downlink();

//fixes retarded bug from C++ compiler renaming functions when they translate to C
extern "C" void SysTick_Handler(void); //needed for all interrupts!! otherwise the routines don't get called!

//values are used in header of all MAVLink messages sent from here
mavlink_system_t mavlink_system = {
    SYS_ID_ROCKET,          //this system ID
    COMP_ID_ENGINE_COMPUTER //this component ID
};
//use only one channel since resources are tight
mavlink_channel_t mavlink_channel = MAVLINK_COMM_0;

mavlink_message_t msg;
mavlink_heartbeat_t hbb;
mavlink_status_t status;
uint8_t txBytes[MAVLINK_MAX_PACKET_LEN];
uint8_t rxByte;

uint32_t tFastLoopStart = 0;
uint32_t tSlowLoopStart = 0;

int main(void)
{
    init_hardware(); //call first so clock gets set up
    init_structs();

    //construct classes, which also does GPIO pin mode setup
    //the global things are REFERENCES to actual objects.we have to initialize to a temporary variable first before saving the address
    g.valves[0] = new Valve(TIM_CHANNEL_1, &htim2,
                            M1_DIR_Pin, M1_DIR_GPIO_Port,
                            M1_PWM_Pin, M1_PWM_GPIO_Port,
                            M1_ENCA_Pin, M1_ENCA_GPIO_Port,
                            M1_ENCB_Pin, M1_ENCB_GPIO_Port,
                            M1_SW_Pin, M1_SW_GPIO_Port);
    g.pressures[0] = new Pressure(&hadc, ADC_CHANNEL_0, P1_Pin, P1_GPIO_Port);
    g.lights = new Lights(RED_Pin, RED_GPIO_Port, GREEN_Pin, GREEN_GPIO_Port);
    g.ignitor = new Ignitor(IGN_Pin, IGN_GPIO_Port, IGN_SNS_Pin, IGN_SNS_GPIO_Port);
    g.fillLineSensors = new FillLineSensors(FL_SW_Pin, FL_SW_GPIO_Port, OX_SW_Pin, OX_SW_GPIO_Port);
    g.power = new Power(&hadc, ADC_CHANNEL_4, V_SNS_Pin, V_SNS_GPIO_Port, POWER_Pin, POWER_GPIO_Port);

    g.lights->startupblink();

    while (1)
    {
        if (HAL_GetTick() > tFastLoopStart + 1000)
        {
            tFastLoopStart = HAL_GetTick();
            fastLoop();
            mavlink_msg_engine_sensors_encode(SYS_ID_ROCKET, 0, &msg, &g.engine);
            downlink();
            mavlink_msg_tank_sensors_encode(SYS_ID_ROCKET, 0, &msg, &g.tanks);
            downlink();
        }
        if (HAL_GetTick() > tSlowLoopStart + 5000)
        {
            tSlowLoopStart = HAL_GetTick();
            slowLoop();
            mavlink_msg_heartbeat_encode(SYS_ID_ROCKET, 0, &msg, &hbb);
            downlink();
            mavlink_msg_engine_computer_status_encode(SYS_ID_ROCKET, 0, &msg, &g.status);
            downlink();
        }
        uplink();
    }
}

void uplink()
{
    //receive one byte at a time
    if (HAL_UART_Receive(&huart1, &rxByte, 1, 0) == HAL_OK)
    {
        //if this byte completes an uplink message
        if (mavlink_parse_char(mavlink_channel, rxByte, &msg, &status))
        {
            //handle the message
            switch (msg.msgid)
            {
            case MAVLINK_MSG_ID_HEARTBEAT:
            {
                gotHeartbeat();
                //^ tells the state machine that we got a heartbeat so we don't time out and abort
                break;
            }
            case MAVLINK_MSG_ID_PRE_CMD:
            {
                //todo
                break;
            }
            case MAVLINK_MSG_ID_CMD_SET_STATE:
            {
                mavlink_cmd_set_state_t data;
                mavlink_msg_cmd_set_state_decode(&msg, &data);
                if (data.cmd == STATE_CMD_ABORT)
                {
                    manualAbort();
                }
                else if (data.cmd == STATE_CMD_PROCEED)
                {
                    manualProceed();
                }
                else if (data.cmd == STATE_CMD_ABORT)
                {
                    forceGoto((ENGINE_COMPUTER_STATE)data.new_state);
                }
                break;
            }
            case MAVLINK_MSG_ID_CMD_SET_VALVE:
            {
                mavlink_cmd_set_valve_t data;
                mavlink_msg_cmd_set_valve_decode(&msg, &data);
                g.valves[data.valve]->command((VALVE_CMD)data.cmd, data.goal_position, data.pulse_duration);
                break;
            }
            case MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE:
            {
                mavlink_cmd_set_power_source_t data;
                mavlink_msg_cmd_set_power_source_decode(&msg, &data);
                g.status.power_source = data.power_source;
                break;
            }
            }
        }
    }
}
void downlink()
{
    uint16_t len = mavlink_msg_to_send_buffer(txBytes, &msg);
    HAL_UART_Transmit(&huart1, txBytes, len, 0); //might need to make timeout nonzero...
}

void fastLoop()
{
    stateMachine();
    g.pressures[0]->run();
    g.tanks.fuel_tank_pressure = g.pressures[0]->getPressure();
    g.valves[0]->run();
    g.engine.fuel_main_valve_position = g.valves[0]->getGoalPosition();
    g.engine.fuel_main_valve_status = g.valves[0]->status();
    g.engine.fuel_main_valve_goal_position = g.valves[0]->getGoalPosition();
    g.engine.fuel_main_valve_motor_power = g.valves[0]->getMotorPower();
    g.lights->run();
    // g.ignitor->run(); //one or more of these 3 make it hang for some reason
    // g.fillLineSensors->run();
    // g.power->run();
}

void slowLoop()
{
    mavlink_get_channel_buffer(mavlink_channel);
}

//if delay()s are hanging and tick() returns always the same value
//this function is not getting called by the interrupt.
//smh so much time wasted
void SysTick_Handler(void)
{
    HAL_IncTick();
}

void init_structs()
{
    g.status.state = ENGINE_COMPUTER_STATE_PREFLIGHT_CHECK;
    g.status.state_proceed = ENGINE_COMPUTER_STATE_FUEL_PRESS;
    g.status.state_abort = ENGINE_COMPUTER_STATE_ABORT_GENERIC;
    g.status.abort_flags = ABORT_FLAGS_NONE;
    g.status.cpu_load = 0;
    g.status.power_source = POWER_SOURCE_EXTERNAL; //start on external power
    g.status.voltage = 13000;                      //zero voltage to start

    g.engine.fuel_main_valve_status = 0;        //no flags set->auto control, we have no idea where valve is
    g.engine.fuel_main_valve_position = 255;    //position is totally unknown
    g.engine.fuel_main_valve_goal_position = 0; //start out by trying to close the valve to reset the encoder
    g.engine.fuel_main_valve_motor_power = 0;   //default no motor power
    g.engine.ox_main_valve_status = 0;
    g.engine.ox_main_valve_position = 255;
    g.engine.ox_main_valve_goal_position = 0;
    g.engine.ox_main_valve_motor_power = 0;
    g.engine.fuel_injector_pressure = 0; //start out with zero pressure reading, which is safe
    g.engine.ox_injector_pressure = 0;
    g.engine.thrust = 0;        //start out with no thrust reading
    g.engine.ignitor_flags = 0; //start out with no flags set: not firing, no continuity

    g.tanks.fuel_vent_valve_status = 0;
    g.tanks.fuel_vent_valve_position = 255;
    g.tanks.fuel_vent_valve_goal_position = 0;
    g.tanks.fuel_vent_valve_motor_power = 0;
    g.tanks.ox_vent_valve_status = 0;
    g.tanks.ox_vent_valve_position = 255;
    g.tanks.ox_vent_valve_goal_position = 0;
    g.tanks.ox_vent_valve_motor_power = 0;
    g.tanks.fuel_tank_pressure = 0;
    g.tanks.ox_tank_pressure = 0;
    g.tanks.fuel_tank_fill_level = 0; //tanks start empty
    g.tanks.ox_tank_fill_level = 0;
    g.tanks.fill_lines_detected = 0; //no flags: neither line connected
}
