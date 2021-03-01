#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <rocketlink/mavlink.h>
#include <Valve.h>
#include <Pressure.h>
#include <Lights.h>
#include <FillLineSensors.h>
#include <Ignitor.h>
#include <Power.h>

class Globals
{
public:
    mavlink_engine_computer_status_t status = {};
    mavlink_engine_sensors_t engine = {};
    mavlink_tank_sensors_t tanks = {};

    Valve *valves[4];
    Pressure *pressures[4];
    Lights *lights;
    Ignitor *ignitor;
    FillLineSensors *fillLineSensors;
    Power *power;
};

extern Globals g;

#endif // __GLOBALS_H__