#pragma once
// MESSAGE CMD_SET_POWER_SOURCE PACKING

#define MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE 97


typedef struct __mavlink_cmd_set_power_source_t {
 uint8_t power_source; /*<  */
} mavlink_cmd_set_power_source_t;

#define MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN 1
#define MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN 1
#define MAVLINK_MSG_ID_97_LEN 1
#define MAVLINK_MSG_ID_97_MIN_LEN 1

#define MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_CRC 57
#define MAVLINK_MSG_ID_97_CRC 57



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_SET_POWER_SOURCE { \
    97, \
    "CMD_SET_POWER_SOURCE", \
    1, \
    {  { "power_source", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_set_power_source_t, power_source) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_SET_POWER_SOURCE { \
    "CMD_SET_POWER_SOURCE", \
    1, \
    {  { "power_source", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_set_power_source_t, power_source) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_set_power_source message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param power_source  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_set_power_source_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t power_source)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN];
    _mav_put_uint8_t(buf, 0, power_source);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN);
#else
    mavlink_cmd_set_power_source_t packet;
    packet.power_source = power_source;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_CRC);
}

/**
 * @brief Pack a cmd_set_power_source message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param power_source  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_set_power_source_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t power_source)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN];
    _mav_put_uint8_t(buf, 0, power_source);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN);
#else
    mavlink_cmd_set_power_source_t packet;
    packet.power_source = power_source;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_CRC);
}

/**
 * @brief Encode a cmd_set_power_source struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_set_power_source C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_set_power_source_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_set_power_source_t* cmd_set_power_source)
{
    return mavlink_msg_cmd_set_power_source_pack(system_id, component_id, msg, cmd_set_power_source->power_source);
}

/**
 * @brief Encode a cmd_set_power_source struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_set_power_source C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_set_power_source_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_set_power_source_t* cmd_set_power_source)
{
    return mavlink_msg_cmd_set_power_source_pack_chan(system_id, component_id, chan, msg, cmd_set_power_source->power_source);
}

/**
 * @brief Send a cmd_set_power_source message
 * @param chan MAVLink channel to send the message
 *
 * @param power_source  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_set_power_source_send(mavlink_channel_t chan, uint8_t power_source)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN];
    _mav_put_uint8_t(buf, 0, power_source);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE, buf, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_CRC);
#else
    mavlink_cmd_set_power_source_t packet;
    packet.power_source = power_source;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE, (const char *)&packet, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_CRC);
#endif
}

/**
 * @brief Send a cmd_set_power_source message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_set_power_source_send_struct(mavlink_channel_t chan, const mavlink_cmd_set_power_source_t* cmd_set_power_source)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_set_power_source_send(chan, cmd_set_power_source->power_source);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE, (const char *)cmd_set_power_source, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_set_power_source_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t power_source)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, power_source);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE, buf, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_CRC);
#else
    mavlink_cmd_set_power_source_t *packet = (mavlink_cmd_set_power_source_t *)msgbuf;
    packet->power_source = power_source;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE, (const char *)packet, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_SET_POWER_SOURCE UNPACKING


/**
 * @brief Get field power_source from cmd_set_power_source message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_cmd_set_power_source_get_power_source(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a cmd_set_power_source message into a struct
 *
 * @param msg The message to decode
 * @param cmd_set_power_source C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_set_power_source_decode(const mavlink_message_t* msg, mavlink_cmd_set_power_source_t* cmd_set_power_source)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_set_power_source->power_source = mavlink_msg_cmd_set_power_source_get_power_source(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN? msg->len : MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN;
        memset(cmd_set_power_source, 0, MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_LEN);
    memcpy(cmd_set_power_source, _MAV_PAYLOAD(msg), len);
#endif
}
