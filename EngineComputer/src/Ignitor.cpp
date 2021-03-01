#include <Ignitor.h>
#include <globals.h>
#include <rocketlink/mavlink.h>

Ignitor::Ignitor(uint16_t _pinIgn, GPIO_TypeDef *_portIgn,
                 uint16_t _pinCnt, GPIO_TypeDef *_portCnt)
{
    pinIgn = _pinIgn;
    portIgn = _portIgn;
    pinCnt = _pinCnt;
    portCnt = _portCnt;

    //make IGN an output
    GPIO_InitTypeDef config = {};
    config.Mode = GPIO_MODE_OUTPUT_PP;
    config.Pin = pinIgn;
    HAL_GPIO_Init(portIgn, &config);
    //make CNT an input
    config.Mode = GPIO_MODE_INPUT;
    config.Pin = pinCnt;
    HAL_GPIO_Init(portCnt, &config);
}

void Ignitor::run()
{
    //set IGN output based on firing flag
    HAL_GPIO_WritePin(portIgn, pinIgn,
                      (GPIO_PinState)(g.engine.ignitor_flags & IGNITOR_FLAGS_FIRING));
    //set continuity flag based on CNT input
    //is there a better way to do the bit operation here, perhaps in one line?
    if (HAL_GPIO_ReadPin(portCnt, pinCnt))
    {
        g.engine.ignitor_flags |= IGNITOR_FLAGS_CONTINUITY;
    }
    else
    {
        g.engine.ignitor_flags &= ~IGNITOR_FLAGS_CONTINUITY;
    }
}