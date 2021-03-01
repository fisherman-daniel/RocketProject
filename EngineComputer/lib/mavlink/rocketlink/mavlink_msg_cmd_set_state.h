#pragma once
// MESSAGE CMD_SET_STATE PACKING

#define MAVLINK_MSG_ID_CMD_SET_STATE 64


typedef struct __mavlink_cmd_set_state_t {
 uint8_t cmd; /*<  */
 uint8_t new_state; /*<  for CMD_GOTO_STATE. ignore otherwise*/
} mavlink_cmd_set_state_t;

#define MAVLINK_MSG_ID_CMD_SET_STATE_LEN 2
#define MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN 2
#define MAVLINK_MSG_ID_64_LEN 2
#define MAVLINK_MSG_ID_64_MIN_LEN 2

#define MAVLINK_MSG_ID_CMD_SET_STATE_CRC 222
#define MAVLINK_MSG_ID_64_CRC 222



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CMD_SET_STATE { \
    64, \
    "CMD_SET_STATE", \
    2, \
    {  { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_set_state_t, cmd) }, \
         { "new_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_cmd_set_state_t, new_state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CMD_SET_STATE { \
    "CMD_SET_STATE", \
    2, \
    {  { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cmd_set_state_t, cmd) }, \
         { "new_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_cmd_set_state_t, new_state) }, \
         } \
}
#endif

/**
 * @brief Pack a cmd_set_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cmd  
 * @param new_state  for CMD_GOTO_STATE. ignore otherwise
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_set_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cmd, uint8_t new_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_STATE_LEN];
    _mav_put_uint8_t(buf, 0, cmd);
    _mav_put_uint8_t(buf, 1, new_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_SET_STATE_LEN);
#else
    mavlink_cmd_set_state_t packet;
    packet.cmd = cmd;
    packet.new_state = new_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_SET_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_SET_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_CRC);
}

/**
 * @brief Pack a cmd_set_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd  
 * @param new_state  for CMD_GOTO_STATE. ignore otherwise
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cmd_set_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cmd,uint8_t new_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_STATE_LEN];
    _mav_put_uint8_t(buf, 0, cmd);
    _mav_put_uint8_t(buf, 1, new_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CMD_SET_STATE_LEN);
#else
    mavlink_cmd_set_state_t packet;
    packet.cmd = cmd;
    packet.new_state = new_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CMD_SET_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CMD_SET_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_CRC);
}

/**
 * @brief Encode a cmd_set_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cmd_set_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_set_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cmd_set_state_t* cmd_set_state)
{
    return mavlink_msg_cmd_set_state_pack(system_id, component_id, msg, cmd_set_state->cmd, cmd_set_state->new_state);
}

/**
 * @brief Encode a cmd_set_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_set_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cmd_set_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cmd_set_state_t* cmd_set_state)
{
    return mavlink_msg_cmd_set_state_pack_chan(system_id, component_id, chan, msg, cmd_set_state->cmd, cmd_set_state->new_state);
}

/**
 * @brief Send a cmd_set_state message
 * @param chan MAVLink channel to send the message
 *
 * @param cmd  
 * @param new_state  for CMD_GOTO_STATE. ignore otherwise
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cmd_set_state_send(mavlink_channel_t chan, uint8_t cmd, uint8_t new_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CMD_SET_STATE_LEN];
    _mav_put_uint8_t(buf, 0, cmd);
    _mav_put_uint8_t(buf, 1, new_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_STATE, buf, MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_CRC);
#else
    mavlink_cmd_set_state_t packet;
    packet.cmd = cmd;
    packet.new_state = new_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_STATE, (const char *)&packet, MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_CRC);
#endif
}

/**
 * @brief Send a cmd_set_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cmd_set_state_send_struct(mavlink_channel_t chan, const mavlink_cmd_set_state_t* cmd_set_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cmd_set_state_send(chan, cmd_set_state->cmd, cmd_set_state->new_state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_STATE, (const char *)cmd_set_state, MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_CMD_SET_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cmd_set_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cmd, uint8_t new_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, cmd);
    _mav_put_uint8_t(buf, 1, new_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_STATE, buf, MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_CRC);
#else
    mavlink_cmd_set_state_t *packet = (mavlink_cmd_set_state_t *)msgbuf;
    packet->cmd = cmd;
    packet->new_state = new_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CMD_SET_STATE, (const char *)packet, MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_LEN, MAVLINK_MSG_ID_CMD_SET_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE CMD_SET_STATE UNPACKING


/**
 * @brief Get field cmd from cmd_set_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_cmd_set_state_get_cmd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field new_state from cmd_set_state message
 *
 * @return  for CMD_GOTO_STATE. ignore otherwise
 */
static inline uint8_t mavlink_msg_cmd_set_state_get_new_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a cmd_set_state message into a struct
 *
 * @param msg The message to decode
 * @param cmd_set_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_cmd_set_state_decode(const mavlink_message_t* msg, mavlink_cmd_set_state_t* cmd_set_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cmd_set_state->cmd = mavlink_msg_cmd_set_state_get_cmd(msg);
    cmd_set_state->new_state = mavlink_msg_cmd_set_state_get_new_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CMD_SET_STATE_LEN? msg->len : MAVLINK_MSG_ID_CMD_SET_STATE_LEN;
        memset(cmd_set_state, 0, MAVLINK_MSG_ID_CMD_SET_STATE_LEN);
    memcpy(cmd_set_state, _MAV_PAYLOAD(msg), len);
#endif
}
