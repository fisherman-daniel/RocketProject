#pragma once
// MESSAGE ACK_CMD PACKING

#define MAVLINK_MSG_ID_ACK_CMD 2


typedef struct __mavlink_ack_cmd_t {
 uint8_t message_id; /*<  */
 uint8_t result; /*<  Allows indicating whether command succesfully completed*/
} mavlink_ack_cmd_t;

#define MAVLINK_MSG_ID_ACK_CMD_LEN 2
#define MAVLINK_MSG_ID_ACK_CMD_MIN_LEN 2
#define MAVLINK_MSG_ID_2_LEN 2
#define MAVLINK_MSG_ID_2_MIN_LEN 2

#define MAVLINK_MSG_ID_ACK_CMD_CRC 82
#define MAVLINK_MSG_ID_2_CRC 82



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACK_CMD { \
    2, \
    "ACK_CMD", \
    2, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ack_cmd_t, message_id) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_ack_cmd_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACK_CMD { \
    "ACK_CMD", \
    2, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ack_cmd_t, message_id) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_ack_cmd_t, result) }, \
         } \
}
#endif

/**
 * @brief Pack a ack_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id  
 * @param result  Allows indicating whether command succesfully completed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ack_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t message_id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACK_CMD_LEN];
    _mav_put_uint8_t(buf, 0, message_id);
    _mav_put_uint8_t(buf, 1, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACK_CMD_LEN);
#else
    mavlink_ack_cmd_t packet;
    packet.message_id = message_id;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACK_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACK_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACK_CMD_MIN_LEN, MAVLINK_MSG_ID_ACK_CMD_LEN, MAVLINK_MSG_ID_ACK_CMD_CRC);
}

/**
 * @brief Pack a ack_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_id  
 * @param result  Allows indicating whether command succesfully completed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ack_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t message_id,uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACK_CMD_LEN];
    _mav_put_uint8_t(buf, 0, message_id);
    _mav_put_uint8_t(buf, 1, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACK_CMD_LEN);
#else
    mavlink_ack_cmd_t packet;
    packet.message_id = message_id;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACK_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACK_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACK_CMD_MIN_LEN, MAVLINK_MSG_ID_ACK_CMD_LEN, MAVLINK_MSG_ID_ACK_CMD_CRC);
}

/**
 * @brief Encode a ack_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ack_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ack_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ack_cmd_t* ack_cmd)
{
    return mavlink_msg_ack_cmd_pack(system_id, component_id, msg, ack_cmd->message_id, ack_cmd->result);
}

/**
 * @brief Encode a ack_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ack_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ack_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ack_cmd_t* ack_cmd)
{
    return mavlink_msg_ack_cmd_pack_chan(system_id, component_id, chan, msg, ack_cmd->message_id, ack_cmd->result);
}

/**
 * @brief Send a ack_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param message_id  
 * @param result  Allows indicating whether command succesfully completed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ack_cmd_send(mavlink_channel_t chan, uint8_t message_id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACK_CMD_LEN];
    _mav_put_uint8_t(buf, 0, message_id);
    _mav_put_uint8_t(buf, 1, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK_CMD, buf, MAVLINK_MSG_ID_ACK_CMD_MIN_LEN, MAVLINK_MSG_ID_ACK_CMD_LEN, MAVLINK_MSG_ID_ACK_CMD_CRC);
#else
    mavlink_ack_cmd_t packet;
    packet.message_id = message_id;
    packet.result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK_CMD, (const char *)&packet, MAVLINK_MSG_ID_ACK_CMD_MIN_LEN, MAVLINK_MSG_ID_ACK_CMD_LEN, MAVLINK_MSG_ID_ACK_CMD_CRC);
#endif
}

/**
 * @brief Send a ack_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ack_cmd_send_struct(mavlink_channel_t chan, const mavlink_ack_cmd_t* ack_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ack_cmd_send(chan, ack_cmd->message_id, ack_cmd->result);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK_CMD, (const char *)ack_cmd, MAVLINK_MSG_ID_ACK_CMD_MIN_LEN, MAVLINK_MSG_ID_ACK_CMD_LEN, MAVLINK_MSG_ID_ACK_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_ACK_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ack_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t message_id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, message_id);
    _mav_put_uint8_t(buf, 1, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK_CMD, buf, MAVLINK_MSG_ID_ACK_CMD_MIN_LEN, MAVLINK_MSG_ID_ACK_CMD_LEN, MAVLINK_MSG_ID_ACK_CMD_CRC);
#else
    mavlink_ack_cmd_t *packet = (mavlink_ack_cmd_t *)msgbuf;
    packet->message_id = message_id;
    packet->result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK_CMD, (const char *)packet, MAVLINK_MSG_ID_ACK_CMD_MIN_LEN, MAVLINK_MSG_ID_ACK_CMD_LEN, MAVLINK_MSG_ID_ACK_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE ACK_CMD UNPACKING


/**
 * @brief Get field message_id from ack_cmd message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_ack_cmd_get_message_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field result from ack_cmd message
 *
 * @return  Allows indicating whether command succesfully completed
 */
static inline uint8_t mavlink_msg_ack_cmd_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a ack_cmd message into a struct
 *
 * @param msg The message to decode
 * @param ack_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_ack_cmd_decode(const mavlink_message_t* msg, mavlink_ack_cmd_t* ack_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ack_cmd->message_id = mavlink_msg_ack_cmd_get_message_id(msg);
    ack_cmd->result = mavlink_msg_ack_cmd_get_result(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ACK_CMD_LEN? msg->len : MAVLINK_MSG_ID_ACK_CMD_LEN;
        memset(ack_cmd, 0, MAVLINK_MSG_ID_ACK_CMD_LEN);
    memcpy(ack_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
