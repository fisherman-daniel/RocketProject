#pragma once
// MESSAGE ENGINE_COMPUTER_STATUS PACKING

#define MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS 32


typedef struct __mavlink_engine_computer_status_t {
 int16_t time; /*<  mission time, in tenths of a second*/
 uint16_t voltage; /*< [mV] voltage on supply bus, whether that's internal battery or external power*/
 uint8_t state; /*<  */
 uint8_t state_proceed; /*<  */
 uint8_t state_abort; /*<  */
 uint8_t abort_flags; /*<  */
 uint8_t cpu_load; /*< [%] */
 uint8_t power_source; /*<  Battery or external supply*/
} mavlink_engine_computer_status_t;

#define MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN 10
#define MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN 10
#define MAVLINK_MSG_ID_32_LEN 10
#define MAVLINK_MSG_ID_32_MIN_LEN 10

#define MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC 195
#define MAVLINK_MSG_ID_32_CRC 195



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ENGINE_COMPUTER_STATUS { \
    32, \
    "ENGINE_COMPUTER_STATUS", \
    8, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_engine_computer_status_t, state) }, \
         { "state_proceed", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_engine_computer_status_t, state_proceed) }, \
         { "state_abort", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_engine_computer_status_t, state_abort) }, \
         { "time", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_engine_computer_status_t, time) }, \
         { "abort_flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_engine_computer_status_t, abort_flags) }, \
         { "cpu_load", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_engine_computer_status_t, cpu_load) }, \
         { "power_source", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_engine_computer_status_t, power_source) }, \
         { "voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_engine_computer_status_t, voltage) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ENGINE_COMPUTER_STATUS { \
    "ENGINE_COMPUTER_STATUS", \
    8, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_engine_computer_status_t, state) }, \
         { "state_proceed", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_engine_computer_status_t, state_proceed) }, \
         { "state_abort", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_engine_computer_status_t, state_abort) }, \
         { "time", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_engine_computer_status_t, time) }, \
         { "abort_flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_engine_computer_status_t, abort_flags) }, \
         { "cpu_load", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_engine_computer_status_t, cpu_load) }, \
         { "power_source", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_engine_computer_status_t, power_source) }, \
         { "voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_engine_computer_status_t, voltage) }, \
         } \
}
#endif

