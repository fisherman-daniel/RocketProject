#pragma once
// MESSAGE TANK_SENSORS PACKING

#define MAVLINK_MSG_ID_TANK_SENSORS 33


typedef struct __mavlink_tank_sensors_t {
 float fuel_tank_pressure; /*< [bar] Pressure sensor reading at fuel injector*/
 float ox_tank_pressure; /*< [bar] Pressure sensor reading at ox injector*/
 uint8_t fuel_vent_valve_mode; /*<  current valve control mode*/
 uint8_t fuel_vent_valve_position; /*< [%open] Position valve is currently at. NaN if valve is not yet homed.*/
 uint8_t fuel_vent_valve_desired_position; /*< [%open] Position valve is supposed to be moving toward. NaN if position was never set*/
 uint8_t fuel_vent_valve_motor_power; /*<  Motor power level*/
 uint8_t ox_vent_valve_mode; /*<  current valve control mode*/
 uint8_t ox_vent_valve_position; /*< [%open] Position valve is currently at. NaN if valve is not yet homed.*/
 uint8_t ox_vent_valve_desired_position; /*< [%open] Position valve is supposed to be moving toward. NaN if position was never set*/
 uint8_t ox_vent_valve_motor_power; /*<  Motor power level*/
 uint8_t fuel_tank_pressure_status; /*<  */
 uint8_t ox_tank_pressure_status; /*<  */
 uint8_t fuel_tank_fill_level; /*< [%] Fuel tank fill level sensor. gives percentage of liquid in tank*/
 uint8_t ox_tank_fill_level; /*< [%] Ox tank fill level sensor*/
 uint8_t fill_lines_detected; /*<  */
} mavlink_tank_sensors_t;

#define MAVLINK_MSG_ID_TANK_SENSORS_LEN 21
#define MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN 21
#define MAVLINK_MSG_ID_33_LEN 21
#define MAVLINK_MSG_ID_33_MIN_LEN 21

#define MAVLINK_MSG_ID_TANK_SENSORS_CRC 133
#define MAVLINK_MSG_ID_33_CRC 133



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TANK_SENSORS { \
    33, \
    "TANK_SENSORS", \
    15, \
    {  { "fuel_vent_valve_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_mode) }, \
         { "fuel_vent_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_position) }, \
         { "fuel_vent_valve_desired_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_desired_position) }, \
         { "fuel_vent_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_motor_power) }, \
         { "ox_vent_valve_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tank_sensors_t, ox_vent_valve_mode) }, \
         { "ox_vent_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_tank_sensors_t, ox_vent_valve_position) }, \
         { "ox_vent_valve_desired_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_tank_sensors_t, ox_vent_valve_desired_position) }, \
         { "ox_vent_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_tank_sensors_t, ox_vent_valve_motor_power) }, \
         { "fuel_tank_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tank_sensors_t, fuel_tank_pressure) }, \
         { "fuel_tank_pressure_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_tank_sensors_t, fuel_tank_pressure_status) }, \
         { "ox_tank_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tank_sensors_t, ox_tank_pressure) }, \
         { "ox_tank_pressure_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_tank_sensors_t, ox_tank_pressure_status) }, \
         { "fuel_tank_fill_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_tank_sensors_t, fuel_tank_fill_level) }, \
         { "ox_tank_fill_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_tank_sensors_t, ox_tank_fill_level) }, \
         { "fill_lines_detected", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_tank_sensors_t, fill_lines_detected) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TANK_SENSORS { \
    "TANK_SENSORS", \
    15, \
    {  { "fuel_vent_valve_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_mode) }, \
         { "fuel_vent_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_position) }, \
         { "fuel_vent_valve_desired_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_desired_position) }, \
         { "fuel_vent_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_motor_power) }, \
         { "ox_vent_valve_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tank_sensors_t, ox_vent_valve_mode) }, \
         { "ox_vent_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_tank_sensors_t, ox_vent_valve_position) }, \
         { "ox_vent_valve_desired_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_tank_sensors_t, ox_vent_valve_desired_position) }, \
         { "ox_vent_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_tank_sensors_t, ox_vent_valve_motor_power) }, \
         { "fuel_tank_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tank_sensors_t, fuel_tank_pressure) }, \
         { "fuel_tank_pressure_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_tank_sensors_t, fuel_tank_pressure_status) }, \
         { "ox_tank_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tank_sensors_t, ox_tank_pressure) }, \
         { "ox_tank_pressure_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_tank_sensors_t, ox_tank_pressure_status) }, \
         { "fuel_tank_fill_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_tank_sensors_t, fuel_tank_fill_level) }, \
         { "ox_tank_fill_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_tank_sensors_t, ox_tank_fill_level) }, \
         { "fill_lines_detected", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_tank_sensors_t, fill_lines_detected) }, \
         } \
}
#endif

