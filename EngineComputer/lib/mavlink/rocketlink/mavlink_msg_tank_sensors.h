#pragma once
// MESSAGE TANK_SENSORS PACKING

#define MAVLINK_MSG_ID_TANK_SENSORS 34


typedef struct __mavlink_tank_sensors_t {
 uint16_t fuel_tank_pressure; /*< [dbar] Pressure sensor reading at fuel injector*/
 uint16_t ox_tank_pressure; /*< [dbar] Pressure sensor reading at ox injector*/
 uint8_t fuel_vent_valve_status; /*<  current valve control mode*/
 uint8_t fuel_vent_valve_position; /*< [%open] Position valve is currently at. NaN if valve is not yet homed.*/
 uint8_t fuel_vent_valve_goal_position; /*< [%open] Position valve is supposed to be moving toward. NaN if position was never set*/
 uint8_t fuel_vent_valve_motor_power; /*<  Motor power level*/
 uint8_t ox_vent_valve_status; /*<  current valve control mode*/
 uint8_t ox_vent_valve_position; /*< [%open] Position valve is currently at. NaN if valve is not yet homed.*/
 uint8_t ox_vent_valve_goal_position; /*< [%open] Position valve is supposed to be moving toward. NaN if position was never set*/
 uint8_t ox_vent_valve_motor_power; /*<  Motor power level*/
 uint8_t fuel_tank_fill_level; /*< [%] Fuel tank fill level sensor. gives percentage of liquid in tank*/
 uint8_t ox_tank_fill_level; /*< [%] Ox tank fill level sensor*/
 uint8_t fill_lines_detected; /*<  */
} mavlink_tank_sensors_t;

#define MAVLINK_MSG_ID_TANK_SENSORS_LEN 15
#define MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN 15
#define MAVLINK_MSG_ID_34_LEN 15
#define MAVLINK_MSG_ID_34_MIN_LEN 15

#define MAVLINK_MSG_ID_TANK_SENSORS_CRC 120
#define MAVLINK_MSG_ID_34_CRC 120



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TANK_SENSORS { \
    34, \
    "TANK_SENSORS", \
    13, \
    {  { "fuel_vent_valve_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_status) }, \
         { "fuel_vent_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_position) }, \
         { "fuel_vent_valve_goal_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_goal_position) }, \
         { "fuel_vent_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_motor_power) }, \
         { "ox_vent_valve_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_tank_sensors_t, ox_vent_valve_status) }, \
         { "ox_vent_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_tank_sensors_t, ox_vent_valve_position) }, \
         { "ox_vent_valve_goal_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tank_sensors_t, ox_vent_valve_goal_position) }, \
         { "ox_vent_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tank_sensors_t, ox_vent_valve_motor_power) }, \
         { "fuel_tank_pressure", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_tank_sensors_t, fuel_tank_pressure) }, \
         { "ox_tank_pressure", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_tank_sensors_t, ox_tank_pressure) }, \
         { "fuel_tank_fill_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tank_sensors_t, fuel_tank_fill_level) }, \
         { "ox_tank_fill_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_tank_sensors_t, ox_tank_fill_level) }, \
         { "fill_lines_detected", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_tank_sensors_t, fill_lines_detected) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TANK_SENSORS { \
    "TANK_SENSORS", \
    13, \
    {  { "fuel_vent_valve_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_status) }, \
         { "fuel_vent_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_position) }, \
         { "fuel_vent_valve_goal_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_goal_position) }, \
         { "fuel_vent_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_tank_sensors_t, fuel_vent_valve_motor_power) }, \
         { "ox_vent_valve_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_tank_sensors_t, ox_vent_valve_status) }, \
         { "ox_vent_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_tank_sensors_t, ox_vent_valve_position) }, \
         { "ox_vent_valve_goal_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tank_sensors_t, ox_vent_valve_goal_position) }, \
         { "ox_vent_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tank_sensors_t, ox_vent_valve_motor_power) }, \
         { "fuel_tank_pressure", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_tank_sensors_t, fuel_tank_pressure) }, \
         { "ox_tank_pressure", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_tank_sensors_t, ox_tank_pressure) }, \
         { "fuel_tank_fill_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tank_sensors_t, fuel_tank_fill_level) }, \
         { "ox_tank_fill_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_tank_sensors_t, ox_tank_fill_level) }, \
         { "fill_lines_detected", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_tank_sensors_t, fill_lines_detected) }, \
         } \
}
#endif

