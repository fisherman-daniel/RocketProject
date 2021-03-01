#pragma once
// MESSAGE ENGINE_SENSORS PACKING

#define MAVLINK_MSG_ID_ENGINE_SENSORS 33


typedef struct __mavlink_engine_sensors_t {
 uint16_t fuel_injector_pressure; /*< [dbar] Pressure sensor reading at fuel injector*/
 uint16_t ox_injector_pressure; /*< [dbar] Pressure sensor reading at ox injector*/
 uint16_t thrust; /*< [cN] Load cell reading*/
 uint8_t fuel_main_valve_status; /*<  current valve control mode*/
 uint8_t fuel_main_valve_position; /*< [%] Position valve is currently at. 255 if valve is not yet homed.*/
 uint8_t fuel_main_valve_goal_position; /*< [%] Position valve is supposed to be moving toward. 255 if position was never set*/
 uint8_t fuel_main_valve_motor_power; /*<  Motor power level*/
 uint8_t ox_main_valve_status; /*<  */
 uint8_t ox_main_valve_position; /*< [%] */
 uint8_t ox_main_valve_goal_position; /*< [%] */
 uint8_t ox_main_valve_motor_power; /*<  Motor power level*/
 uint8_t ignitor_flags; /*<  Ignitor continuity and firing state*/
} mavlink_engine_sensors_t;

#define MAVLINK_MSG_ID_ENGINE_SENSORS_LEN 15
#define MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN 15
#define MAVLINK_MSG_ID_33_LEN 15
#define MAVLINK_MSG_ID_33_MIN_LEN 15