/**
 * @brief Pack a tank_sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param fuel_vent_valve_mode  current valve control mode
 * @param fuel_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param fuel_vent_valve_desired_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param fuel_vent_valve_motor_power  Motor power level
 * @param ox_vent_valve_mode  current valve control mode
 * @param ox_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param ox_vent_valve_desired_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param ox_vent_valve_motor_power  Motor power level
 * @param fuel_tank_pressure [bar] Pressure sensor reading at fuel injector
 * @param fuel_tank_pressure_status  
 * @param ox_tank_pressure [bar] Pressure sensor reading at ox injector
 * @param ox_tank_pressure_status  
 * @param fuel_tank_fill_level [%] Fuel tank fill level sensor. gives percentage of liquid in tank
 * @param ox_tank_fill_level [%] Ox tank fill level sensor
 * @param fill_lines_detected  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tank_sensors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t fuel_vent_valve_mode, uint8_t fuel_vent_valve_position, uint8_t fuel_vent_valve_desired_position, uint8_t fuel_vent_valve_motor_power, uint8_t ox_vent_valve_mode, uint8_t ox_vent_valve_position, uint8_t ox_vent_valve_desired_position, uint8_t ox_vent_valve_motor_power, float fuel_tank_pressure, uint8_t fuel_tank_pressure_status, float ox_tank_pressure, uint8_t ox_tank_pressure_status, uint8_t fuel_tank_fill_level, uint8_t ox_tank_fill_level, uint8_t fill_lines_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TANK_SENSORS_LEN];
    _mav_put_float(buf, 0, fuel_tank_pressure);
    _mav_put_float(buf, 4, ox_tank_pressure);
    _mav_put_uint8_t(buf, 8, fuel_vent_valve_mode);
    _mav_put_uint8_t(buf, 9, fuel_vent_valve_position);
    _mav_put_uint8_t(buf, 10, fuel_vent_valve_desired_position);
    _mav_put_uint8_t(buf, 11, fuel_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 12, ox_vent_valve_mode);
    _mav_put_uint8_t(buf, 13, ox_vent_valve_position);
    _mav_put_uint8_t(buf, 14, ox_vent_valve_desired_position);
    _mav_put_uint8_t(buf, 15, ox_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 16, fuel_tank_pressure_status);
    _mav_put_uint8_t(buf, 17, ox_tank_pressure_status);
    _mav_put_uint8_t(buf, 18, fuel_tank_fill_level);
    _mav_put_uint8_t(buf, 19, ox_tank_fill_level);
    _mav_put_uint8_t(buf, 20, fill_lines_detected);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TANK_SENSORS_LEN);
#else
    mavlink_tank_sensors_t packet;
    packet.fuel_tank_pressure = fuel_tank_pressure;
    packet.ox_tank_pressure = ox_tank_pressure;
    packet.fuel_vent_valve_mode = fuel_vent_valve_mode;
    packet.fuel_vent_valve_position = fuel_vent_valve_position;
    packet.fuel_vent_valve_desired_position = fuel_vent_valve_desired_position;
    packet.fuel_vent_valve_motor_power = fuel_vent_valve_motor_power;
    packet.ox_vent_valve_mode = ox_vent_valve_mode;
    packet.ox_vent_valve_position = ox_vent_valve_position;
    packet.ox_vent_valve_desired_position = ox_vent_valve_desired_position;
    packet.ox_vent_valve_motor_power = ox_vent_valve_motor_power;
    packet.fuel_tank_pressure_status = fuel_tank_pressure_status;
    packet.ox_tank_pressure_status = ox_tank_pressure_status;
    packet.fuel_tank_fill_level = fuel_tank_fill_level;
    packet.ox_tank_fill_level = ox_tank_fill_level;
    packet.fill_lines_detected = fill_lines_detected;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TANK_SENSORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TANK_SENSORS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
}

/**
 * @brief Pack a tank_sensors message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fuel_vent_valve_mode  current valve control mode
 * @param fuel_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param fuel_vent_valve_desired_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param fuel_vent_valve_motor_power  Motor power level
 * @param ox_vent_valve_mode  current valve control mode
 * @param ox_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param ox_vent_valve_desired_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param ox_vent_valve_motor_power  Motor power level
 * @param fuel_tank_pressure [bar] Pressure sensor reading at fuel injector
 * @param fuel_tank_pressure_status  
 * @param ox_tank_pressure [bar] Pressure sensor reading at ox injector
 * @param ox_tank_pressure_status  
 * @param fuel_tank_fill_level [%] Fuel tank fill level sensor. gives percentage of liquid in tank
 * @param ox_tank_fill_level [%] Ox tank fill level sensor
 * @param fill_lines_detected  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tank_sensors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t fuel_vent_valve_mode,uint8_t fuel_vent_valve_position,uint8_t fuel_vent_valve_desired_position,uint8_t fuel_vent_valve_motor_power,uint8_t ox_vent_valve_mode,uint8_t ox_vent_valve_position,uint8_t ox_vent_valve_desired_position,uint8_t ox_vent_valve_motor_power,float fuel_tank_pressure,uint8_t fuel_tank_pressure_status,float ox_tank_pressure,uint8_t ox_tank_pressure_status,uint8_t fuel_tank_fill_level,uint8_t ox_tank_fill_level,uint8_t fill_lines_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TANK_SENSORS_LEN];
    _mav_put_float(buf, 0, fuel_tank_pressure);
    _mav_put_float(buf, 4, ox_tank_pressure);
    _mav_put_uint8_t(buf, 8, fuel_vent_valve_mode);
    _mav_put_uint8_t(buf, 9, fuel_vent_valve_position);
    _mav_put_uint8_t(buf, 10, fuel_vent_valve_desired_position);
    _mav_put_uint8_t(buf, 11, fuel_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 12, ox_vent_valve_mode);
    _mav_put_uint8_t(buf, 13, ox_vent_valve_position);
    _mav_put_uint8_t(buf, 14, ox_vent_valve_desired_position);
    _mav_put_uint8_t(buf, 15, ox_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 16, fuel_tank_pressure_status);
    _mav_put_uint8_t(buf, 17, ox_tank_pressure_status);
    _mav_put_uint8_t(buf, 18, fuel_tank_fill_level);
    _mav_put_uint8_t(buf, 19, ox_tank_fill_level);
    _mav_put_uint8_t(buf, 20, fill_lines_detected);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TANK_SENSORS_LEN);
#else
    mavlink_tank_sensors_t packet;
    packet.fuel_tank_pressure = fuel_tank_pressure;
    packet.ox_tank_pressure = ox_tank_pressure;
    packet.fuel_vent_valve_mode = fuel_vent_valve_mode;
    packet.fuel_vent_valve_position = fuel_vent_valve_position;
    packet.fuel_vent_valve_desired_position = fuel_vent_valve_desired_position;
    packet.fuel_vent_valve_motor_power = fuel_vent_valve_motor_power;
    packet.ox_vent_valve_mode = ox_vent_valve_mode;
    packet.ox_vent_valve_position = ox_vent_valve_position;
    packet.ox_vent_valve_desired_position = ox_vent_valve_desired_position;
    packet.ox_vent_valve_motor_power = ox_vent_valve_motor_power;
    packet.fuel_tank_pressure_status = fuel_tank_pressure_status;
    packet.ox_tank_pressure_status = ox_tank_pressure_status;
    packet.fuel_tank_fill_level = fuel_tank_fill_level;
    packet.ox_tank_fill_level = ox_tank_fill_level;
    packet.fill_lines_detected = fill_lines_detected;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TANK_SENSORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TANK_SENSORS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
}

/**
 * @brief Encode a tank_sensors struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tank_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tank_sensors_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tank_sensors_t* tank_sensors)
{
    return mavlink_msg_tank_sensors_pack(system_id, component_id, msg, tank_sensors->fuel_vent_valve_mode, tank_sensors->fuel_vent_valve_position, tank_sensors->fuel_vent_valve_desired_position, tank_sensors->fuel_vent_valve_motor_power, tank_sensors->ox_vent_valve_mode, tank_sensors->ox_vent_valve_position, tank_sensors->ox_vent_valve_desired_position, tank_sensors->ox_vent_valve_motor_power, tank_sensors->fuel_tank_pressure, tank_sensors->fuel_tank_pressure_status, tank_sensors->ox_tank_pressure, tank_sensors->ox_tank_pressure_status, tank_sensors->fuel_tank_fill_level, tank_sensors->ox_tank_fill_level, tank_sensors->fill_lines_detected);
}

/**
 * @brief Encode a tank_sensors struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tank_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tank_sensors_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tank_sensors_t* tank_sensors)
{
    return mavlink_msg_tank_sensors_pack_chan(system_id, component_id, chan, msg, tank_sensors->fuel_vent_valve_mode, tank_sensors->fuel_vent_valve_position, tank_sensors->fuel_vent_valve_desired_position, tank_sensors->fuel_vent_valve_motor_power, tank_sensors->ox_vent_valve_mode, tank_sensors->ox_vent_valve_position, tank_sensors->ox_vent_valve_desired_position, tank_sensors->ox_vent_valve_motor_power, tank_sensors->fuel_tank_pressure, tank_sensors->fuel_tank_pressure_status, tank_sensors->ox_tank_pressure, tank_sensors->ox_tank_pressure_status, tank_sensors->fuel_tank_fill_level, tank_sensors->ox_tank_fill_level, tank_sensors->fill_lines_detected);
}

/**
 * @brief Send a tank_sensors message
 * @param chan MAVLink channel to send the message
 *
 * @param fuel_vent_valve_mode  current valve control mode
 * @param fuel_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param fuel_vent_valve_desired_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param fuel_vent_valve_motor_power  Motor power level
 * @param ox_vent_valve_mode  current valve control mode
 * @param ox_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param ox_vent_valve_desired_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param ox_vent_valve_motor_power  Motor power level
 * @param fuel_tank_pressure [bar] Pressure sensor reading at fuel injector
 * @param fuel_tank_pressure_status  
 * @param ox_tank_pressure [bar] Pressure sensor reading at ox injector
 * @param ox_tank_pressure_status  
 * @param fuel_tank_fill_level [%] Fuel tank fill level sensor. gives percentage of liquid in tank
 * @param ox_tank_fill_level [%] Ox tank fill level sensor
 * @param fill_lines_detected  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tank_sensors_send(mavlink_channel_t chan, uint8_t fuel_vent_valve_mode, uint8_t fuel_vent_valve_position, uint8_t fuel_vent_valve_desired_position, uint8_t fuel_vent_valve_motor_power, uint8_t ox_vent_valve_mode, uint8_t ox_vent_valve_position, uint8_t ox_vent_valve_desired_position, uint8_t ox_vent_valve_motor_power, float fuel_tank_pressure, uint8_t fuel_tank_pressure_status, float ox_tank_pressure, uint8_t ox_tank_pressure_status, uint8_t fuel_tank_fill_level, uint8_t ox_tank_fill_level, uint8_t fill_lines_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TANK_SENSORS_LEN];
    _mav_put_float(buf, 0, fuel_tank_pressure);
    _mav_put_float(buf, 4, ox_tank_pressure);
    _mav_put_uint8_t(buf, 8, fuel_vent_valve_mode);
    _mav_put_uint8_t(buf, 9, fuel_vent_valve_position);
    _mav_put_uint8_t(buf, 10, fuel_vent_valve_desired_position);
    _mav_put_uint8_t(buf, 11, fuel_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 12, ox_vent_valve_mode);
    _mav_put_uint8_t(buf, 13, ox_vent_valve_position);
    _mav_put_uint8_t(buf, 14, ox_vent_valve_desired_position);
    _mav_put_uint8_t(buf, 15, ox_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 16, fuel_tank_pressure_status);
    _mav_put_uint8_t(buf, 17, ox_tank_pressure_status);
    _mav_put_uint8_t(buf, 18, fuel_tank_fill_level);
    _mav_put_uint8_t(buf, 19, ox_tank_fill_level);
    _mav_put_uint8_t(buf, 20, fill_lines_detected);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TANK_SENSORS, buf, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
#else
    mavlink_tank_sensors_t packet;
    packet.fuel_tank_pressure = fuel_tank_pressure;
    packet.ox_tank_pressure = ox_tank_pressure;
    packet.fuel_vent_valve_mode = fuel_vent_valve_mode;
    packet.fuel_vent_valve_position = fuel_vent_valve_position;
    packet.fuel_vent_valve_desired_position = fuel_vent_valve_desired_position;
    packet.fuel_vent_valve_motor_power = fuel_vent_valve_motor_power;
    packet.ox_vent_valve_mode = ox_vent_valve_mode;
    packet.ox_vent_valve_position = ox_vent_valve_position;
    packet.ox_vent_valve_desired_position = ox_vent_valve_desired_position;
    packet.ox_vent_valve_motor_power = ox_vent_valve_motor_power;
    packet.fuel_tank_pressure_status = fuel_tank_pressure_status;
    packet.ox_tank_pressure_status = ox_tank_pressure_status;
    packet.fuel_tank_fill_level = fuel_tank_fill_level;
    packet.ox_tank_fill_level = ox_tank_fill_level;
    packet.fill_lines_detected = fill_lines_detected;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TANK_SENSORS, (const char *)&packet, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
#endif
}

/**
 * @brief Send a tank_sensors message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tank_sensors_send_struct(mavlink_channel_t chan, const mavlink_tank_sensors_t* tank_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tank_sensors_send(chan, tank_sensors->fuel_vent_valve_mode, tank_sensors->fuel_vent_valve_position, tank_sensors->fuel_vent_valve_desired_position, tank_sensors->fuel_vent_valve_motor_power, tank_sensors->ox_vent_valve_mode, tank_sensors->ox_vent_valve_position, tank_sensors->ox_vent_valve_desired_position, tank_sensors->ox_vent_valve_motor_power, tank_sensors->fuel_tank_pressure, tank_sensors->fuel_tank_pressure_status, tank_sensors->ox_tank_pressure, tank_sensors->ox_tank_pressure_status, tank_sensors->fuel_tank_fill_level, tank_sensors->ox_tank_fill_level, tank_sensors->fill_lines_detected);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TANK_SENSORS, (const char *)tank_sensors, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
#endif
}

#if MAVLINK_MSG_ID_TANK_SENSORS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tank_sensors_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t fuel_vent_valve_mode, uint8_t fuel_vent_valve_position, uint8_t fuel_vent_valve_desired_position, uint8_t fuel_vent_valve_motor_power, uint8_t ox_vent_valve_mode, uint8_t ox_vent_valve_position, uint8_t ox_vent_valve_desired_position, uint8_t ox_vent_valve_motor_power, float fuel_tank_pressure, uint8_t fuel_tank_pressure_status, float ox_tank_pressure, uint8_t ox_tank_pressure_status, uint8_t fuel_tank_fill_level, uint8_t ox_tank_fill_level, uint8_t fill_lines_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, fuel_tank_pressure);
    _mav_put_float(buf, 4, ox_tank_pressure);
    _mav_put_uint8_t(buf, 8, fuel_vent_valve_mode);
    _mav_put_uint8_t(buf, 9, fuel_vent_valve_position);
    _mav_put_uint8_t(buf, 10, fuel_vent_valve_desired_position);
    _mav_put_uint8_t(buf, 11, fuel_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 12, ox_vent_valve_mode);
    _mav_put_uint8_t(buf, 13, ox_vent_valve_position);
    _mav_put_uint8_t(buf, 14, ox_vent_valve_desired_position);
    _mav_put_uint8_t(buf, 15, ox_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 16, fuel_tank_pressure_status);
    _mav_put_uint8_t(buf, 17, ox_tank_pressure_status);
    _mav_put_uint8_t(buf, 18, fuel_tank_fill_level);
    _mav_put_uint8_t(buf, 19, ox_tank_fill_level);
    _mav_put_uint8_t(buf, 20, fill_lines_detected);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TANK_SENSORS, buf, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
#else
    mavlink_tank_sensors_t *packet = (mavlink_tank_sensors_t *)msgbuf;
    packet->fuel_tank_pressure = fuel_tank_pressure;
    packet->ox_tank_pressure = ox_tank_pressure;
    packet->fuel_vent_valve_mode = fuel_vent_valve_mode;
    packet->fuel_vent_valve_position = fuel_vent_valve_position;
    packet->fuel_vent_valve_desired_position = fuel_vent_valve_desired_position;
    packet->fuel_vent_valve_motor_power = fuel_vent_valve_motor_power;
    packet->ox_vent_valve_mode = ox_vent_valve_mode;
    packet->ox_vent_valve_position = ox_vent_valve_position;
    packet->ox_vent_valve_desired_position = ox_vent_valve_desired_position;
    packet->ox_vent_valve_motor_power = ox_vent_valve_motor_power;
    packet->fuel_tank_pressure_status = fuel_tank_pressure_status;
    packet->ox_tank_pressure_status = ox_tank_pressure_status;
    packet->fuel_tank_fill_level = fuel_tank_fill_level;
    packet->ox_tank_fill_level = ox_tank_fill_level;
    packet->fill_lines_detected = fill_lines_detected;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TANK_SENSORS, (const char *)packet, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
#endif
}
#endif

#endif

// MESSAGE TANK_SENSORS UNPACKING


/**
 * @brief Get field fuel_vent_valve_mode from tank_sensors message
 *
 * @return  current valve control mode
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_vent_valve_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field fuel_vent_valve_position from tank_sensors message
 *
 * @return [%open] Position valve is currently at. NaN if valve is not yet homed.
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_vent_valve_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field fuel_vent_valve_desired_position from tank_sensors message
 *
 * @return [%open] Position valve is supposed to be moving toward. NaN if position was never set
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_vent_valve_desired_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field fuel_vent_valve_motor_power from tank_sensors message
 *
 * @return  Motor power level
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_vent_valve_motor_power(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field ox_vent_valve_mode from tank_sensors message
 *
 * @return  current valve control mode
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_vent_valve_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field ox_vent_valve_position from tank_sensors message
 *
 * @return [%open] Position valve is currently at. NaN if valve is not yet homed.
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_vent_valve_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field ox_vent_valve_desired_position from tank_sensors message
 *
 * @return [%open] Position valve is supposed to be moving toward. NaN if position was never set
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_vent_valve_desired_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field ox_vent_valve_motor_power from tank_sensors message
 *
 * @return  Motor power level
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_vent_valve_motor_power(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field fuel_tank_pressure from tank_sensors message
 *
 * @return [bar] Pressure sensor reading at fuel injector
 */