/**
 * @brief Pack a tank_sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param fuel_vent_valve_status  current valve control mode
 * @param fuel_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param fuel_vent_valve_goal_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param fuel_vent_valve_motor_power  Motor power level
 * @param ox_vent_valve_status  current valve control mode
 * @param ox_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param ox_vent_valve_goal_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param ox_vent_valve_motor_power  Motor power level
 * @param fuel_tank_pressure [dbar] Pressure sensor reading at fuel injector
 * @param ox_tank_pressure [dbar] Pressure sensor reading at ox injector
 * @param fuel_tank_fill_level [%] Fuel tank fill level sensor. gives percentage of liquid in tank
 * @param ox_tank_fill_level [%] Ox tank fill level sensor
 * @param fill_lines_detected  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tank_sensors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t fuel_vent_valve_status, uint8_t fuel_vent_valve_position, uint8_t fuel_vent_valve_goal_position, uint8_t fuel_vent_valve_motor_power, uint8_t ox_vent_valve_status, uint8_t ox_vent_valve_position, uint8_t ox_vent_valve_goal_position, uint8_t ox_vent_valve_motor_power, uint16_t fuel_tank_pressure, uint16_t ox_tank_pressure, uint8_t fuel_tank_fill_level, uint8_t ox_tank_fill_level, uint8_t fill_lines_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TANK_SENSORS_LEN];
    _mav_put_uint16_t(buf, 0, fuel_tank_pressure);
    _mav_put_uint16_t(buf, 2, ox_tank_pressure);
    _mav_put_uint8_t(buf, 4, fuel_vent_valve_status);
    _mav_put_uint8_t(buf, 5, fuel_vent_valve_position);
    _mav_put_uint8_t(buf, 6, fuel_vent_valve_goal_position);
    _mav_put_uint8_t(buf, 7, fuel_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 8, ox_vent_valve_status);
    _mav_put_uint8_t(buf, 9, ox_vent_valve_position);
    _mav_put_uint8_t(buf, 10, ox_vent_valve_goal_position);
    _mav_put_uint8_t(buf, 11, ox_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 12, fuel_tank_fill_level);
    _mav_put_uint8_t(buf, 13, ox_tank_fill_level);
    _mav_put_uint8_t(buf, 14, fill_lines_detected);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TANK_SENSORS_LEN);
#else
    mavlink_tank_sensors_t packet;
    packet.fuel_tank_pressure = fuel_tank_pressure;
    packet.ox_tank_pressure = ox_tank_pressure;
    packet.fuel_vent_valve_status = fuel_vent_valve_status;
    packet.fuel_vent_valve_position = fuel_vent_valve_position;
    packet.fuel_vent_valve_goal_position = fuel_vent_valve_goal_position;
    packet.fuel_vent_valve_motor_power = fuel_vent_valve_motor_power;
    packet.ox_vent_valve_status = ox_vent_valve_status;
    packet.ox_vent_valve_position = ox_vent_valve_position;
    packet.ox_vent_valve_goal_position = ox_vent_valve_goal_position;
    packet.ox_vent_valve_motor_power = ox_vent_valve_motor_power;
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
 * @param fuel_vent_valve_status  current valve control mode
 * @param fuel_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param fuel_vent_valve_goal_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param fuel_vent_valve_motor_power  Motor power level
 * @param ox_vent_valve_status  current valve control mode
 * @param ox_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param ox_vent_valve_goal_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param ox_vent_valve_motor_power  Motor power level
 * @param fuel_tank_pressure [dbar] Pressure sensor reading at fuel injector
 * @param ox_tank_pressure [dbar] Pressure sensor reading at ox injector
 * @param fuel_tank_fill_level [%] Fuel tank fill level sensor. gives percentage of liquid in tank
 * @param ox_tank_fill_level [%] Ox tank fill level sensor
 * @param fill_lines_detected  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tank_sensors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t fuel_vent_valve_status,uint8_t fuel_vent_valve_position,uint8_t fuel_vent_valve_goal_position,uint8_t fuel_vent_valve_motor_power,uint8_t ox_vent_valve_status,uint8_t ox_vent_valve_position,uint8_t ox_vent_valve_goal_position,uint8_t ox_vent_valve_motor_power,uint16_t fuel_tank_pressure,uint16_t ox_tank_pressure,uint8_t fuel_tank_fill_level,uint8_t ox_tank_fill_level,uint8_t fill_lines_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TANK_SENSORS_LEN];
    _mav_put_uint16_t(buf, 0, fuel_tank_pressure);
    _mav_put_uint16_t(buf, 2, ox_tank_pressure);
    _mav_put_uint8_t(buf, 4, fuel_vent_valve_status);
    _mav_put_uint8_t(buf, 5, fuel_vent_valve_position);
    _mav_put_uint8_t(buf, 6, fuel_vent_valve_goal_position);
    _mav_put_uint8_t(buf, 7, fuel_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 8, ox_vent_valve_status);
    _mav_put_uint8_t(buf, 9, ox_vent_valve_position);
    _mav_put_uint8_t(buf, 10, ox_vent_valve_goal_position);
    _mav_put_uint8_t(buf, 11, ox_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 12, fuel_tank_fill_level);
    _mav_put_uint8_t(buf, 13, ox_tank_fill_level);
    _mav_put_uint8_t(buf, 14, fill_lines_detected);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TANK_SENSORS_LEN);
#else
    mavlink_tank_sensors_t packet;
    packet.fuel_tank_pressure = fuel_tank_pressure;
    packet.ox_tank_pressure = ox_tank_pressure;
    packet.fuel_vent_valve_status = fuel_vent_valve_status;
    packet.fuel_vent_valve_position = fuel_vent_valve_position;
    packet.fuel_vent_valve_goal_position = fuel_vent_valve_goal_position;
    packet.fuel_vent_valve_motor_power = fuel_vent_valve_motor_power;
    packet.ox_vent_valve_status = ox_vent_valve_status;
    packet.ox_vent_valve_position = ox_vent_valve_position;
    packet.ox_vent_valve_goal_position = ox_vent_valve_goal_position;
    packet.ox_vent_valve_motor_power = ox_vent_valve_motor_power;
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
    return mavlink_msg_tank_sensors_pack(system_id, component_id, msg, tank_sensors->fuel_vent_valve_status, tank_sensors->fuel_vent_valve_position, tank_sensors->fuel_vent_valve_goal_position, tank_sensors->fuel_vent_valve_motor_power, tank_sensors->ox_vent_valve_status, tank_sensors->ox_vent_valve_position, tank_sensors->ox_vent_valve_goal_position, tank_sensors->ox_vent_valve_motor_power, tank_sensors->fuel_tank_pressure, tank_sensors->ox_tank_pressure, tank_sensors->fuel_tank_fill_level, tank_sensors->ox_tank_fill_level, tank_sensors->fill_lines_detected);
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
    return mavlink_msg_tank_sensors_pack_chan(system_id, component_id, chan, msg, tank_sensors->fuel_vent_valve_status, tank_sensors->fuel_vent_valve_position, tank_sensors->fuel_vent_valve_goal_position, tank_sensors->fuel_vent_valve_motor_power, tank_sensors->ox_vent_valve_status, tank_sensors->ox_vent_valve_position, tank_sensors->ox_vent_valve_goal_position, tank_sensors->ox_vent_valve_motor_power, tank_sensors->fuel_tank_pressure, tank_sensors->ox_tank_pressure, tank_sensors->fuel_tank_fill_level, tank_sensors->ox_tank_fill_level, tank_sensors->fill_lines_detected);
}

/**
 * @brief Send a tank_sensors message
 * @param chan MAVLink channel to send the message
 *
 * @param fuel_vent_valve_status  current valve control mode
 * @param fuel_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param fuel_vent_valve_goal_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param fuel_vent_valve_motor_power  Motor power level
 * @param ox_vent_valve_status  current valve control mode
 * @param ox_vent_valve_position [%open] Position valve is currently at. NaN if valve is not yet homed.
 * @param ox_vent_valve_goal_position [%open] Position valve is supposed to be moving toward. NaN if position was never set
 * @param ox_vent_valve_motor_power  Motor power level
 * @param fuel_tank_pressure [dbar] Pressure sensor reading at fuel injector
 * @param ox_tank_pressure [dbar] Pressure sensor reading at ox injector
 * @param fuel_tank_fill_level [%] Fuel tank fill level sensor. gives percentage of liquid in tank
 * @param ox_tank_fill_level [%] Ox tank fill level sensor
 * @param fill_lines_detected  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tank_sensors_send(mavlink_channel_t chan, uint8_t fuel_vent_valve_status, uint8_t fuel_vent_valve_position, uint8_t fuel_vent_valve_goal_position, uint8_t fuel_vent_valve_motor_power, uint8_t ox_vent_valve_status, uint8_t ox_vent_valve_position, uint8_t ox_vent_valve_goal_position, uint8_t ox_vent_valve_motor_power, uint16_t fuel_tank_pressure, uint16_t ox_tank_pressure, uint8_t fuel_tank_fill_level, uint8_t ox_tank_fill_level, uint8_t fill_lines_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TANK_SENSORS_LEN];
    _mav_put_uint16_t(buf, 0, fuel_tank_pressure);
    _mav_put_uint16_t(buf, 2, ox_tank_pressure);
    _mav_put_uint8_t(buf, 4, fuel_vent_valve_status);
    _mav_put_uint8_t(buf, 5, fuel_vent_valve_position);
    _mav_put_uint8_t(buf, 6, fuel_vent_valve_goal_position);
    _mav_put_uint8_t(buf, 7, fuel_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 8, ox_vent_valve_status);
    _mav_put_uint8_t(buf, 9, ox_vent_valve_position);
    _mav_put_uint8_t(buf, 10, ox_vent_valve_goal_position);
    _mav_put_uint8_t(buf, 11, ox_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 12, fuel_tank_fill_level);
    _mav_put_uint8_t(buf, 13, ox_tank_fill_level);
    _mav_put_uint8_t(buf, 14, fill_lines_detected);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TANK_SENSORS, buf, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
#else
    mavlink_tank_sensors_t packet;
    packet.fuel_tank_pressure = fuel_tank_pressure;
    packet.ox_tank_pressure = ox_tank_pressure;
    packet.fuel_vent_valve_status = fuel_vent_valve_status;
    packet.fuel_vent_valve_position = fuel_vent_valve_position;
    packet.fuel_vent_valve_goal_position = fuel_vent_valve_goal_position;
    packet.fuel_vent_valve_motor_power = fuel_vent_valve_motor_power;
    packet.ox_vent_valve_status = ox_vent_valve_status;
    packet.ox_vent_valve_position = ox_vent_valve_position;
    packet.ox_vent_valve_goal_position = ox_vent_valve_goal_position;
    packet.ox_vent_valve_motor_power = ox_vent_valve_motor_power;
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
    mavlink_msg_tank_sensors_send(chan, tank_sensors->fuel_vent_valve_status, tank_sensors->fuel_vent_valve_position, tank_sensors->fuel_vent_valve_goal_position, tank_sensors->fuel_vent_valve_motor_power, tank_sensors->ox_vent_valve_status, tank_sensors->ox_vent_valve_position, tank_sensors->ox_vent_valve_goal_position, tank_sensors->ox_vent_valve_motor_power, tank_sensors->fuel_tank_pressure, tank_sensors->ox_tank_pressure, tank_sensors->fuel_tank_fill_level, tank_sensors->ox_tank_fill_level, tank_sensors->fill_lines_detected);
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
static inline void mavlink_msg_tank_sensors_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t fuel_vent_valve_status, uint8_t fuel_vent_valve_position, uint8_t fuel_vent_valve_goal_position, uint8_t fuel_vent_valve_motor_power, uint8_t ox_vent_valve_status, uint8_t ox_vent_valve_position, uint8_t ox_vent_valve_goal_position, uint8_t ox_vent_valve_motor_power, uint16_t fuel_tank_pressure, uint16_t ox_tank_pressure, uint8_t fuel_tank_fill_level, uint8_t ox_tank_fill_level, uint8_t fill_lines_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, fuel_tank_pressure);
    _mav_put_uint16_t(buf, 2, ox_tank_pressure);
    _mav_put_uint8_t(buf, 4, fuel_vent_valve_status);
    _mav_put_uint8_t(buf, 5, fuel_vent_valve_position);
    _mav_put_uint8_t(buf, 6, fuel_vent_valve_goal_position);
    _mav_put_uint8_t(buf, 7, fuel_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 8, ox_vent_valve_status);
    _mav_put_uint8_t(buf, 9, ox_vent_valve_position);
    _mav_put_uint8_t(buf, 10, ox_vent_valve_goal_position);
    _mav_put_uint8_t(buf, 11, ox_vent_valve_motor_power);
    _mav_put_uint8_t(buf, 12, fuel_tank_fill_level);
    _mav_put_uint8_t(buf, 13, ox_tank_fill_level);
    _mav_put_uint8_t(buf, 14, fill_lines_detected);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TANK_SENSORS, buf, MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN, MAVLINK_MSG_ID_TANK_SENSORS_LEN, MAVLINK_MSG_ID_TANK_SENSORS_CRC);
#else
    mavlink_tank_sensors_t *packet = (mavlink_tank_sensors_t *)msgbuf;
    packet->fuel_tank_pressure = fuel_tank_pressure;
    packet->ox_tank_pressure = ox_tank_pressure;
    packet->fuel_vent_valve_status = fuel_vent_valve_status;
    packet->fuel_vent_valve_position = fuel_vent_valve_position;
    packet->fuel_vent_valve_goal_position = fuel_vent_valve_goal_position;
    packet->fuel_vent_valve_motor_power = fuel_vent_valve_motor_power;
    packet->ox_vent_valve_status = ox_vent_valve_status;
    packet->ox_vent_valve_position = ox_vent_valve_position;
    packet->ox_vent_valve_goal_position = ox_vent_valve_goal_position;
    packet->ox_vent_valve_motor_power = ox_vent_valve_motor_power;
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
 * @brief Get field fuel_vent_valve_status from tank_sensors message
 *
 * @return  current valve control mode
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_vent_valve_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field fuel_vent_valve_position from tank_sensors message
 *
 * @return [%open] Position valve is currently at. NaN if valve is not yet homed.
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_vent_valve_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field fuel_vent_valve_goal_position from tank_sensors message
 *
 * @return [%open] Position valve is supposed to be moving toward. NaN if position was never set
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_vent_valve_goal_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field fuel_vent_valve_motor_power from tank_sensors message
 *
 * @return  Motor power level
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_vent_valve_motor_power(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field ox_vent_valve_status from tank_sensors message
 *
 * @return  current valve control mode
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_vent_valve_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field ox_vent_valve_position from tank_sensors message
 *
 * @return [%open] Position valve is currently at. NaN if valve is not yet homed.
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_vent_valve_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field ox_vent_valve_goal_position from tank_sensors message
 *
 * @return [%open] Position valve is supposed to be moving toward. NaN if position was never set
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_vent_valve_goal_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field ox_vent_valve_motor_power from tank_sensors message
 *
 * @return  Motor power level
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_vent_valve_motor_power(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field fuel_tank_pressure from tank_sensors message
 *
 * @return [dbar] Pressure sensor reading at fuel injector
 */
