#pragma once
// MESSAGE CMD_SET_VALVE PACKING

#define MAVLINK_MSG_ID_CMD_SET_VALVE 96


typedef struct __mavlink_cmd_set_valve_t {
 uint8_t valve; /*<  */
 uint8_t valve_mode; /*<  */
 uint8_t desired_position; /*<  don't save this value unless in position control mode*/
} mavlink_cmd_set_valve_t;

#define MAVLINK_MSG_ID_CMD_SET_VALVE_LEN 3
#define MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN 3
#define MAVLINK_MSG_ID_96_LEN 3
#define MAVLINK_MSG_ID_96_MIN_LEN 3

#define MAVLINK_MSG_ID_CMD_SET_VALVE_CRC 32
#define MAVLINK_MSG_ID_96_CRC 32



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_SET_VALVE { \
    96, \
    "CMD_SET_VALVE", \
    3, \
    {  { "valve", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_set_valve_t, valve) }, \
         { "valve_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_cmd_set_valve_t, valve_mode) }, \
         { "desired_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_cmd_set_valve_t, desired_position) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_SET_VALVE { \
    "CMD_SET_VALVE", \
    3, \
    {  { "valve", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_set_valve_t, valve) }, \
         { "valve_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_cmd_set_valve_t, valve_mode) }, \
         { "desired_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_cmd_set_valve_t, desired_position) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_set_valve message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param valve  
 * @param valve_mode  
 * @param desired_position  don't save this value unless in position control mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_set_valve_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t valve, uint8_t valve_mode, uint8_t desired_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_VALVE_LEN];
    _mav_put_uint8_t(buf, 0, valve);
    _mav_put_uint8_t(buf, 1, valve_mode);
    _mav_put_uint8_t(buf, 2, desired_position);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN);
#else
    mavlink_cmd_set_valve_t packet;
    packet.valve = valve;
    packet.valve_mode = valve_mode;
    packet.desired_position = desired_position;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_SET_VALVE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_CRC);
}

/**
 * @brief Pack a cmd_set_valve message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param valve  
 * @param valve_mode  
 * @param desired_position  don't save this value unless in position control mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_set_valve_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t valve,uint8_t valve_mode,uint8_t desired_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_VALVE_LEN];
    _mav_put_uint8_t(buf, 0, valve);
    _mav_put_uint8_t(buf, 1, valve_mode);
    _mav_put_uint8_t(buf, 2, desired_position);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN);
#else
    mavlink_cmd_set_valve_t packet;
    packet.valve = valve;
    packet.valve_mode = valve_mode;
    packet.desired_position = desired_position;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_SET_VALVE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_CRC);
}

/**
 * @brief Encode a cmd_set_valve struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_set_valve C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_set_valve_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_set_valve_t* cmd_set_valve)
{
    return mavlink_msg_cmd_set_valve_pack(system_id, component_id, msg, cmd_set_valve->valve, cmd_set_valve->valve_mode, cmd_set_valve->desired_position);
}

/**
 * @brief Encode a cmd_set_valve struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_set_valve C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_set_valve_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_set_valve_t* cmd_set_valve)
{
    return mavlink_msg_cmd_set_valve_pack_chan(system_id, component_id, chan, msg, cmd_set_valve->valve, cmd_set_valve->valve_mode, cmd_set_valve->desired_position);
}

/**
 * @brief Send a cmd_set_valve message
 * @param chan MAVLink channel to send the message
 *
 * @param valve  
 * @param valve_mode  
 * @param desired_position  don't save this value unless in position control mode
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_set_valve_send(mavlink_channel_t chan, uint8_t valve, uint8_t valve_mode, uint8_t desired_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_VALVE_LEN];
    _mav_put_uint8_t(buf, 0, valve);
    _mav_put_uint8_t(buf, 1, valve_mode);
    _mav_put_uint8_t(buf, 2, desired_position);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_VALVE, buf, MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_CRC);
#else
    mavlink_cmd_set_valve_t packet;
    packet.valve = valve;
    packet.valve_mode = valve_mode;
    packet.desired_position = desired_position;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_VALVE, (const char *)&packet, MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_CRC);
#endif
}

/**
 * @brief Send a cmd_set_valve message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_set_valve_send_struct(mavlink_channel_t chan, const mavlink_cmd_set_valve_t* cmd_set_valve)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_set_valve_send(chan, cmd_set_valve->valve, cmd_set_valve->valve_mode, cmd_set_valve->desired_position);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_VALVE, (const char *)cmd_set_valve, MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_SET_VALVE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_set_valve_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t valve, uint8_t valve_mode, uint8_t desired_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, valve);
    _mav_put_uint8_t(buf, 1, valve_mode);
    _mav_put_uint8_t(buf, 2, desired_position);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_VALVE, buf, MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_CRC);
#else
    mavlink_cmd_set_valve_t *packet = (mavlink_cmd_set_valve_t *)msgbuf;
    packet->valve = valve;
    packet->valve_mode = valve_mode;
    packet->desired_position = desired_position;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_VALVE, (const char *)packet, MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN, MAVLINK_MSG_ID_CMD_SET_VALVE_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_SET_VALVE UNPACKING


/**
 * @brief Get field valve from cmd_set_valve message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_cmd_set_valve_get_valve(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field valve_mode from cmd_set_valve message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_cmd_set_valve_get_valve_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field desired_position from cmd_set_valve message
 *
 * @return  don't save this value unless in position control mode
 */
static inline uint8_t mavlink_msg_cmd_set_valve_get_desired_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a cmd_set_valve message into a struct
 *
 * @param msg The message to decode
 * @param cmd_set_valve C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_set_valve_decode(const mavlink_message_t* msg, mavlink_cmd_set_valve_t* cmd_set_valve)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_set_valve->valve = mavlink_msg_cmd_set_valve_get_valve(msg);
    cmd_set_valve->valve_mode = mavlink_msg_cmd_set_valve_get_valve_mode(msg);
    cmd_set_valve->desired_position = mavlink_msg_cmd_set_valve_get_desired_position(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_SET_VALVE_LEN? msg->len : MAVLINK_MSG_ID_CMD_SET_VALVE_LEN;
        memset(cmd_set_valve, 0, MAVLINK_MSG_ID_CMD_SET_VALVE_LEN);
    memcpy(cmd_set_valve, _MAV_PAYLOAD(msg), len);
#endif
}
