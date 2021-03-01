#ifndef __CONFIG_H__
#define __CONFIG_H__

//
//abort levels config
//
//pressure levels above these will cause an abort. units are dbar, = 0.1bar = 10kPa
const uint16_t FUEL_TANK_PRESSURE_ABORT_LEVEL = 700,
               OX_TANK_PRESSURE_ABORT_LEVEL = 700,
               FUEL_INJ_PRESSURE_ABORT_LEVEL = 300,
               OX_INJ_PRESSURE_ABORT_LEVEL = 300;
//units are ms
const uint16_t IGNITION_TIMEOUT_ABORT_LEVEL = 1000, LINK_TIMEOUT_ABORT_LEVEL = 10000; //ms
const uint16_t VOLTAGE_ABORT_LEVEL = 9000;                                            //mV
//
//PID config
//
const float KP_VALVE = -1;
//
//state config
//

const uint16_t MAX_ZERO_PRESS = 10;    //dbar
const uint16_t MAX_ZERO_THRUST = 10;   //cN
const uint16_t MIN_VOLTAGE_OK = 11000; //mV

const uint16_t MAX_SAFE_FUEL_PRESS = 1000,
               MIN_FUEL_PRESS_OK = 9990,
               MAX_SAFE_OX_PRESS = 1000,
               MIN_OX_PRESS_OK = 9990; //dbar

const uint16_t COUNTDOWN_TIME = 15000; //ms
const uint16_t IGNITION_TIME = 5000;   //ms before t0
const uint16_t ADD_OX_TIME = 4000;     //ms before t0
const uint16_t ADD_FUEL_TIME = 3000;   //ms before t0

const uint8_t FUEL_IGN_AMT = 10; //%
const uint8_t OX_IGN_AMT = 10;

#endif // __CONFIG_H__