static inline uint16_t mavlink_msg_tank_sensors_get_fuel_tank_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field ox_tank_pressure from tank_sensors message
 *
 * @return [dbar] Pressure sensor reading at ox injector
 */
static inline uint16_t mavlink_msg_tank_sensors_get_ox_tank_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field fuel_tank_fill_level from tank_sensors message
 *
 * @return [%] Fuel tank fill level sensor. gives percentage of liquid in tank
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fuel_tank_fill_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field ox_tank_fill_level from tank_sensors message
 *
 * @return [%] Ox tank fill level sensor
 */
static inline uint8_t mavlink_msg_tank_sensors_get_ox_tank_fill_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field fill_lines_detected from tank_sensors message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_tank_sensors_get_fill_lines_detected(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
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
    tank_sensors->fuel_vent_valve_status = mavlink_msg_tank_sensors_get_fuel_vent_valve_status(msg);
    tank_sensors->fuel_vent_valve_position = mavlink_msg_tank_sensors_get_fuel_vent_valve_position(msg);
    tank_sensors->fuel_vent_valve_goal_position = mavlink_msg_tank_sensors_get_fuel_vent_valve_goal_position(msg);
    tank_sensors->fuel_vent_valve_motor_power = mavlink_msg_tank_sensors_get_fuel_vent_valve_motor_power(msg);
    tank_sensors->ox_vent_valve_status = mavlink_msg_tank_sensors_get_ox_vent_valve_status(msg);
    tank_sensors->ox_vent_valve_position = mavlink_msg_tank_sensors_get_ox_vent_valve_position(msg);
    tank_sensors->ox_vent_valve_goal_position = mavlink_msg_tank_sensors_get_ox_vent_valve_goal_position(msg);
    tank_sensors->ox_vent_valve_motor_power = mavlink_msg_tank_sensors_get_ox_vent_valve_motor_power(msg);
    tank_sensors->fuel_tank_fill_level = mavlink_msg_tank_sensors_get_fuel_tank_fill_level(msg);
    tank_sensors->ox_tank_fill_level = mavlink_msg_tank_sensors_get_ox_tank_fill_level(msg);
    tank_sensors->fill_lines_detected = mavlink_msg_tank_sensors_get_fill_lines_detected(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TANK_SENSORS_LEN? msg->len : MAVLINK_MSG_ID_TANK_SENSORS_LEN;
        memset(tank_sensors, 0, MAVLINK_MSG_ID_TANK_SENSORS_LEN);
    memcpy(tank_sensors, _MAV_PAYLOAD(msg), len);
#endif
}
