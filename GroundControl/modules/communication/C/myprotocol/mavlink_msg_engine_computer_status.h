#pragma once
// MESSAGE ENGINE_COMPUTER_STATUS PACKING

#define MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS 35


typedef struct __mavlink_engine_computer_status_t {
 uint16_t abort_flags; /*<  */
 uint8_t state; /*<  */
 uint8_t state_proceed; /*<  */
 uint8_t state_abort; /*<  */
 uint8_t arm_state; /*<  */
 uint8_t cpu_load; /*< [%] */
} mavlink_engine_computer_status_t;

#define MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN 7
#define MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN 7
#define MAVLINK_MSG_ID_35_LEN 7
#define MAVLINK_MSG_ID_35_MIN_LEN 7

#define MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC 165
#define MAVLINK_MSG_ID_35_CRC 165



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ENGINE_COMPUTER_STATUS { \
    35, \
    "ENGINE_COMPUTER_STATUS", \
    6, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_engine_computer_status_t, state) }, \
         { "state_proceed", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_engine_computer_status_t, state_proceed) }, \
         { "state_abort", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_engine_computer_status_t, state_abort) }, \
         { "abort_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_engine_computer_status_t, abort_flags) }, \
         { "arm_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_engine_computer_status_t, arm_state) }, \
         { "cpu_load", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_engine_computer_status_t, cpu_load) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ENGINE_COMPUTER_STATUS { \
    "ENGINE_COMPUTER_STATUS", \
    6, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_engine_computer_status_t, state) }, \
         { "state_proceed", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_engine_computer_status_t, state_proceed) }, \
         { "state_abort", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_engine_computer_status_t, state_abort) }, \
         { "abort_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_engine_computer_status_t, abort_flags) }, \
         { "arm_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_engine_computer_status_t, arm_state) }, \
         { "cpu_load", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_engine_computer_status_t, cpu_load) }, \
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
 * @param abort_flags  
 * @param arm_state  
 * @param cpu_load [%] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engine_computer_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t state, uint8_t state_proceed, uint8_t state_abort, uint16_t abort_flags, uint8_t arm_state, uint8_t cpu_load)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, abort_flags);
    _mav_put_uint8_t(buf, 2, state);
    _mav_put_uint8_t(buf, 3, state_proceed);
    _mav_put_uint8_t(buf, 4, state_abort);
    _mav_put_uint8_t(buf, 5, arm_state);
    _mav_put_uint8_t(buf, 6, cpu_load);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN);
#else
    mavlink_engine_computer_status_t packet;
    packet.abort_flags = abort_flags;
    packet.state = state;
    packet.state_proceed = state_proceed;
    packet.state_abort = state_abort;
    packet.arm_state = arm_state;
    packet.cpu_load = cpu_load;

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
 * @param abort_flags  
 * @param arm_state  
 * @param cpu_load [%] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engine_computer_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t state,uint8_t state_proceed,uint8_t state_abort,uint16_t abort_flags,uint8_t arm_state,uint8_t cpu_load)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, abort_flags);
    _mav_put_uint8_t(buf, 2, state);
    _mav_put_uint8_t(buf, 3, state_proceed);
    _mav_put_uint8_t(buf, 4, state_abort);
    _mav_put_uint8_t(buf, 5, arm_state);
    _mav_put_uint8_t(buf, 6, cpu_load);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN);
#else
    mavlink_engine_computer_status_t packet;
    packet.abort_flags = abort_flags;
    packet.state = state;
    packet.state_proceed = state_proceed;
    packet.state_abort = state_abort;
    packet.arm_state = arm_state;
    packet.cpu_load = cpu_load;

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
    return mavlink_msg_engine_computer_status_pack(system_id, component_id, msg, engine_computer_status->state, engine_computer_status->state_proceed, engine_computer_status->state_abort, engine_computer_status->abort_flags, engine_computer_status->arm_state, engine_computer_status->cpu_load);
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
    return mavlink_msg_engine_computer_status_pack_chan(system_id, component_id, chan, msg, engine_computer_status->state, engine_computer_status->state_proceed, engine_computer_status->state_abort, engine_computer_status->abort_flags, engine_computer_status->arm_state, engine_computer_status->cpu_load);
}

/**
 * @brief Send a engine_computer_status message
 * @param chan MAVLink channel to send the message
 *
 * @param state  
 * @param state_proceed  
 * @param state_abort  
 * @param abort_flags  
 * @param arm_state  
 * @param cpu_load [%] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_engine_computer_status_send(mavlink_channel_t chan, uint8_t state, uint8_t state_proceed, uint8_t state_abort, uint16_t abort_flags, uint8_t arm_state, uint8_t cpu_load)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, abort_flags);
    _mav_put_uint8_t(buf, 2, state);
    _mav_put_uint8_t(buf, 3, state_proceed);
    _mav_put_uint8_t(buf, 4, state_abort);
    _mav_put_uint8_t(buf, 5, arm_state);
    _mav_put_uint8_t(buf, 6, cpu_load);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS, buf, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
#else
    mavlink_engine_computer_status_t packet;
    packet.abort_flags = abort_flags;
    packet.state = state;
    packet.state_proceed = state_proceed;
    packet.state_abort = state_abort;
    packet.arm_state = arm_state;
    packet.cpu_load = cpu_load;

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
    mavlink_msg_engine_computer_status_send(chan, engine_computer_status->state, engine_computer_status->state_proceed, engine_computer_status->state_abort, engine_computer_status->abort_flags, engine_computer_status->arm_state, engine_computer_status->cpu_load);
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
static inline void mavlink_msg_engine_computer_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t state, uint8_t state_proceed, uint8_t state_abort, uint16_t abort_flags, uint8_t arm_state, uint8_t cpu_load)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, abort_flags);
    _mav_put_uint8_t(buf, 2, state);
    _mav_put_uint8_t(buf, 3, state_proceed);
    _mav_put_uint8_t(buf, 4, state_abort);
    _mav_put_uint8_t(buf, 5, arm_state);
    _mav_put_uint8_t(buf, 6, cpu_load);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS, buf, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_CRC);
#else
    mavlink_engine_computer_status_t *packet = (mavlink_engine_computer_status_t *)msgbuf;
    packet->abort_flags = abort_flags;
    packet->state = state;
    packet->state_proceed = state_proceed;
    packet->state_abort = state_abort;
    packet->arm_state = arm_state;
    packet->cpu_load = cpu_load;

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
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field state_proceed from engine_computer_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_state_proceed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field state_abort from engine_computer_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_state_abort(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field abort_flags from engine_computer_status message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_engine_computer_status_get_abort_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field arm_state from engine_computer_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_arm_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field cpu_load from engine_computer_status message
 *
 * @return [%] 
 */
static inline uint8_t mavlink_msg_engine_computer_status_get_cpu_load(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
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
    engine_computer_status->abort_flags = mavlink_msg_engine_computer_status_get_abort_flags(msg);
    engine_computer_status->state = mavlink_msg_engine_computer_status_get_state(msg);
    engine_computer_status->state_proceed = mavlink_msg_engine_computer_status_get_state_proceed(msg);
    engine_computer_status->state_abort = mavlink_msg_engine_computer_status_get_state_abort(msg);
    engine_computer_status->arm_state = mavlink_msg_engine_computer_status_get_arm_state(msg);
    engine_computer_status->cpu_load = mavlink_msg_engine_computer_status_get_cpu_load(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN? msg->len : MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN;
        memset(engine_computer_status, 0, MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_LEN);
    memcpy(engine_computer_status, _MAV_PAYLOAD(msg), len);
#endif
}
