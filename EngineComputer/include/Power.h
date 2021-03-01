#ifndef __POWER_H__
#define __POWER_H__

#include <stm32f0xx_hal.h>

class Power
{
public:
    Power(ADC_HandleTypeDef *_adc, uint32_t _channel,
          uint16_t _pinVlt, GPIO_TypeDef *_portVlt,
          uint16_t _pinSrc, GPIO_TypeDef *_portSrc);
    void run();

private:
    uint16_t pinSrc;
    GPIO_TypeDef *portSrc;
    ADC_HandleTypeDef *adc;
    uint32_t channel;
};

#endif // __POWER_H__