#include <Power.h>
#include <rocketlink/mavlink.h>
#include <globals.h>

Power::Power(ADC_HandleTypeDef *_adc, uint32_t _channel,
             uint16_t _pinVlt, GPIO_TypeDef *_portVlt,
             uint16_t _pinSrc, GPIO_TypeDef *_portSrc)
{
    pinSrc = _pinSrc;
    portSrc = _portSrc;
    adc = _adc;
    channel = _channel;

    //make VLT analog input
    GPIO_InitTypeDef configGpio = {};
    configGpio.Mode = GPIO_MODE_ANALOG;
    configGpio.Pin = _pinVlt;
    HAL_GPIO_Init(_portVlt, &configGpio);
    //make SRC digital output
    configGpio.Mode = GPIO_MODE_OUTPUT_PP;
    configGpio.Pin = _pinSrc;
    HAL_GPIO_Init(portSrc, &configGpio);
}

void Power::run()
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
    //convert it to real units and save in voltage
    g.status.voltage = raw;

    //set output based on power_status flag
    if (g.status.power_source == POWER_SOURCE_INTERNAL)
    {
        HAL_GPIO_WritePin(portSrc, pinSrc, GPIO_PIN_SET);
    }
    else if (g.status.power_source == POWER_SOURCE_EXTERNAL)
    {
        HAL_GPIO_WritePin(portSrc, pinSrc, GPIO_PIN_RESET);
    }
}