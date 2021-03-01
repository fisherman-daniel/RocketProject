#ifndef __VALVE_H__
#define __VALVE_H__

#include <stm32f0xx_hal.h>
#include <rocketlink/mavlink.h>

class Valve
{
public:
    Valve(uint32_t _timerChannelEnable, TIM_HandleTypeDef *_timerEnable,
          uint16_t _pinDir, GPIO_TypeDef *_portDir,
          uint16_t _pinPwm, GPIO_TypeDef *_portPwm,
          uint16_t _pinEncA, GPIO_TypeDef *_portEncA,
          uint16_t _pinEncB, GPIO_TypeDef *_portEncB,
          uint16_t _pinLimit, GPIO_TypeDef *_portLimit);
    VALVE_STATUS_FLAGS status();
    uint8_t getGoalPosition();
    uint8_t getPosition();
    uint8_t getMotorPower();
    void releaseManualOverride();
    void setAutoGoalPosition(uint8_t pos);
    void command(VALVE_CMD cmd, uint8_t pos, uint16_t duration);
    void run();

private:
    TIM_HandleTypeDef *timer;
    uint32_t channel;
    uint16_t pinDir, pinEncA, pinEncB, pinLimit;
    GPIO_TypeDef *portDir, *portEncA, *portEncB, *portLimit;
    bool manualOverrideFlag, encoderReliableFlag, pulseFlag;
    uint32_t timePulseStart;
    uint16_t pulseDuration;
    uint8_t manualGoalPosition, autoGoalPosition, currentPosition;
    uint16_t encoderPosition;
    int8_t motorPower;
};
#endif // __VALVE_H__