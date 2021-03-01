#pragma once
// MESSAGE CMD_REQUEST_MESSAGE PACKING

#define MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE 3


typedef struct __mavlink_cmd_request_message_t {
 uint8_t message_id; /*<  */
} mavlink_cmd_request_message_t;

#define MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN 1
#define MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN 1
#define MAVLINK_MSG_ID_3_LEN 1
#define MAVLINK_MSG_ID_3_MIN_LEN 1

#define MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_CRC 195
#define MAVLINK_MSG_ID_3_CRC 195



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_REQUEST_MESSAGE { \
    3, \
    "CMD_REQUEST_MESSAGE", \
    1, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_request_message_t, message_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_REQUEST_MESSAGE { \
    "CMD_REQUEST_MESSAGE", \
    1, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_request_message_t, message_id) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_request_message message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_request_message_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t message_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN];
    _mav_put_uint8_t(buf, 0, message_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN);
#else
    mavlink_cmd_request_message_t packet;
    packet.message_id = message_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_CRC);
}

/**
 * @brief Pack a cmd_request_message message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_id  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_request_message_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t message_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN];
    _mav_put_uint8_t(buf, 0, message_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN);
#else
    mavlink_cmd_request_message_t packet;
    packet.message_id = message_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_CRC);
}

/**
 * @brief Encode a cmd_request_message struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_request_message C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_request_message_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_request_message_t* cmd_request_message)
{
    return mavlink_msg_cmd_request_message_pack(system_id, component_id, msg, cmd_request_message->message_id);
}

/**
 * @brief Encode a cmd_request_message struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_request_message C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_request_message_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_request_message_t* cmd_request_message)
{
    return mavlink_msg_cmd_request_message_pack_chan(system_id, component_id, chan, msg, cmd_request_message->message_id);
}

/**
 * @brief Send a cmd_request_message message
 * @param chan MAVLink channel to send the message
 *
 * @param message_id  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_request_message_send(mavlink_channel_t chan, uint8_t message_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN];
    _mav_put_uint8_t(buf, 0, message_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE, buf, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_CRC);
#else
    mavlink_cmd_request_message_t packet;
    packet.message_id = message_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE, (const char *)&packet, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_CRC);
#endif
}

/**
 * @brief Send a cmd_request_message message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_request_message_send_struct(mavlink_channel_t chan, const mavlink_cmd_request_message_t* cmd_request_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_request_message_send(chan, cmd_request_message->message_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE, (const char *)cmd_request_message, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_request_message_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t message_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, message_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE, buf, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_CRC);
#else
    mavlink_cmd_request_message_t *packet = (mavlink_cmd_request_message_t *)msgbuf;
    packet->message_id = message_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE, (const char *)packet, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_REQUEST_MESSAGE UNPACKING


/**
 * @brief Get field message_id from cmd_request_message message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_cmd_request_message_get_message_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a cmd_request_message message into a struct
 *
 * @param msg The message to decode
 * @param cmd_request_message C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_request_message_decode(const mavlink_message_t* msg, mavlink_cmd_request_message_t* cmd_request_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_request_message->message_id = mavlink_msg_cmd_request_message_get_message_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN? msg->len : MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN;
        memset(cmd_request_message, 0, MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_LEN);
    memcpy(cmd_request_message, _MAV_PAYLOAD(msg), len);
#endif
}
