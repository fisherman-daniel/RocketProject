#pragma once
// MESSAGE CMD_PROCEED PACKING

#define MAVLINK_MSG_ID_CMD_PROCEED 66


typedef struct __mavlink_cmd_proceed_t {

} mavlink_cmd_proceed_t;

#define MAVLINK_MSG_ID_CMD_PROCEED_LEN 0
#define MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN 0
#define MAVLINK_MSG_ID_66_LEN 0
#define MAVLINK_MSG_ID_66_MIN_LEN 0

#define MAVLINK_MSG_ID_CMD_PROCEED_CRC 28
#define MAVLINK_MSG_ID_66_CRC 28



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_PROCEED { \
    66, \
    "CMD_PROCEED", \
    0, \
    {  } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_PROCEED { \
    "CMD_PROCEED", \
    0, \
    {  } \
}
#endif

/**
 * @brief Pack a cmd_proceed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *

 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_proceed_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                              )
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_PROCEED_LEN];


        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_PROCEED_LEN);
#else
    mavlink_cmd_proceed_t packet;


        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_PROCEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_PROCEED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN, MAVLINK_MSG_ID_CMD_PROCEED_LEN, MAVLINK_MSG_ID_CMD_PROCEED_CRC);
}

/**
 * @brief Pack a cmd_proceed message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into

 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_proceed_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   )
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_PROCEED_LEN];


        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_PROCEED_LEN);
#else
    mavlink_cmd_proceed_t packet;


        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_PROCEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_PROCEED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN, MAVLINK_MSG_ID_CMD_PROCEED_LEN, MAVLINK_MSG_ID_CMD_PROCEED_CRC);
}

/**
 * @brief Encode a cmd_proceed struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_proceed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_proceed_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_proceed_t* cmd_proceed)
{
    return mavlink_msg_cmd_proceed_pack(system_id, component_id, msg,);
}

/**
 * @brief Encode a cmd_proceed struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_proceed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_proceed_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_proceed_t* cmd_proceed)
{
    return mavlink_msg_cmd_proceed_pack_chan(system_id, component_id, chan, msg,);
}

/**
 * @brief Send a cmd_proceed message
 * @param chan MAVLink channel to send the message
 *

 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_proceed_send(mavlink_channel_t chan,)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_PROCEED_LEN];


    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PROCEED, buf, MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN, MAVLINK_MSG_ID_CMD_PROCEED_LEN, MAVLINK_MSG_ID_CMD_PROCEED_CRC);
#else
    mavlink_cmd_proceed_t packet;


    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PROCEED, (const char *)&packet, MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN, MAVLINK_MSG_ID_CMD_PROCEED_LEN, MAVLINK_MSG_ID_CMD_PROCEED_CRC);
#endif
}

/**
 * @brief Send a cmd_proceed message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_proceed_send_struct(mavlink_channel_t chan, const mavlink_cmd_proceed_t* cmd_proceed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_proceed_send(chan,);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PROCEED, (const char *)cmd_proceed, MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN, MAVLINK_MSG_ID_CMD_PROCEED_LEN, MAVLINK_MSG_ID_CMD_PROCEED_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_PROCEED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_proceed_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan, )
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;


    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PROCEED, buf, MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN, MAVLINK_MSG_ID_CMD_PROCEED_LEN, MAVLINK_MSG_ID_CMD_PROCEED_CRC);
#else
    mavlink_cmd_proceed_t *packet = (mavlink_cmd_proceed_t *)msgbuf;


    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_PROCEED, (const char *)packet, MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN, MAVLINK_MSG_ID_CMD_PROCEED_LEN, MAVLINK_MSG_ID_CMD_PROCEED_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_PROCEED UNPACKING



/**
 * @brief Decode a cmd_proceed message into a struct
 *
 * @param msg The message to decode
 * @param cmd_proceed C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_proceed_decode(const mavlink_message_t* msg, mavlink_cmd_proceed_t* cmd_proceed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS

#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_PROCEED_LEN? msg->len : MAVLINK_MSG_ID_CMD_PROCEED_LEN;
        memset(cmd_proceed, 0, MAVLINK_MSG_ID_CMD_PROCEED_LEN);
    memcpy(cmd_proceed, _MAV_PAYLOAD(msg), len);
#endif
}
