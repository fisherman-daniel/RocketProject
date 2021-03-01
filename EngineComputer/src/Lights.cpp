#include <Lights.h>
#include <globals.h>
#include <rocketlink/mavlink.h>

Lights::Lights(uint16_t _pinRed, GPIO_TypeDef *_portRed,
               uint16_t _pinGreen, GPIO_TypeDef *_portGreen)
{
    pinRed = _pinRed;
    pinGreen = _pinGreen;
    portRed = _portRed;
    portGreen = _portGreen;
    currR = currG = false;

    GPIO_InitTypeDef config = {};
    config.Mode = GPIO_MODE_OUTPUT_PP;
    config.Pin = pinRed;
    HAL_GPIO_Init(portRed, &config);
    config.Pin = pinGreen;
    HAL_GPIO_Init(portGreen, &config);
}

void Lights::startupblink()
{
    //red, green, then off
    HAL_GPIO_WritePin(portRed, pinRed, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(portRed, pinRed, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(portGreen, pinGreen, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(portGreen, pinGreen, GPIO_PIN_RESET);
}

void Lights::run()
{
    uint16_t R, G;
    R = G = 0;
    switch (::g.status.state)
    {
    case ENGINE_COMPUTER_STATE_PREFLIGHT_CHECK:
    {
        G = 0b1000000000000000;
        break;
    }
    case ENGINE_COMPUTER_STATE_FUEL_PRESS:
    {
        G = 0b1010000000000000;
        break;
    }
    case ENGINE_COMPUTER_STATE_OX_PRESS:
    {
        G = 0b1010100000000000;
        break;
    }
    case ENGINE_COMPUTER_STATE_IGNITION_AUTOSEQ:
    {
        R = 0b1100110011001100;
        G = 0b1111111111111111;
        break;
    }
    case ENGINE_COMPUTER_STATE_BURN_AUTOSEQ:
    {
        R = 0b1010101010101010;
        G = 0b1111111111111111;
        break;
    }
    case ENGINE_COMPUTER_STATE_ENGINE_CUTOFF:
    {
        R = 0b0011000000000000;
        G = 0b1111000000000000;
        break;
    }
    case ENGINE_COMPUTER_STATE_ABORT_DURING_BURN:
    {
        R = 0b1100110011001100;
        break;
    }
    case ENGINE_COMPUTER_STATE_ABORT_GENERIC:
    {
        R = 0b1111000011110000;
        break;
    }
    }
    //get new LED states based on which slot we're in.
    //the 16-bits of the flash pattern codes last over a 2-second period
    uint8_t timeSlot = (uint8_t)((HAL_GetTick() % 2000) * (16.0 / 2000));
    uint16_t mask = (1 << 15) >> timeSlot;
    bool newR = mask & R;
    bool newG = mask & G;
    //only write new values to output pins if states have changed
    if (newR != currR)
    {
        HAL_GPIO_WritePin(portRed, pinRed, (GPIO_PinState)newR);
        currR = newR;
    }
    if ((mask & G) != currG)
    {
        HAL_GPIO_WritePin(portGreen, pinGreen, (GPIO_PinState)newG);
        currG = newG;
    }
}