#define MAVLINK_MSG_ID_ENGINE_SENSORS_CRC 72
#define MAVLINK_MSG_ID_33_CRC 72



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ENGINE_SENSORS { \
    33, \
    "ENGINE_SENSORS", \
    12, \
    {  { "fuel_main_valve_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_engine_sensors_t, fuel_main_valve_status) }, \
         { "fuel_main_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_engine_sensors_t, fuel_main_valve_position) }, \
         { "fuel_main_valve_goal_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_engine_sensors_t, fuel_main_valve_goal_position) }, \
         { "fuel_main_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_engine_sensors_t, fuel_main_valve_motor_power) }, \
         { "ox_main_valve_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_engine_sensors_t, ox_main_valve_status) }, \
         { "ox_main_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_engine_sensors_t, ox_main_valve_position) }, \
         { "ox_main_valve_goal_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_engine_sensors_t, ox_main_valve_goal_position) }, \
         { "ox_main_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_engine_sensors_t, ox_main_valve_motor_power) }, \
         { "fuel_injector_pressure", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_engine_sensors_t, fuel_injector_pressure) }, \
         { "ox_injector_pressure", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_engine_sensors_t, ox_injector_pressure) }, \
         { "thrust", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_engine_sensors_t, thrust) }, \
         { "ignitor_flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_engine_sensors_t, ignitor_flags) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ENGINE_SENSORS { \
    "ENGINE_SENSORS", \
    12, \
    {  { "fuel_main_valve_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_engine_sensors_t, fuel_main_valve_status) }, \
         { "fuel_main_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_engine_sensors_t, fuel_main_valve_position) }, \
         { "fuel_main_valve_goal_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_engine_sensors_t, fuel_main_valve_goal_position) }, \
         { "fuel_main_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_engine_sensors_t, fuel_main_valve_motor_power) }, \
         { "ox_main_valve_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_engine_sensors_t, ox_main_valve_status) }, \
         { "ox_main_valve_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_engine_sensors_t, ox_main_valve_position) }, \
         { "ox_main_valve_goal_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_engine_sensors_t, ox_main_valve_goal_position) }, \
         { "ox_main_valve_motor_power", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_engine_sensors_t, ox_main_valve_motor_power) }, \
         { "fuel_injector_pressure", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_engine_sensors_t, fuel_injector_pressure) }, \
         { "ox_injector_pressure", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_engine_sensors_t, ox_injector_pressure) }, \
         { "thrust", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_engine_sensors_t, thrust) }, \
         { "ignitor_flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_engine_sensors_t, ignitor_flags) }, \
         } \
}
#endif

/**
 * @brief Pack a engine_sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param fuel_main_valve_status  current valve control mode
 * @param fuel_main_valve_position [%] Position valve is currently at. 255 if valve is not yet homed.
 * @param fuel_main_valve_goal_position [%] Position valve is supposed to be moving toward. 255 if position was never set
 * @param fuel_main_valve_motor_power  Motor power level
 * @param ox_main_valve_status  
 * @param ox_main_valve_position [%] 
 * @param ox_main_valve_goal_position [%] 
 * @param ox_main_valve_motor_power  Motor power level
 * @param fuel_injector_pressure [dbar] Pressure sensor reading at fuel injector
 * @param ox_injector_pressure [dbar] Pressure sensor reading at ox injector
 * @param thrust [cN] Load cell reading
 * @param ignitor_flags  Ignitor continuity and firing state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engine_sensors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t fuel_main_valve_status, uint8_t fuel_main_valve_position, uint8_t fuel_main_valve_goal_position, uint8_t fuel_main_valve_motor_power, uint8_t ox_main_valve_status, uint8_t ox_main_valve_position, uint8_t ox_main_valve_goal_position, uint8_t ox_main_valve_motor_power, uint16_t fuel_injector_pressure, uint16_t ox_injector_pressure, uint16_t thrust, uint8_t ignitor_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_SENSORS_LEN];
    _mav_put_uint16_t(buf, 0, fuel_injector_pressure);
    _mav_put_uint16_t(buf, 2, ox_injector_pressure);
    _mav_put_uint16_t(buf, 4, thrust);
    _mav_put_uint8_t(buf, 6, fuel_main_valve_status);
    _mav_put_uint8_t(buf, 7, fuel_main_valve_position);
    _mav_put_uint8_t(buf, 8, fuel_main_valve_goal_position);
    _mav_put_uint8_t(buf, 9, fuel_main_valve_motor_power);
    _mav_put_uint8_t(buf, 10, ox_main_valve_status);
    _mav_put_uint8_t(buf, 11, ox_main_valve_position);
    _mav_put_uint8_t(buf, 12, ox_main_valve_goal_position);
    _mav_put_uint8_t(buf, 13, ox_main_valve_motor_power);
    _mav_put_uint8_t(buf, 14, ignitor_flags);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN);
#else
    mavlink_engine_sensors_t packet;
    packet.fuel_injector_pressure = fuel_injector_pressure;
    packet.ox_injector_pressure = ox_injector_pressure;
    packet.thrust = thrust;
    packet.fuel_main_valve_status = fuel_main_valve_status;
    packet.fuel_main_valve_position = fuel_main_valve_position;
    packet.fuel_main_valve_goal_position = fuel_main_valve_goal_position;
    packet.fuel_main_valve_motor_power = fuel_main_valve_motor_power;
    packet.ox_main_valve_status = ox_main_valve_status;
    packet.ox_main_valve_position = ox_main_valve_position;
    packet.ox_main_valve_goal_position = ox_main_valve_goal_position;
    packet.ox_main_valve_motor_power = ox_main_valve_motor_power;
    packet.ignitor_flags = ignitor_flags;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGINE_SENSORS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_CRC);
}

/**
 * @brief Pack a engine_sensors message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fuel_main_valve_status  current valve control mode
 * @param fuel_main_valve_position [%] Position valve is currently at. 255 if valve is not yet homed.
 * @param fuel_main_valve_goal_position [%] Position valve is supposed to be moving toward. 255 if position was never set
 * @param fuel_main_valve_motor_power  Motor power level
 * @param ox_main_valve_status  
 * @param ox_main_valve_position [%] 
 * @param ox_main_valve_goal_position [%] 
 * @param ox_main_valve_motor_power  Motor power level
 * @param fuel_injector_pressure [dbar] Pressure sensor reading at fuel injector
 * @param ox_injector_pressure [dbar] Pressure sensor reading at ox injector
 * @param thrust [cN] Load cell reading
 * @param ignitor_flags  Ignitor continuity and firing state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engine_sensors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t fuel_main_valve_status,uint8_t fuel_main_valve_position,uint8_t fuel_main_valve_goal_position,uint8_t fuel_main_valve_motor_power,uint8_t ox_main_valve_status,uint8_t ox_main_valve_position,uint8_t ox_main_valve_goal_position,uint8_t ox_main_valve_motor_power,uint16_t fuel_injector_pressure,uint16_t ox_injector_pressure,uint16_t thrust,uint8_t ignitor_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_SENSORS_LEN];
    _mav_put_uint16_t(buf, 0, fuel_injector_pressure);
    _mav_put_uint16_t(buf, 2, ox_injector_pressure);
    _mav_put_uint16_t(buf, 4, thrust);
    _mav_put_uint8_t(buf, 6, fuel_main_valve_status);
    _mav_put_uint8_t(buf, 7, fuel_main_valve_position);
    _mav_put_uint8_t(buf, 8, fuel_main_valve_goal_position);
    _mav_put_uint8_t(buf, 9, fuel_main_valve_motor_power);
    _mav_put_uint8_t(buf, 10, ox_main_valve_status);
    _mav_put_uint8_t(buf, 11, ox_main_valve_position);
    _mav_put_uint8_t(buf, 12, ox_main_valve_goal_position);
    _mav_put_uint8_t(buf, 13, ox_main_valve_motor_power);
    _mav_put_uint8_t(buf, 14, ignitor_flags);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN);
#else
    mavlink_engine_sensors_t packet;
    packet.fuel_injector_pressure = fuel_injector_pressure;
    packet.ox_injector_pressure = ox_injector_pressure;
    packet.thrust = thrust;
    packet.fuel_main_valve_status = fuel_main_valve_status;
    packet.fuel_main_valve_position = fuel_main_valve_position;
    packet.fuel_main_valve_goal_position = fuel_main_valve_goal_position;
    packet.fuel_main_valve_motor_power = fuel_main_valve_motor_power;
    packet.ox_main_valve_status = ox_main_valve_status;
    packet.ox_main_valve_position = ox_main_valve_position;
    packet.ox_main_valve_goal_position = ox_main_valve_goal_position;
    packet.ox_main_valve_motor_power = ox_main_valve_motor_power;
    packet.ignitor_flags = ignitor_flags;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGINE_SENSORS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_CRC);
}

/**
 * @brief Encode a engine_sensors struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param engine_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engine_sensors_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_engine_sensors_t* engine_sensors)
{
    return mavlink_msg_engine_sensors_pack(system_id, component_id, msg, engine_sensors->fuel_main_valve_status, engine_sensors->fuel_main_valve_position, engine_sensors->fuel_main_valve_goal_position, engine_sensors->fuel_main_valve_motor_power, engine_sensors->ox_main_valve_status, engine_sensors->ox_main_valve_position, engine_sensors->ox_main_valve_goal_position, engine_sensors->ox_main_valve_motor_power, engine_sensors->fuel_injector_pressure, engine_sensors->ox_injector_pressure, engine_sensors->thrust, engine_sensors->ignitor_flags);
}

/**
 * @brief Encode a engine_sensors struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param engine_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engine_sensors_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_engine_sensors_t* engine_sensors)
{
    return mavlink_msg_engine_sensors_pack_chan(system_id, component_id, chan, msg, engine_sensors->fuel_main_valve_status, engine_sensors->fuel_main_valve_position, engine_sensors->fuel_main_valve_goal_position, engine_sensors->fuel_main_valve_motor_power, engine_sensors->ox_main_valve_status, engine_sensors->ox_main_valve_position, engine_sensors->ox_main_valve_goal_position, engine_sensors->ox_main_valve_motor_power, engine_sensors->fuel_injector_pressure, engine_sensors->ox_injector_pressure, engine_sensors->thrust, engine_sensors->ignitor_flags);
}

/**
 * @brief Send a engine_sensors message
 * @param chan MAVLink channel to send the message
 *
 * @param fuel_main_valve_status  current valve control mode
 * @param fuel_main_valve_position [%] Position valve is currently at. 255 if valve is not yet homed.
 * @param fuel_main_valve_goal_position [%] Position valve is supposed to be moving toward. 255 if position was never set
 * @param fuel_main_valve_motor_power  Motor power level
 * @param ox_main_valve_status  
 * @param ox_main_valve_position [%] 
 * @param ox_main_valve_goal_position [%] 
 * @param ox_main_valve_motor_power  Motor power level
 * @param fuel_injector_pressure [dbar] Pressure sensor reading at fuel injector
 * @param ox_injector_pressure [dbar] Pressure sensor reading at ox injector
 * @param thrust [cN] Load cell reading
 * @param ignitor_flags  Ignitor continuity and firing state
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_engine_sensors_send(mavlink_channel_t chan, uint8_t fuel_main_valve_status, uint8_t fuel_main_valve_position, uint8_t fuel_main_valve_goal_position, uint8_t fuel_main_valve_motor_power, uint8_t ox_main_valve_status, uint8_t ox_main_valve_position, uint8_t ox_main_valve_goal_position, uint8_t ox_main_valve_motor_power, uint16_t fuel_injector_pressure, uint16_t ox_injector_pressure, uint16_t thrust, uint8_t ignitor_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_SENSORS_LEN];
    _mav_put_uint16_t(buf, 0, fuel_injector_pressure);
    _mav_put_uint16_t(buf, 2, ox_injector_pressure);
    _mav_put_uint16_t(buf, 4, thrust);
    _mav_put_uint8_t(buf, 6, fuel_main_valve_status);
    _mav_put_uint8_t(buf, 7, fuel_main_valve_position);
    _mav_put_uint8_t(buf, 8, fuel_main_valve_goal_position);
    _mav_put_uint8_t(buf, 9, fuel_main_valve_motor_power);
    _mav_put_uint8_t(buf, 10, ox_main_valve_status);
    _mav_put_uint8_t(buf, 11, ox_main_valve_position);
    _mav_put_uint8_t(buf, 12, ox_main_valve_goal_position);
    _mav_put_uint8_t(buf, 13, ox_main_valve_motor_power);
    _mav_put_uint8_t(buf, 14, ignitor_flags);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_SENSORS, buf, MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_CRC);
#else
    mavlink_engine_sensors_t packet;
    packet.fuel_injector_pressure = fuel_injector_pressure;
    packet.ox_injector_pressure = ox_injector_pressure;
    packet.thrust = thrust;
    packet.fuel_main_valve_status = fuel_main_valve_status;
    packet.fuel_main_valve_position = fuel_main_valve_position;
    packet.fuel_main_valve_goal_position = fuel_main_valve_goal_position;
    packet.fuel_main_valve_motor_power = fuel_main_valve_motor_power;
    packet.ox_main_valve_status = ox_main_valve_status;
    packet.ox_main_valve_position = ox_main_valve_position;
    packet.ox_main_valve_goal_position = ox_main_valve_goal_position;
    packet.ox_main_valve_motor_power = ox_main_valve_motor_power;
    packet.ignitor_flags = ignitor_flags;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_SENSORS, (const char *)&packet, MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_CRC);
#endif
}

/**
 * @brief Send a engine_sensors message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_engine_sensors_send_struct(mavlink_channel_t chan, const mavlink_engine_sensors_t* engine_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_engine_sensors_send(chan, engine_sensors->fuel_main_valve_status, engine_sensors->fuel_main_valve_position, engine_sensors->fuel_main_valve_goal_position, engine_sensors->fuel_main_valve_motor_power, engine_sensors->ox_main_valve_status, engine_sensors->ox_main_valve_position, engine_sensors->ox_main_valve_goal_position, engine_sensors->ox_main_valve_motor_power, engine_sensors->fuel_injector_pressure, engine_sensors->ox_injector_pressure, engine_sensors->thrust, engine_sensors->ignitor_flags);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_SENSORS, (const char *)engine_sensors, MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ENGINE_SENSORS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_engine_sensors_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t fuel_main_valve_status, uint8_t fuel_main_valve_position, uint8_t fuel_main_valve_goal_position, uint8_t fuel_main_valve_motor_power, uint8_t ox_main_valve_status, uint8_t ox_main_valve_position, uint8_t ox_main_valve_goal_position, uint8_t ox_main_valve_motor_power, uint16_t fuel_injector_pressure, uint16_t ox_injector_pressure, uint16_t thrust, uint8_t ignitor_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, fuel_injector_pressure);
    _mav_put_uint16_t(buf, 2, ox_injector_pressure);
    _mav_put_uint16_t(buf, 4, thrust);
    _mav_put_uint8_t(buf, 6, fuel_main_valve_status);
    _mav_put_uint8_t(buf, 7, fuel_main_valve_position);
    _mav_put_uint8_t(buf, 8, fuel_main_valve_goal_position);
    _mav_put_uint8_t(buf, 9, fuel_main_valve_motor_power);
    _mav_put_uint8_t(buf, 10, ox_main_valve_status);
    _mav_put_uint8_t(buf, 11, ox_main_valve_position);
    _mav_put_uint8_t(buf, 12, ox_main_valve_goal_position);
    _mav_put_uint8_t(buf, 13, ox_main_valve_motor_power);
    _mav_put_uint8_t(buf, 14, ignitor_flags);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_SENSORS, buf, MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_CRC);
#else
    mavlink_engine_sensors_t *packet = (mavlink_engine_sensors_t *)msgbuf;
    packet->fuel_injector_pressure = fuel_injector_pressure;
    packet->ox_injector_pressure = ox_injector_pressure;
    packet->thrust = thrust;
    packet->fuel_main_valve_status = fuel_main_valve_status;
    packet->fuel_main_valve_position = fuel_main_valve_position;
    packet->fuel_main_valve_goal_position = fuel_main_valve_goal_position;
    packet->fuel_main_valve_motor_power = fuel_main_valve_motor_power;
    packet->ox_main_valve_status = ox_main_valve_status;
    packet->ox_main_valve_position = ox_main_valve_position;
    packet->ox_main_valve_goal_position = ox_main_valve_goal_position;
    packet->ox_main_valve_motor_power = ox_main_valve_motor_power;
    packet->ignitor_flags = ignitor_flags;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_SENSORS, (const char *)packet, MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN, MAVLINK_MSG_ID_ENGINE_SENSORS_CRC);
#endif
}
#endif

#endif

// MESSAGE ENGINE_SENSORS UNPACKING


/**
 * @brief Get field fuel_main_valve_status from engine_sensors message
 *
 * @return  current valve control mode
 */
static inline uint8_t mavlink_msg_engine_sensors_get_fuel_main_valve_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field fuel_main_valve_position from engine_sensors message
 *
 * @return [%] Position valve is currently at. 255 if valve is not yet homed.
 */
static inline uint8_t mavlink_msg_engine_sensors_get_fuel_main_valve_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field fuel_main_valve_goal_position from engine_sensors message
 *
 * @return [%] Position valve is supposed to be moving toward. 255 if position was never set
 */
static inline uint8_t mavlink_msg_engine_sensors_get_fuel_main_valve_goal_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field fuel_main_valve_motor_power from engine_sensors message
 *
 * @return  Motor power level
 */
static inline uint8_t mavlink_msg_engine_sensors_get_fuel_main_valve_motor_power(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field ox_main_valve_status from engine_sensors message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_engine_sensors_get_ox_main_valve_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field ox_main_valve_position from engine_sensors message
 *
 * @return [%] 
 */
static inline uint8_t mavlink_msg_engine_sensors_get_ox_main_valve_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field ox_main_valve_goal_position from engine_sensors message
 *
 * @return [%] 
 */
static inline uint8_t mavlink_msg_engine_sensors_get_ox_main_valve_goal_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field ox_main_valve_motor_power from engine_sensors message
 *
 * @return  Motor power level
 */
static inline uint8_t mavlink_msg_engine_sensors_get_ox_main_valve_motor_power(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field fuel_injector_pressure from engine_sensors message
 *
 * @return [dbar] Pressure sensor reading at fuel injector
 */
static inline uint16_t mavlink_msg_engine_sensors_get_fuel_injector_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field ox_injector_pressure from engine_sensors message
 *
 * @return [dbar] Pressure sensor reading at ox injector
 */
static inline uint16_t mavlink_msg_engine_sensors_get_ox_injector_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field thrust from engine_sensors message
 *
 * @return [cN] Load cell reading
 */
static inline uint16_t mavlink_msg_engine_sensors_get_thrust(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field ignitor_flags from engine_sensors message
 *
 * @return  Ignitor continuity and firing state
 */
static inline uint8_t mavlink_msg_engine_sensors_get_ignitor_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Decode a engine_sensors message into a struct
 *
 * @param msg The message to decode
 * @param engine_sensors C-struct to decode the message contents into
 */
static inline void mavlink_msg_engine_sensors_decode(const mavlink_message_t* msg, mavlink_engine_sensors_t* engine_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    engine_sensors->fuel_injector_pressure = mavlink_msg_engine_sensors_get_fuel_injector_pressure(msg);
    engine_sensors->ox_injector_pressure = mavlink_msg_engine_sensors_get_ox_injector_pressure(msg);
    engine_sensors->thrust = mavlink_msg_engine_sensors_get_thrust(msg);
    engine_sensors->fuel_main_valve_status = mavlink_msg_engine_sensors_get_fuel_main_valve_status(msg);
    engine_sensors->fuel_main_valve_position = mavlink_msg_engine_sensors_get_fuel_main_valve_position(msg);
    engine_sensors->fuel_main_valve_goal_position = mavlink_msg_engine_sensors_get_fuel_main_valve_goal_position(msg);
    engine_sensors->fuel_main_valve_motor_power = mavlink_msg_engine_sensors_get_fuel_main_valve_motor_power(msg);
    engine_sensors->ox_main_valve_status = mavlink_msg_engine_sensors_get_ox_main_valve_status(msg);
    engine_sensors->ox_main_valve_position = mavlink_msg_engine_sensors_get_ox_main_valve_position(msg);
    engine_sensors->ox_main_valve_goal_position = mavlink_msg_engine_sensors_get_ox_main_valve_goal_position(msg);
    engine_sensors->ox_main_valve_motor_power = mavlink_msg_engine_sensors_get_ox_main_valve_motor_power(msg);
    engine_sensors->ignitor_flags = mavlink_msg_engine_sensors_get_ignitor_flags(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ENGINE_SENSORS_LEN? msg->len : MAVLINK_MSG_ID_ENGINE_SENSORS_LEN;
        memset(engine_sensors, 0, MAVLINK_MSG_ID_ENGINE_SENSORS_LEN);
    memcpy(engine_sensors, _MAV_PAYLOAD(msg), len);
#endif
}
