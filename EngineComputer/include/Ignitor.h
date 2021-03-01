#ifndef __IGNITOR_H__
#define __IGNITOR_H__

#include <stm32f0xx_hal.h>

class Ignitor
{
public:
    Ignitor(uint16_t _pinIgn, GPIO_TypeDef *_portIgn,
            uint16_t _pinCnt, GPIO_TypeDef *_portCnt);
    void run();

private:
    uint16_t pinIgn, pinCnt;
    GPIO_TypeDef *portIgn, *portCnt;
};

#endif // __IGNITOR_H__