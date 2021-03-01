#pragma once
// MESSAGE CMD_ABORT PACKING

#define MAVLINK_MSG_ID_CMD_ABORT 64


typedef struct __mavlink_cmd_abort_t {
 uint8_t hard; /*<  0 for normal abort. 1 for hard abort.*/
} mavlink_cmd_abort_t;

#define MAVLINK_MSG_ID_CMD_ABORT_LEN 1
#define MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN 1
#define MAVLINK_MSG_ID_64_LEN 1
#define MAVLINK_MSG_ID_64_MIN_LEN 1

#define MAVLINK_MSG_ID_CMD_ABORT_CRC 21
#define MAVLINK_MSG_ID_64_CRC 21



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_ABORT { \
    64, \
    "CMD_ABORT", \
    1, \
    {  { "hard", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_abort_t, hard) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_ABORT { \
    "CMD_ABORT", \
    1, \
    {  { "hard", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_abort_t, hard) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_abort message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param hard  0 for normal abort. 1 for hard abort.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_abort_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t hard)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_ABORT_LEN];
    _mav_put_uint8_t(buf, 0, hard);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_ABORT_LEN);
#else
    mavlink_cmd_abort_t packet;
    packet.hard = hard;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_ABORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_ABORT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN, MAVLINK_MSG_ID_CMD_ABORT_LEN, MAVLINK_MSG_ID_CMD_ABORT_CRC);
}

/**
 * @brief Pack a cmd_abort message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hard  0 for normal abort. 1 for hard abort.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_abort_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t hard)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_ABORT_LEN];
    _mav_put_uint8_t(buf, 0, hard);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_ABORT_LEN);
#else
    mavlink_cmd_abort_t packet;
    packet.hard = hard;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_ABORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_ABORT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN, MAVLINK_MSG_ID_CMD_ABORT_LEN, MAVLINK_MSG_ID_CMD_ABORT_CRC);
}

/**
 * @brief Encode a cmd_abort struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_abort C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_abort_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_abort_t* cmd_abort)
{
    return mavlink_msg_cmd_abort_pack(system_id, component_id, msg, cmd_abort->hard);
}

/**
 * @brief Encode a cmd_abort struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_abort C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_abort_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_abort_t* cmd_abort)
{
    return mavlink_msg_cmd_abort_pack_chan(system_id, component_id, chan, msg, cmd_abort->hard);
}

/**
 * @brief Send a cmd_abort message
 * @param chan MAVLink channel to send the message
 *
 * @param hard  0 for normal abort. 1 for hard abort.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_abort_send(mavlink_channel_t chan, uint8_t hard)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_ABORT_LEN];
    _mav_put_uint8_t(buf, 0, hard);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ABORT, buf, MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN, MAVLINK_MSG_ID_CMD_ABORT_LEN, MAVLINK_MSG_ID_CMD_ABORT_CRC);
#else
    mavlink_cmd_abort_t packet;
    packet.hard = hard;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ABORT, (const char *)&packet, MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN, MAVLINK_MSG_ID_CMD_ABORT_LEN, MAVLINK_MSG_ID_CMD_ABORT_CRC);
#endif
}

/**
 * @brief Send a cmd_abort message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_abort_send_struct(mavlink_channel_t chan, const mavlink_cmd_abort_t* cmd_abort)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_abort_send(chan, cmd_abort->hard);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ABORT, (const char *)cmd_abort, MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN, MAVLINK_MSG_ID_CMD_ABORT_LEN, MAVLINK_MSG_ID_CMD_ABORT_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_ABORT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_abort_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t hard)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, hard);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ABORT, buf, MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN, MAVLINK_MSG_ID_CMD_ABORT_LEN, MAVLINK_MSG_ID_CMD_ABORT_CRC);
#else
    mavlink_cmd_abort_t *packet = (mavlink_cmd_abort_t *)msgbuf;
    packet->hard = hard;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_ABORT, (const char *)packet, MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN, MAVLINK_MSG_ID_CMD_ABORT_LEN, MAVLINK_MSG_ID_CMD_ABORT_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_ABORT UNPACKING


/**
 * @brief Get field hard from cmd_abort message
 *
 * @return  0 for normal abort. 1 for hard abort.
 */
static inline uint8_t mavlink_msg_cmd_abort_get_hard(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a cmd_abort message into a struct
 *
 * @param msg The message to decode
 * @param cmd_abort C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_abort_decode(const mavlink_message_t* msg, mavlink_cmd_abort_t* cmd_abort)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_abort->hard = mavlink_msg_cmd_abort_get_hard(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_ABORT_LEN? msg->len : MAVLINK_MSG_ID_CMD_ABORT_LEN;
        memset(cmd_abort, 0, MAVLINK_MSG_ID_CMD_ABORT_LEN);
    memcpy(cmd_abort, _MAV_PAYLOAD(msg), len);
#endif
}