static inline float mavlink_msg_tank_sensors_get_fuel_tank_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field fuel_tank_pressure_status from tank_sensors message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_tank_pressure_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field ox_tank_pressure from tank_sensors message
 *
 * @return [bar] Pressure sensor reading at ox injector
 */
static inline float mavlink_msg_tank_sensors_get_ox_tank_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field ox_tank_pressure_status from tank_sensors message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_tank_pressure_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field fuel_tank_fill_level from tank_sensors message
 *
 * @return [%] Fuel tank fill level sensor. gives percentage of liquid in tank
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_tank_fill_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field ox_tank_fill_level from tank_sensors message
 *
 * @return [%] Ox tank fill level sensor
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_tank_fill_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field fill_lines_detected from tank_sensors message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fill_lines_detected(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Decode a tank_sensors message into a struct
 *
 * @param msg The message to decode
 * @param tank_sensors C-struct to decode the message contents into
 */
static inline void mavlink_msg_tank_sensors_decode(const mavlink_message_t* msg, mavlink_tank_sensors_t* tank_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tank_sensors->fuel_tank_pressure = mavlink_msg_tank_sensors_get_fuel_tank_pressure(msg);
    tank_sensors->ox_tank_pressure = mavlink_msg_tank_sensors_get_ox_tank_pressure(msg);
    tank_sensors->fuel_vent_valve_mode = mavlink_msg_tank_sensors_get_fuel_vent_valve_mode(msg);
    tank_sensors->fuel_vent_valve_position = mavlink_msg_tank_sensors_get_fuel_vent_valve_position(msg);
    tank_sensors->fuel_vent_valve_desired_position = mavlink_msg_tank_sensors_get_fuel_vent_valve_desired_position(msg);
    tank_sensors->fuel_vent_valve_motor_power = mavlink_msg_tank_sensors_get_fuel_vent_valve_motor_power(msg);
    tank_sensors->ox_vent_valve_mode = mavlink_msg_tank_sensors_get_ox_vent_valve_mode(msg);
    tank_sensors->ox_vent_valve_position = mavlink_msg_tank_sensors_get_ox_vent_valve_position(msg);
    tank_sensors->ox_vent_valve_desired_position = mavlink_msg_tank_sensors_get_ox_vent_valve_desired_position(msg);
    tank_sensors->ox_vent_valve_motor_power = mavlink_msg_tank_sensors_get_ox_vent_valve_motor_power(msg);
    tank_sensors->fuel_tank_pressure_status = mavlink_msg_tank_sensors_get_fuel_tank_pressure_status(msg);
    tank_sensors->ox_tank_pressure_status = mavlink_msg_tank_sensors_get_ox_tank_pressure_status(msg);
    tank_sensors->fuel_tank_fill_level = mavlink_msg_tank_sensors_get_fuel_tank_fill_level(msg);
    tank_sensors->ox_tank_fill_level = mavlink_msg_tank_sensors_get_ox_tank_fill_level(msg);
    tank_sensors->fill_lines_detected = mavlink_msg_tank_sensors_get_fill_lines_detected(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TANK_SENSORS_LEN? msg->len : MAVLINK_MSG_ID_TANK_SENSORS_LEN;
        memset(tank_sensors, 0, MAVLINK_MSG_ID_TANK_SENSORS_LEN);
    memcpy(tank_sensors, _MAV_PAYLOAD(msg), len);
#endif
}
