#pragma once
// MESSAGE POWER_SENSOR PACKING

#define MAVLINK_MSG_ID_POWER_SENSOR 34


typedef struct __mavlink_power_sensor_t {
 uint16_t battery_voltage; /*< [mV] Battery voltage*/
 uint8_t power_source; /*<  Battery or external supply*/
 uint8_t battery_status; /*<  */
} mavlink_power_sensor_t;

#define MAVLINK_MSG_ID_POWER_SENSOR_LEN 4
#define MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN 4
#define MAVLINK_MSG_ID_34_LEN 4
#define MAVLINK_MSG_ID_34_MIN_LEN 4

#define MAVLINK_MSG_ID_POWER_SENSOR_CRC 208
#define MAVLINK_MSG_ID_34_CRC 208



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_POWER_SENSOR { \
    34, \
    "POWER_SENSOR", \
    3, \
    {  { "power_source", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_power_sensor_t, power_source) }, \
         { "battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_power_sensor_t, battery_voltage) }, \
         { "battery_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_power_sensor_t, battery_status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_POWER_SENSOR { \
    "POWER_SENSOR", \
    3, \
    {  { "power_source", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_power_sensor_t, power_source) }, \
         { "battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_power_sensor_t, battery_voltage) }, \
         { "battery_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_power_sensor_t, battery_status) }, \
         } \
}
#endif

/**
 * @brief Pack a power_sensor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param power_source  Battery or external supply
 * @param battery_voltage [mV] Battery voltage
 * @param battery_status  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_power_sensor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t power_source, uint16_t battery_voltage, uint8_t battery_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POWER_SENSOR_LEN];
    _mav_put_uint16_t(buf, 0, battery_voltage);
    _mav_put_uint8_t(buf, 2, power_source);
    _mav_put_uint8_t(buf, 3, battery_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POWER_SENSOR_LEN);
#else
    mavlink_power_sensor_t packet;
    packet.battery_voltage = battery_voltage;
    packet.power_source = power_source;
    packet.battery_status = battery_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POWER_SENSOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POWER_SENSOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN, MAVLINK_MSG_ID_POWER_SENSOR_LEN, MAVLINK_MSG_ID_POWER_SENSOR_CRC);
}

/**
 * @brief Pack a power_sensor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param power_source  Battery or external supply
 * @param battery_voltage [mV] Battery voltage
 * @param battery_status  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_power_sensor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t power_source,uint16_t battery_voltage,uint8_t battery_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POWER_SENSOR_LEN];
    _mav_put_uint16_t(buf, 0, battery_voltage);
    _mav_put_uint8_t(buf, 2, power_source);
    _mav_put_uint8_t(buf, 3, battery_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POWER_SENSOR_LEN);
#else
    mavlink_power_sensor_t packet;
    packet.battery_voltage = battery_voltage;
    packet.power_source = power_source;
    packet.battery_status = battery_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POWER_SENSOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POWER_SENSOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN, MAVLINK_MSG_ID_POWER_SENSOR_LEN, MAVLINK_MSG_ID_POWER_SENSOR_CRC);
}

/**
 * @brief Encode a power_sensor struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param power_sensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_power_sensor_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_power_sensor_t* power_sensor)
{
    return mavlink_msg_power_sensor_pack(system_id, component_id, msg, power_sensor->power_source, power_sensor->battery_voltage, power_sensor->battery_status);
}

/**
 * @brief Encode a power_sensor struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param power_sensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_power_sensor_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_power_sensor_t* power_sensor)
{
    return mavlink_msg_power_sensor_pack_chan(system_id, component_id, chan, msg, power_sensor->power_source, power_sensor->battery_voltage, power_sensor->battery_status);
}

/**
 * @brief Send a power_sensor message
 * @param chan MAVLink channel to send the message
 *
 * @param power_source  Battery or external supply
 * @param battery_voltage [mV] Battery voltage
 * @param battery_status  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_power_sensor_send(mavlink_channel_t chan, uint8_t power_source, uint16_t battery_voltage, uint8_t battery_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POWER_SENSOR_LEN];
    _mav_put_uint16_t(buf, 0, battery_voltage);
    _mav_put_uint8_t(buf, 2, power_source);
    _mav_put_uint8_t(buf, 3, battery_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POWER_SENSOR, buf, MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN, MAVLINK_MSG_ID_POWER_SENSOR_LEN, MAVLINK_MSG_ID_POWER_SENSOR_CRC);
#else
    mavlink_power_sensor_t packet;
    packet.battery_voltage = battery_voltage;
    packet.power_source = power_source;
    packet.battery_status = battery_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POWER_SENSOR, (const char *)&packet, MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN, MAVLINK_MSG_ID_POWER_SENSOR_LEN, MAVLINK_MSG_ID_POWER_SENSOR_CRC);
#endif
}

/**
 * @brief Send a power_sensor message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_power_sensor_send_struct(mavlink_channel_t chan, const mavlink_power_sensor_t* power_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_power_sensor_send(chan, power_sensor->power_source, power_sensor->battery_voltage, power_sensor->battery_status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POWER_SENSOR, (const char *)power_sensor, MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN, MAVLINK_MSG_ID_POWER_SENSOR_LEN, MAVLINK_MSG_ID_POWER_SENSOR_CRC);
#endif
}

#if MAVLINK_MSG_ID_POWER_SENSOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_power_sensor_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t power_source, uint16_t battery_voltage, uint8_t battery_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, battery_voltage);
    _mav_put_uint8_t(buf, 2, power_source);
    _mav_put_uint8_t(buf, 3, battery_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POWER_SENSOR, buf, MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN, MAVLINK_MSG_ID_POWER_SENSOR_LEN, MAVLINK_MSG_ID_POWER_SENSOR_CRC);
#else
    mavlink_power_sensor_t *packet = (mavlink_power_sensor_t *)msgbuf;
    packet->battery_voltage = battery_voltage;
    packet->power_source = power_source;
    packet->battery_status = battery_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POWER_SENSOR, (const char *)packet, MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN, MAVLINK_MSG_ID_POWER_SENSOR_LEN, MAVLINK_MSG_ID_POWER_SENSOR_CRC);
#endif
}
#endif

#endif

// MESSAGE POWER_SENSOR UNPACKING


/**
 * @brief Get field power_source from power_sensor message
 *
 * @return  Battery or external supply
 */
static inline uint8_t mavlink_msg_power_sensor_get_power_source(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field battery_voltage from power_sensor message
 *
 * @return [mV] Battery voltage
 */
static inline uint16_t mavlink_msg_power_sensor_get_battery_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field battery_status from power_sensor message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_power_sensor_get_battery_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a power_sensor message into a struct
 *
 * @param msg The message to decode
 * @param power_sensor C-struct to decode the message contents into
 */
static inline void mavlink_msg_power_sensor_decode(const mavlink_message_t* msg, mavlink_power_sensor_t* power_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    power_sensor->battery_voltage = mavlink_msg_power_sensor_get_battery_voltage(msg);
    power_sensor->power_source = mavlink_msg_power_sensor_get_power_source(msg);
    power_sensor->battery_status = mavlink_msg_power_sensor_get_battery_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_POWER_SENSOR_LEN? msg->len : MAVLINK_MSG_ID_POWER_SENSOR_LEN;
        memset(power_sensor, 0, MAVLINK_MSG_ID_POWER_SENSOR_LEN);
    memcpy(power_sensor, _MAV_PAYLOAD(msg), len);
#endif
}
