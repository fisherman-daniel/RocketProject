#include <Valve.h>
#include <config.h>

Valve::Valve(uint32_t _timerChannelEnable, TIM_HandleTypeDef *_timerEnable,
             uint16_t _pinDir, GPIO_TypeDef *_portDir,
             uint16_t _pinPwm, GPIO_TypeDef *_portPwm,
             uint16_t _pinEncA, GPIO_TypeDef *_portEncA,
             uint16_t _pinEncB, GPIO_TypeDef *_portEncB,
             uint16_t _pinLimit, GPIO_TypeDef *_portLimit)
{
    channel = _timerChannelEnable;
    timer = _timerEnable;
    pinDir = _pinDir;
    pinEncA = _pinEncA;
    pinEncB = _pinEncB;
    portDir = _portDir;
    portEncA = _portEncA;
    portEncB = _portEncB;
    pinLimit = _pinLimit;
    portLimit = _portLimit;

    encoderPosition = -1; //error value

    //make DIR an output
    GPIO_InitTypeDef configGPIO = {};
    configGPIO.Mode = GPIO_MODE_OUTPUT_PP;
    configGPIO.Pin = pinDir;
    HAL_GPIO_Init(portDir, &configGPIO);
    //make PWM a PWM output
    configGPIO.Mode = GPIO_MODE_AF_PP;
    configGPIO.Alternate = GPIO_AF2_TIM2;
    configGPIO.Pin = _pinPwm;
    HAL_GPIO_Init(_portPwm, &configGPIO);

    //make ENCA an interrupt pin
    configGPIO.Mode = GPIO_MODE_IT_RISING;
    configGPIO.Alternate = 0;
    configGPIO.Pin = pinEncA;
    HAL_GPIO_Init(portEncA, &configGPIO);
    //make ENCB, SW inputs
    configGPIO.Mode = GPIO_MODE_INPUT;
    configGPIO.Pin = pinEncB;
    HAL_GPIO_Init(portEncB, &configGPIO);
    configGPIO.Pin = pinLimit;
    HAL_GPIO_Init(portLimit, &configGPIO);
}

VALVE_STATUS_FLAGS Valve::status()
{
    uint8_t result = 0;
    if (manualOverrideFlag)
    {
        result |= VALVE_FLAGS_MANUAL_OVERRIDE;
    }
    if (encoderReliableFlag)
    {
        result |= VALVE_FLAGS_ENCODER_RELIABLE;
    }
    if (currentPosition == 0)
    {
        result |= VALVE_FLAGS_FULL_CLOSED;
    }
    if (currentPosition == 100)
    {
        result |= VALVE_FLAGS_FULL_OPEN;
    }
    return VALVE_STATUS_FLAGS(result);
}

uint8_t Valve::getGoalPosition()
{
    return manualOverrideFlag ? manualGoalPosition : autoGoalPosition;
}

uint8_t Valve::getPosition()
{
    return currentPosition;
}

uint8_t Valve::getMotorPower()
{
    return (motorPower >= 0) ? motorPower : -(motorPower);
}

void Valve::setAutoGoalPosition(uint8_t pos)
{
    autoGoalPosition = pos;
}

void Valve::releaseManualOverride()
{
    manualOverrideFlag = false;
}

void Valve::command(VALVE_CMD cmd, uint8_t pos, uint16_t duration)
{
    if (cmd == VALVE_CMD_END_MANUAL_OVERRIDE)
    {
        manualOverrideFlag = false;
    }
    else
    {
        manualOverrideFlag = true;
        if (cmd == VALVE_CMD_OPEN)
        {
            manualGoalPosition = 100;
        }
        else if (cmd == VALVE_CMD_CLOSE)
        {
            manualGoalPosition = 0;
        }
        else if (cmd == VALVE_CMD_SET_POSITION)
        {
            manualGoalPosition = pos;
        }
        else if (cmd == VALVE_CMD_PULSE)
        {
            pulseDuration = duration;
            pulseFlag = true;
            manualGoalPosition = pos;
            timePulseStart = HAL_GetTick();
        }
    }
}

void Valve::run()
{
    currentPosition = encoderPosition / 100;
    if (encoderReliableFlag)
    {
        if (pulseFlag && HAL_GetTick() > (timePulseStart + pulseDuration))
        {
            pulseFlag = false;
            manualGoalPosition = 0;
        }
        uint8_t error = currentPosition - getGoalPosition();
        motorPower = error * KP_VALVE;
    }
    else
    {
        if (HAL_GPIO_ReadPin(portLimit, pinLimit))
        {
            motorPower = 0;
            encoderPosition = 0;
            encoderReliableFlag = true;
        }
        else
        {
            motorPower = -100;
        }
    }
    //set direction pin
    uint8_t duty = 0;
    if (motorPower < 0)
    {
        duty = -motorPower;
        HAL_GPIO_WritePin(portDir, pinDir, GPIO_PIN_RESET);
    }
    else if (motorPower > 0)
    {
        duty = motorPower;
        HAL_GPIO_WritePin(portDir, pinDir, GPIO_PIN_SET);
    }
    //set pwm pin duty cycle
    HAL_TIM_PWM_Stop(timer, channel);
    TIM_OC_InitTypeDef config = {};
    config.OCMode = TIM_OCMODE_PWM1;
    config.Pulse = duty;
    HAL_TIM_PWM_ConfigChannel(timer, &config, channel);
    HAL_TIM_PWM_Start(timer, channel); // start pwm generation
}