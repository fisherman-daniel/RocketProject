#pragma once
// MESSAGE PRE_CMD PACKING

#define MAVLINK_MSG_ID_PRE_CMD 1


typedef struct __mavlink_pre_cmd_t {
 uint8_t message_id; /*<  */
} mavlink_pre_cmd_t;

#define MAVLINK_MSG_ID_PRE_CMD_LEN 1
#define MAVLINK_MSG_ID_PRE_CMD_MIN_LEN 1
#define MAVLINK_MSG_ID_1_LEN 1
#define MAVLINK_MSG_ID_1_MIN_LEN 1

#define MAVLINK_MSG_ID_PRE_CMD_CRC 158
#define MAVLINK_MSG_ID_1_CRC 158



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PRE_CMD { \
    1, \
    "PRE_CMD", \
    1, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_pre_cmd_t, message_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PRE_CMD { \
    "PRE_CMD", \
    1, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_pre_cmd_t, message_id) }, \
         } \
}
#endif

/**
 * @brief Pack a pre_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pre_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t message_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRE_CMD_LEN];
    _mav_put_uint8_t(buf, 0, message_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRE_CMD_LEN);
#else
    mavlink_pre_cmd_t packet;
    packet.message_id = message_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRE_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PRE_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PRE_CMD_MIN_LEN, MAVLINK_MSG_ID_PRE_CMD_LEN, MAVLINK_MSG_ID_PRE_CMD_CRC);
}

/**
 * @brief Pack a pre_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_id  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pre_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t message_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRE_CMD_LEN];
    _mav_put_uint8_t(buf, 0, message_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PRE_CMD_LEN);
#else
    mavlink_pre_cmd_t packet;
    packet.message_id = message_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PRE_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PRE_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PRE_CMD_MIN_LEN, MAVLINK_MSG_ID_PRE_CMD_LEN, MAVLINK_MSG_ID_PRE_CMD_CRC);
}

/**
 * @brief Encode a pre_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pre_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pre_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pre_cmd_t* pre_cmd)
{
    return mavlink_msg_pre_cmd_pack(system_id, component_id, msg, pre_cmd->message_id);
}

/**
 * @brief Encode a pre_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pre_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pre_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pre_cmd_t* pre_cmd)
{
    return mavlink_msg_pre_cmd_pack_chan(system_id, component_id, chan, msg, pre_cmd->message_id);
}

/**
 * @brief Send a pre_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param message_id  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pre_cmd_send(mavlink_channel_t chan, uint8_t message_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PRE_CMD_LEN];
    _mav_put_uint8_t(buf, 0, message_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRE_CMD, buf, MAVLINK_MSG_ID_PRE_CMD_MIN_LEN, MAVLINK_MSG_ID_PRE_CMD_LEN, MAVLINK_MSG_ID_PRE_CMD_CRC);
#else
    mavlink_pre_cmd_t packet;
    packet.message_id = message_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRE_CMD, (const char *)&packet, MAVLINK_MSG_ID_PRE_CMD_MIN_LEN, MAVLINK_MSG_ID_PRE_CMD_LEN, MAVLINK_MSG_ID_PRE_CMD_CRC);
#endif
}

/**
 * @brief Send a pre_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pre_cmd_send_struct(mavlink_channel_t chan, const mavlink_pre_cmd_t* pre_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pre_cmd_send(chan, pre_cmd->message_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRE_CMD, (const char *)pre_cmd, MAVLINK_MSG_ID_PRE_CMD_MIN_LEN, MAVLINK_MSG_ID_PRE_CMD_LEN, MAVLINK_MSG_ID_PRE_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_PRE_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pre_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t message_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, message_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRE_CMD, buf, MAVLINK_MSG_ID_PRE_CMD_MIN_LEN, MAVLINK_MSG_ID_PRE_CMD_LEN, MAVLINK_MSG_ID_PRE_CMD_CRC);
#else
    mavlink_pre_cmd_t *packet = (mavlink_pre_cmd_t *)msgbuf;
    packet->message_id = message_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PRE_CMD, (const char *)packet, MAVLINK_MSG_ID_PRE_CMD_MIN_LEN, MAVLINK_MSG_ID_PRE_CMD_LEN, MAVLINK_MSG_ID_PRE_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE PRE_CMD UNPACKING


/**
 * @brief Get field message_id from pre_cmd message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_pre_cmd_get_message_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a pre_cmd message into a struct
 *
 * @param msg The message to decode
 * @param pre_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_pre_cmd_decode(const mavlink_message_t* msg, mavlink_pre_cmd_t* pre_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pre_cmd->message_id = mavlink_msg_pre_cmd_get_message_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PRE_CMD_LEN? msg->len : MAVLINK_MSG_ID_PRE_CMD_LEN;
        memset(pre_cmd, 0, MAVLINK_MSG_ID_PRE_CMD_LEN);
    memcpy(pre_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