/**
 * @brief Pack a engine_computer_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param state  
 * @param state_proceed  
 * @param state_abort  
 * @param time  mission time, in tenths of a second
 * @param abort_flags  
 * @param cpu_load [%] 
 * @param power_source  Battery or external supply
 * @param voltage [mV] voltage on supply bus, whether that's internal battery or external power
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engine_computer_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t state, uint8_t state_proceed, uint8_t state_abort, int16_t time, uint8_t abort_flags, uint8_t cpu_load, uint8_t power_source, uint16_t voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN];
    _mav_put_int16_t(buf, 0, time);
    _mav_put_uint16_t(buf, 2, voltage);
    _mav_put_uint8_t(buf, 4, state);
    _mav_put_uint8_t(buf, 5, state_proceed);
    _mav_put_uint8_t(buf, 6, state_abort);
    _mav_put_uint8_t(buf, 7, abort_flags);
    _mav_put_uint8_t(buf, 8, cpu_load);
    _mav_put_uint8_t(buf, 9, power_source);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN);
#else
    mavlink_engine_computer_status_t packet;
    packet.time = time;
    packet.voltage = voltage;
    packet.state = state;
    packet.state_proceed = state_proceed;
    packet.state_abort = state_abort;
    packet.abort_flags = abort_flags;
    packet.cpu_load = cpu_load;
    packet.power_source = power_source;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
}

/**
 * @brief Pack a engine_computer_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state  
 * @param state_proceed  
 * @param state_abort  
 * @param time  mission time, in tenths of a second
 * @param abort_flags  
 * @param cpu_load [%] 
 * @param power_source  Battery or external supply
 * @param voltage [mV] voltage on supply bus, whether that's internal battery or external power
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engine_computer_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t state,uint8_t state_proceed,uint8_t state_abort,int16_t time,uint8_t abort_flags,uint8_t cpu_load,uint8_t power_source,uint16_t voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN];
    _mav_put_int16_t(buf, 0, time);
    _mav_put_uint16_t(buf, 2, voltage);
    _mav_put_uint8_t(buf, 4, state);
    _mav_put_uint8_t(buf, 5, state_proceed);
    _mav_put_uint8_t(buf, 6, state_abort);
    _mav_put_uint8_t(buf, 7, abort_flags);
    _mav_put_uint8_t(buf, 8, cpu_load);
    _mav_put_uint8_t(buf, 9, power_source);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN);
#else
    mavlink_engine_computer_status_t packet;
    packet.time = time;
    packet.voltage = voltage;
    packet.state = state;
    packet.state_proceed = state_proceed;
    packet.state_abort = state_abort;
    packet.abort_flags = abort_flags;
    packet.cpu_load = cpu_load;
    packet.power_source = power_source;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
}

/**
 * @brief Encode a engine_computer_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param engine_computer_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engine_computer_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_engine_computer_status_t* engine_computer_status)
{
    return mavlink_msg_engine_computer_status_pack(system_id, component_id, msg, engine_computer_status->state, engine_computer_status->state_proceed, engine_computer_status->state_abort, engine_computer_status->time, engine_computer_status->abort_flags, engine_computer_status->cpu_load, engine_computer_status->power_source, engine_computer_status->voltage);
}

/**
 * @brief Encode a engine_computer_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param engine_computer_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engine_computer_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_engine_computer_status_t* engine_computer_status)
{
    return mavlink_msg_engine_computer_status_pack_chan(system_id, component_id, chan, msg, engine_computer_status->state, engine_computer_status->state_proceed, engine_computer_status->state_abort, engine_computer_status->time, engine_computer_status->abort_flags, engine_computer_status->cpu_load, engine_computer_status->power_source, engine_computer_status->voltage);
}

/**
 * @brief Send a engine_computer_status message
 * @param chan MAVLink channel to send the message
 *
 * @param state  
 * @param state_proceed  
 * @param state_abort  
 * @param time  mission time, in tenths of a second
 * @param abort_flags  
 * @param cpu_load [%] 
 * @param power_source  Battery or external supply
 * @param voltage [mV] voltage on supply bus, whether that's internal battery or external power
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_engine_computer_status_send(mavlink_channel_t chan, uint8_t state, uint8_t state_proceed, uint8_t state_abort, int16_t time, uint8_t abort_flags, uint8_t cpu_load, uint8_t power_source, uint16_t voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN];
    _mav_put_int16_t(buf, 0, time);
    _mav_put_uint16_t(buf, 2, voltage);
    _mav_put_uint8_t(buf, 4, state);
    _mav_put_uint8_t(buf, 5, state_proceed);
    _mav_put_uint8_t(buf, 6, state_abort);
    _mav_put_uint8_t(buf, 7, abort_flags);
    _mav_put_uint8_t(buf, 8, cpu_load);
    _mav_put_uint8_t(buf, 9, power_source);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS, buf, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
#else
    mavlink_engine_computer_status_t packet;
    packet.time = time;
    packet.voltage = voltage;
    packet.state = state;
    packet.state_proceed = state_proceed;
    packet.state_abort = state_abort;
    packet.abort_flags = abort_flags;
    packet.cpu_load = cpu_load;
    packet.power_source = power_source;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS, (const char *)&packet, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
#endif
}

/**
 * @brief Send a engine_computer_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_engine_computer_status_send_struct(mavlink_channel_t chan, const mavlink_engine_computer_status_t* engine_computer_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_engine_computer_status_send(chan, engine_computer_status->state, engine_computer_status->state_proceed, engine_computer_status->state_abort, engine_computer_status->time, engine_computer_status->abort_flags, engine_computer_status->cpu_load, engine_computer_status->power_source, engine_computer_status->voltage);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS, (const char *)engine_computer_status, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_engine_computer_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t state, uint8_t state_proceed, uint8_t state_abort, int16_t time, uint8_t abort_flags, uint8_t cpu_load, uint8_t power_source, uint16_t voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, time);
    _mav_put_uint16_t(buf, 2, voltage);
    _mav_put_uint8_t(buf, 4, state);
    _mav_put_uint8_t(buf, 5, state_proceed);
    _mav_put_uint8_t(buf, 6, state_abort);
    _mav_put_uint8_t(buf, 7, abort_flags);
    _mav_put_uint8_t(buf, 8, cpu_load);
    _mav_put_uint8_t(buf, 9, power_source);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS, buf, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
#else
    mavlink_engine_computer_status_t *packet = (mavlink_engine_computer_status_t *)msgbuf;
    packet->time = time;
    packet->voltage = voltage;
    packet->state = state;
    packet->state_proceed = state_proceed;
    packet->state_abort = state_abort;
    packet->abort_flags = abort_flags;
    packet->cpu_load = cpu_load;
    packet->power_source = power_source;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS, (const char *)packet, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE ENGINE_COMPUTER_STATUS UNPACKING


/**
 * @brief Get field state from engine_computer_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field state_proceed from engine_computer_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_state_proceed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field state_abort from engine_computer_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_state_abort(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field time from engine_computer_status message
 *
 * @return  mission time, in tenths of a second
 */
static inline int16_t mavlink_msg_engine_computer_status_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field abort_flags from engine_computer_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_abort_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field cpu_load from engine_computer_status message
 *
 * @return [%] 
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_cpu_load(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field power_source from engine_computer_status message
 *
 * @return  Battery or external supply
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_power_source(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field voltage from engine_computer_status message
 *
 * @return [mV] voltage on supply bus, whether that's internal battery or external power
 */
static inline uint16_t mavlink_msg_engine_computer_status_get_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a engine_computer_status message into a struct
 *
 * @param msg The message to decode
 * @param engine_computer_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_engine_computer_status_decode(const mavlink_message_t* msg, mavlink_engine_computer_status_t* engine_computer_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    engine_computer_status->time = mavlink_msg_engine_computer_status_get_time(msg);
    engine_computer_status->voltage = mavlink_msg_engine_computer_status_get_voltage(msg);
    engine_computer_status->state = mavlink_msg_engine_computer_status_get_state(msg);
    engine_computer_status->state_proceed = mavlink_msg_engine_computer_status_get_state_proceed(msg);
    engine_computer_status->state_abort = mavlink_msg_engine_computer_status_get_state_abort(msg);
    engine_computer_status->abort_flags = mavlink_msg_engine_computer_status_get_abort_flags(msg);
    engine_computer_status->cpu_load = mavlink_msg_engine_computer_status_get_cpu_load(msg);
    engine_computer_status->power_source = mavlink_msg_engine_computer_status_get_power_source(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN? msg->len : MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN;
        memset(engine_computer_status, 0, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN);
    memcpy(engine_computer_status, _MAV_PAYLOAD(msg), len);
#endif
}
