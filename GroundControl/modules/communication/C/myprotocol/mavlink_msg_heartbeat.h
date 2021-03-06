#pragma once
// MESSAGE HEARTBEAT PACKING

#define MAVLINK_MSG_ID_HEARTBEAT 0


typedef struct __mavlink_heartbeat_t {
 uint8_t system_type; /*<  */
 uint8_t component_type; /*<  */
} mavlink_heartbeat_t;

#define MAVLINK_MSG_ID_HEARTBEAT_LEN 2
#define MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN 2
#define MAVLINK_MSG_ID_0_LEN 2
#define MAVLINK_MSG_ID_0_MIN_LEN 2

#define MAVLINK_MSG_ID_HEARTBEAT_CRC 86
#define MAVLINK_MSG_ID_0_CRC 86



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
    0, \
    "HEARTBEAT", \
    2, \
    {  { "system_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_heartbeat_t, system_type) }, \
         { "component_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_heartbeat_t, component_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
    "HEARTBEAT", \
    2, \
    {  { "system_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_heartbeat_t, system_type) }, \
         { "component_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_heartbeat_t, component_type) }, \
         } \
}
#endif

/**
 * @brief Pack a heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param system_type  
 * @param component_type  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t system_type, uint8_t component_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
    _mav_put_uint8_t(buf, 0, system_type);
    _mav_put_uint8_t(buf, 1, component_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
    mavlink_heartbeat_t packet;
    packet.system_type = system_type;
    packet.component_type = component_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
}

/**
 * @brief Pack a heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param system_type  
 * @param component_type  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t system_type,uint8_t component_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
    _mav_put_uint8_t(buf, 0, system_type);
    _mav_put_uint8_t(buf, 1, component_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
    mavlink_heartbeat_t packet;
    packet.system_type = system_type;
    packet.component_type = component_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
}

/**
 * @brief Encode a heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_heartbeat_t* heartbeat)
{
    return mavlink_msg_heartbeat_pack(system_id, component_id, msg, heartbeat->system_type, heartbeat->component_type);
}

/**
 * @brief Encode a heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_heartbeat_t* heartbeat)
{
    return mavlink_msg_heartbeat_pack_chan(system_id, component_id, chan, msg, heartbeat->system_type, heartbeat->component_type);
}

/**
 * @brief Send a heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param system_type  
 * @param component_type  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_heartbeat_send(mavlink_channel_t chan, uint8_t system_type, uint8_t component_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
    _mav_put_uint8_t(buf, 0, system_type);
    _mav_put_uint8_t(buf, 1, component_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    mavlink_heartbeat_t packet;
    packet.system_type = system_type;
    packet.component_type = component_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}

/**
 * @brief Send a heartbeat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_heartbeat_send_struct(mavlink_channel_t chan, const mavlink_heartbeat_t* heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_heartbeat_send(chan, heartbeat->system_type, heartbeat->component_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)heartbeat, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t system_type, uint8_t component_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, system_type);
    _mav_put_uint8_t(buf, 1, component_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    mavlink_heartbeat_t *packet = (mavlink_heartbeat_t *)msgbuf;
    packet->system_type = system_type;
    packet->component_type = component_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE HEARTBEAT UNPACKING


/**
 * @brief Get field system_type from heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_heartbeat_get_system_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field component_type from heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_heartbeat_get_component_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_heartbeat_decode(const mavlink_message_t* msg, mavlink_heartbeat_t* heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    heartbeat->system_type = mavlink_msg_heartbeat_get_system_type(msg);
    heartbeat->component_type = mavlink_msg_heartbeat_get_component_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HEARTBEAT_LEN? msg->len : MAVLINK_MSG_ID_HEARTBEAT_LEN;
        memset(heartbeat, 0, MAVLINK_MSG_ID_HEARTBEAT_LEN);
    memcpy(heartbeat, _MAV_PAYLOAD(msg), len);
#endif
}
