#include <FillLineSensors.h>
#include <rocketlink/mavlink.h>
#include <globals.h>

FillLineSensors::FillLineSensors(uint16_t _pinFuel, GPIO_TypeDef *_portFuel,
                                 uint16_t _pinOx, GPIO_TypeDef *_portOx)
{
    pinFuel = _pinFuel;
    portFuel = _portFuel;
    pinOx = _pinOx;
    portOx = _portOx;

    //make both inputs
    GPIO_InitTypeDef config = {};
    config.Mode = GPIO_MODE_INPUT;
    config.Pin = pinFuel;
    HAL_GPIO_Init(portFuel, &config);
    config.Pin = pinOx;
    HAL_GPIO_Init(portOx, &config);
}

void FillLineSensors::run()
{
    uint8_t newFlags = 0;
    //set fill line present flags in struct based on reading pins
    if (HAL_GPIO_ReadPin(portFuel, pinFuel))
    {
        newFlags |= TANK_FLAGS_FUEL;
    }
    if (HAL_GPIO_ReadPin(portOx, pinOx))
    {
        newFlags |= TANK_FLAGS_OX;
    }
    g.tanks.fill_lines_detected = newFlags;
}