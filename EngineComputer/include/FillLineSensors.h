#ifndef __FILLLINESENSORS_H__
#define __FILLLINESENSORS_H__

#include <stm32f0xx_hal.h>

class FillLineSensors
{
public:
    FillLineSensors(uint16_t _pinFuel, GPIO_TypeDef *_portFuel,
                    uint16_t _pinOx, GPIO_TypeDef *_portOx);
    void run();

private:
    uint16_t pinFuel, pinOx;
    GPIO_TypeDef *portFuel, *portOx;
};

#endif // __FILLLINESENSORS_H__