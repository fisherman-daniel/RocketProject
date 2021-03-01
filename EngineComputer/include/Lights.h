#ifndef __LIGHTS_H__
#define __LIGHTS_H__

#include <stm32f0xx_hal.h>

class Lights
{
public:
    Lights(uint16_t _pinRed, GPIO_TypeDef *_portRed,
           uint16_t _pinGreen, GPIO_TypeDef *_portGreen);
    void run();
    void startupblink();

private:
    uint16_t pinRed, pinGreen, pinBlue;
    bool currR, currG, currB;
    GPIO_TypeDef *portRed, *portGreen, *portBlue;
};

#endif // __LIGHTS_H__