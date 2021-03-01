#include <Pressure.h>
#include <stm32f0xx_hal.h>

Pressure::Pressure(ADC_HandleTypeDef *_adc, uint32_t _channel, uint16_t _pin, GPIO_TypeDef *_port)
{
    adc = _adc;
    channel = _channel;
    pressure = 0;

    GPIO_InitTypeDef configGpio = {};
    configGpio.Mode = GPIO_MODE_ANALOG;
    configGpio.Pin = _pin;
    HAL_GPIO_Init(_port, &configGpio);
}

uint16_t Pressure::getPressure()
{
    return pressure;
}

void Pressure::run()
{
    // add this channel to adc
    ADC_ChannelConfTypeDef configChannel;
    configChannel.Channel = channel;
    configChannel.Rank = ADC_RANK_CHANNEL_NUMBER;
    configChannel.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    HAL_ADC_ConfigChannel(adc, &configChannel);
    //do adc conversion
    HAL_ADC_Start(adc);
    HAL_ADC_PollForConversion(adc, HAL_MAX_DELAY);
    uint32_t raw = HAL_ADC_GetValue(adc);
    //remove this channel from adc
    configChannel.Rank = ADC_RANK_NONE;
    HAL_ADC_ConfigChannel(adc, &configChannel);
    //convert it to real units and save in variable
    pressure = (uint16_t)(raw * (100.0 / 2048));
}
