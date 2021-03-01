#ifndef __PRESSURE_H__
#define __PRESSURE_H__

#pragma once

#include <stm32f0xx_hal.h>
#include <rocketlink/mavlink.h>

class Pressure
{
public:
    Pressure(ADC_HandleTypeDef *_adc, uint32_t _channel, uint16_t _pin, GPIO_TypeDef *_port);
    uint16_t getPressure();
    void run();

private:
    ADC_HandleTypeDef *adc;
    uint32_t channel;
    uint16_t pressure;
};
#endif // __PRESSURE_H__