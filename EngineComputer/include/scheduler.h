#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stm32f0xx_hal.h>

class Scheduler
{
public:
    void scheduleTask(void (*func)(void), uint16_t interval, uint16_t max_time, bool repeat);
    void run();
};

#endif