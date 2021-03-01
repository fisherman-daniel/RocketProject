#pragma once
// MESSAGE CMD_SET_MESSAGE_INTERVAL PACKING

#define MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL 4


typedef struct __mavlink_cmd_set_message_interval_t {
 uint16_t interval; /*< [ms] 0 to disable*/
 uint8_t message_id; /*<  */
} mavlink_cmd_set_message_interval_t;

#define MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN 3
#define MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN 3
#define MAVLINK_MSG_ID_4_LEN 3
#define MAVLINK_MSG_ID_4_MIN_LEN 3

#define MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_CRC 201
#define MAVLINK_MSG_ID_4_CRC 201



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_SET_MESSAGE_INTERVAL { \
    4, \
    "CMD_SET_MESSAGE_INTERVAL", \
    2, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_cmd_set_message_interval_t, message_id) }, \
         { "interval", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_cmd_set_message_interval_t, interval) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_SET_MESSAGE_INTERVAL { \
    "CMD_SET_MESSAGE_INTERVAL", \
    2, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_cmd_set_message_interval_t, message_id) }, \
         { "interval", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_cmd_set_message_interval_t, interval) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_set_message_interval message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id  
 * @param interval [ms] 0 to disable
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_set_message_interval_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t message_id, uint16_t interval)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN];
    _mav_put_uint16_t(buf, 0, interval);
    _mav_put_uint8_t(buf, 2, message_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN);
#else
    mavlink_cmd_set_message_interval_t packet;
    packet.interval = interval;
    packet.message_id = message_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_CRC);
}

/**
 * @brief Pack a cmd_set_message_interval message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_id  
 * @param interval [ms] 0 to disable
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_set_message_interval_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t message_id,uint16_t interval)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN];
    _mav_put_uint16_t(buf, 0, interval);
    _mav_put_uint8_t(buf, 2, message_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN);
#else
    mavlink_cmd_set_message_interval_t packet;
    packet.interval = interval;
    packet.message_id = message_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_CRC);
}

/**
 * @brief Encode a cmd_set_message_interval struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_set_message_interval C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_set_message_interval_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_set_message_interval_t* cmd_set_message_interval)
{
    return mavlink_msg_cmd_set_message_interval_pack(system_id, component_id, msg, cmd_set_message_interval->message_id, cmd_set_message_interval->interval);
}

/**
 * @brief Encode a cmd_set_message_interval struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_set_message_interval C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_set_message_interval_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_set_message_interval_t* cmd_set_message_interval)
{
    return mavlink_msg_cmd_set_message_interval_pack_chan(system_id, component_id, chan, msg, cmd_set_message_interval->message_id, cmd_set_message_interval->interval);
}

/**
 * @brief Send a cmd_set_message_interval message
 * @param chan MAVLink channel to send the message
 *
 * @param message_id  
 * @param interval [ms] 0 to disable
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_set_message_interval_send(mavlink_channel_t chan, uint8_t message_id, uint16_t interval)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN];
    _mav_put_uint16_t(buf, 0, interval);
    _mav_put_uint8_t(buf, 2, message_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL, buf, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_CRC);
#else
    mavlink_cmd_set_message_interval_t packet;
    packet.interval = interval;
    packet.message_id = message_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL, (const char *)&packet, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_CRC);
#endif
}

/**
 * @brief Send a cmd_set_message_interval message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_set_message_interval_send_struct(mavlink_channel_t chan, const mavlink_cmd_set_message_interval_t* cmd_set_message_interval)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_set_message_interval_send(chan, cmd_set_message_interval->message_id, cmd_set_message_interval->interval);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL, (const char *)cmd_set_message_interval, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_set_message_interval_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t message_id, uint16_t interval)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, interval);
    _mav_put_uint8_t(buf, 2, message_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL, buf, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_CRC);
#else
    mavlink_cmd_set_message_interval_t *packet = (mavlink_cmd_set_message_interval_t *)msgbuf;
    packet->interval = interval;
    packet->message_id = message_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL, (const char *)packet, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_SET_MESSAGE_INTERVAL UNPACKING


/**
 * @brief Get field message_id from cmd_set_message_interval message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_cmd_set_message_interval_get_message_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field interval from cmd_set_message_interval message
 *
 * @return [ms] 0 to disable
 */
static inline uint16_t mavlink_msg_cmd_set_message_interval_get_interval(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a cmd_set_message_interval message into a struct
 *
 * @param msg The message to decode
 * @param cmd_set_message_interval C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_set_message_interval_decode(const mavlink_message_t* msg, mavlink_cmd_set_message_interval_t* cmd_set_message_interval)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_set_message_interval->interval = mavlink_msg_cmd_set_message_interval_get_interval(msg);
    cmd_set_message_interval->message_id = mavlink_msg_cmd_set_message_interval_get_message_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN? msg->len : MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN;
        memset(cmd_set_message_interval, 0, MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_LEN);
    memcpy(cmd_set_message_interval, _MAV_PAYLOAD(msg), len);
#endif
}
