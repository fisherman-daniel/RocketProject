/** @file
 *    @brief MAVLink comm protocol testsuite generated from myprotocol.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef MYPROTOCOL_TESTSUITE_H
#define MYPROTOCOL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_myprotocol(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_myprotocol(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_heartbeat_t packet_in = {
        5,72
    };
    mavlink_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.system_type = packet_in.system_type;
        packet1.component_type = packet_in.component_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.system_type , packet1.component_type );
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.system_type , packet1.component_type );
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_send(MAVLINK_COMM_1 , packet1.system_type , packet1.component_type );
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_prep_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PREP_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_prep_cmd_t packet_in = {
        5,72,139
    };
    mavlink_prep_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.message_id = packet_in.message_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PREP_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PREP_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_prep_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_prep_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_prep_cmd_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.message_id );
    mavlink_msg_prep_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_prep_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.message_id );
    mavlink_msg_prep_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_prep_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_prep_cmd_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.message_id );
    mavlink_msg_prep_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ack_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ACK_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ack_cmd_t packet_in = {
        5,72
    };
    mavlink_ack_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.message_id = packet_in.message_id;
        packet1.result = packet_in.result;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ACK_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ACK_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ack_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ack_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ack_cmd_pack(system_id, component_id, &msg , packet1.message_id , packet1.result );
    mavlink_msg_ack_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ack_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.message_id , packet1.result );
    mavlink_msg_ack_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ack_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ack_cmd_send(MAVLINK_COMM_1 , packet1.message_id , packet1.result );
    mavlink_msg_ack_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_request_message(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_request_message_t packet_in = {
        5
    };
    mavlink_cmd_request_message_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.message_id = packet_in.message_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_REQUEST_MESSAGE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_request_message_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_request_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_request_message_pack(system_id, component_id, &msg , packet1.message_id );
    mavlink_msg_cmd_request_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_request_message_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.message_id );
    mavlink_msg_cmd_request_message_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_request_message_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_request_message_send(MAVLINK_COMM_1 , packet1.message_id );
    mavlink_msg_cmd_request_message_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_set_message_interval(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_set_message_interval_t packet_in = {
        17235,139
    };
    mavlink_cmd_set_message_interval_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.interval = packet_in.interval;
        packet1.message_id = packet_in.message_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_SET_MESSAGE_INTERVAL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_message_interval_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_set_message_interval_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_message_interval_pack(system_id, component_id, &msg , packet1.message_id , packet1.interval );
    mavlink_msg_cmd_set_message_interval_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_message_interval_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.message_id , packet1.interval );
    mavlink_msg_cmd_set_message_interval_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_set_message_interval_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_message_interval_send(MAVLINK_COMM_1 , packet1.message_id , packet1.interval );
    mavlink_msg_cmd_set_message_interval_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_engine_sensors(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ENGINE_SENSORS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_engine_sensors_t packet_in = {
        17.0,45.0,73.0,41,108,175,242,53,120,187,254,65,132,199
    };
    mavlink_engine_sensors_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.fuel_injector_pressure = packet_in.fuel_injector_pressure;
        packet1.ox_injector_pressure = packet_in.ox_injector_pressure;
        packet1.thrust = packet_in.thrust;
        packet1.fuel_main_valve_mode = packet_in.fuel_main_valve_mode;
        packet1.fuel_main_valve_position = packet_in.fuel_main_valve_position;
        packet1.fuel_main_valve_desired_position = packet_in.fuel_main_valve_desired_position;
        packet1.fuel_main_valve_motor_power = packet_in.fuel_main_valve_motor_power;
        packet1.ox_main_valve_mode = packet_in.ox_main_valve_mode;
        packet1.ox_main_valve_position = packet_in.ox_main_valve_position;
        packet1.ox_main_valve_desired_position = packet_in.ox_main_valve_desired_position;
        packet1.ox_main_valve_motor_power = packet_in.ox_main_valve_motor_power;
        packet1.fuel_injector_pressure_status = packet_in.fuel_injector_pressure_status;
        packet1.ox_injector_pressure_status = packet_in.ox_injector_pressure_status;
        packet1.ignitor_status = packet_in.ignitor_status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ENGINE_SENSORS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_sensors_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_engine_sensors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_sensors_pack(system_id, component_id, &msg , packet1.fuel_main_valve_mode , packet1.fuel_main_valve_position , packet1.fuel_main_valve_desired_position , packet1.fuel_main_valve_motor_power , packet1.ox_main_valve_mode , packet1.ox_main_valve_position , packet1.ox_main_valve_desired_position , packet1.ox_main_valve_motor_power , packet1.fuel_injector_pressure , packet1.fuel_injector_pressure_status , packet1.ox_injector_pressure , packet1.ox_injector_pressure_status , packet1.thrust , packet1.ignitor_status );
    mavlink_msg_engine_sensors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_sensors_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.fuel_main_valve_mode , packet1.fuel_main_valve_position , packet1.fuel_main_valve_desired_position , packet1.fuel_main_valve_motor_power , packet1.ox_main_valve_mode , packet1.ox_main_valve_position , packet1.ox_main_valve_desired_position , packet1.ox_main_valve_motor_power , packet1.fuel_injector_pressure , packet1.fuel_injector_pressure_status , packet1.ox_injector_pressure , packet1.ox_injector_pressure_status , packet1.thrust , packet1.ignitor_status );
    mavlink_msg_engine_sensors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_engine_sensors_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_sensors_send(MAVLINK_COMM_1 , packet1.fuel_main_valve_mode , packet1.fuel_main_valve_position , packet1.fuel_main_valve_desired_position , packet1.fuel_main_valve_motor_power , packet1.ox_main_valve_mode , packet1.ox_main_valve_position , packet1.ox_main_valve_desired_position , packet1.ox_main_valve_motor_power , packet1.fuel_injector_pressure , packet1.fuel_injector_pressure_status , packet1.ox_injector_pressure , packet1.ox_injector_pressure_status , packet1.thrust , packet1.ignitor_status );
    mavlink_msg_engine_sensors_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tank_sensors(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TANK_SENSORS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tank_sensors_t packet_in = {
        17.0,45.0,29,96,163,230,41,108,175,242,53,120,187,254,65
    };
    mavlink_tank_sensors_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.fuel_tank_pressure = packet_in.fuel_tank_pressure;
        packet1.ox_tank_pressure = packet_in.ox_tank_pressure;
        packet1.fuel_vent_valve_mode = packet_in.fuel_vent_valve_mode;
        packet1.fuel_vent_valve_position = packet_in.fuel_vent_valve_position;
        packet1.fuel_vent_valve_desired_position = packet_in.fuel_vent_valve_desired_position;
        packet1.fuel_vent_valve_motor_power = packet_in.fuel_vent_valve_motor_power;
        packet1.ox_vent_valve_mode = packet_in.ox_vent_valve_mode;
        packet1.ox_vent_valve_position = packet_in.ox_vent_valve_position;
        packet1.ox_vent_valve_desired_position = packet_in.ox_vent_valve_desired_position;
        packet1.ox_vent_valve_motor_power = packet_in.ox_vent_valve_motor_power;
        packet1.fuel_tank_pressure_status = packet_in.fuel_tank_pressure_status;
        packet1.ox_tank_pressure_status = packet_in.ox_tank_pressure_status;
        packet1.fuel_tank_fill_level = packet_in.fuel_tank_fill_level;
        packet1.ox_tank_fill_level = packet_in.ox_tank_fill_level;
        packet1.fill_lines_detected = packet_in.fill_lines_detected;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TANK_SENSORS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tank_sensors_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tank_sensors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tank_sensors_pack(system_id, component_id, &msg , packet1.fuel_vent_valve_mode , packet1.fuel_vent_valve_position , packet1.fuel_vent_valve_desired_position , packet1.fuel_vent_valve_motor_power , packet1.ox_vent_valve_mode , packet1.ox_vent_valve_position , packet1.ox_vent_valve_desired_position , packet1.ox_vent_valve_motor_power , packet1.fuel_tank_pressure , packet1.fuel_tank_pressure_status , packet1.ox_tank_pressure , packet1.ox_tank_pressure_status , packet1.fuel_tank_fill_level , packet1.ox_tank_fill_level , packet1.fill_lines_detected );
    mavlink_msg_tank_sensors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tank_sensors_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.fuel_vent_valve_mode , packet1.fuel_vent_valve_position , packet1.fuel_vent_valve_desired_position , packet1.fuel_vent_valve_motor_power , packet1.ox_vent_valve_mode , packet1.ox_vent_valve_position , packet1.ox_vent_valve_desired_position , packet1.ox_vent_valve_motor_power , packet1.fuel_tank_pressure , packet1.fuel_tank_pressure_status , packet1.ox_tank_pressure , packet1.ox_tank_pressure_status , packet1.fuel_tank_fill_level , packet1.ox_tank_fill_level , packet1.fill_lines_detected );
    mavlink_msg_tank_sensors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tank_sensors_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tank_sensors_send(MAVLINK_COMM_1 , packet1.fuel_vent_valve_mode , packet1.fuel_vent_valve_position , packet1.fuel_vent_valve_desired_position , packet1.fuel_vent_valve_motor_power , packet1.ox_vent_valve_mode , packet1.ox_vent_valve_position , packet1.ox_vent_valve_desired_position , packet1.ox_vent_valve_motor_power , packet1.fuel_tank_pressure , packet1.fuel_tank_pressure_status , packet1.ox_tank_pressure , packet1.ox_tank_pressure_status , packet1.fuel_tank_fill_level , packet1.ox_tank_fill_level , packet1.fill_lines_detected );
    mavlink_msg_tank_sensors_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_power_sensor(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_POWER_SENSOR >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_power_sensor_t packet_in = {
        17235,139,206
    };
    mavlink_power_sensor_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.battery_voltage = packet_in.battery_voltage;
        packet1.power_source = packet_in.power_source;
        packet1.battery_status = packet_in.battery_status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_POWER_SENSOR_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_power_sensor_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_power_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_power_sensor_pack(system_id, component_id, &msg , packet1.power_source , packet1.battery_voltage , packet1.battery_status );
    mavlink_msg_power_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_power_sensor_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.power_source , packet1.battery_voltage , packet1.battery_status );
    mavlink_msg_power_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_power_sensor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_power_sensor_send(MAVLINK_COMM_1 , packet1.power_source , packet1.battery_voltage , packet1.battery_status );
    mavlink_msg_power_sensor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_engine_computer_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_engine_computer_status_t packet_in = {
        17235,139,206,17,84,151
    };
    mavlink_engine_computer_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.abort_flags = packet_in.abort_flags;
        packet1.state = packet_in.state;
        packet1.state_proceed = packet_in.state_proceed;
        packet1.state_abort = packet_in.state_abort;
        packet1.arm_state = packet_in.arm_state;
        packet1.cpu_load = packet_in.cpu_load;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ENGINE_COMPUTER_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_computer_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_engine_computer_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_computer_status_pack(system_id, component_id, &msg , packet1.state , packet1.state_proceed , packet1.state_abort , packet1.abort_flags , packet1.arm_state , packet1.cpu_load );
    mavlink_msg_engine_computer_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_computer_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.state , packet1.state_proceed , packet1.state_abort , packet1.abort_flags , packet1.arm_state , packet1.cpu_load );
    mavlink_msg_engine_computer_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_engine_computer_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_computer_status_send(MAVLINK_COMM_1 , packet1.state , packet1.state_proceed , packet1.state_abort , packet1.abort_flags , packet1.arm_state , packet1.cpu_load );
    mavlink_msg_engine_computer_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_abort(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_ABORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_abort_t packet_in = {
        5
    };
    mavlink_cmd_abort_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.hard = packet_in.hard;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_ABORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_abort_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_abort_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_abort_pack(system_id, component_id, &msg , packet1.hard );
    mavlink_msg_cmd_abort_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_abort_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.hard );
    mavlink_msg_cmd_abort_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_abort_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_abort_send(MAVLINK_COMM_1 , packet1.hard );
    mavlink_msg_cmd_abort_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_goto_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_GOTO_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_goto_state_t packet_in = {
        5
    };
    mavlink_cmd_goto_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.state = packet_in.state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_GOTO_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_GOTO_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_goto_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_goto_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_goto_state_pack(system_id, component_id, &msg , packet1.state );
    mavlink_msg_cmd_goto_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_goto_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.state );
    mavlink_msg_cmd_goto_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_goto_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_goto_state_send(MAVLINK_COMM_1 , packet1.state );
    mavlink_msg_cmd_goto_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_proceed(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_PROCEED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_proceed_t packet_in = {
        
    };
    mavlink_cmd_proceed_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_PROCEED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_proceed_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_proceed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_proceed_pack(system_id, component_id, &msg );
    mavlink_msg_cmd_proceed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_proceed_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg );
    mavlink_msg_cmd_proceed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_proceed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_proceed_send(MAVLINK_COMM_1 );
    mavlink_msg_cmd_proceed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_set_valve(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_SET_VALVE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_set_valve_t packet_in = {
        5,72,139
    };
    mavlink_cmd_set_valve_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.valve = packet_in.valve;
        packet1.valve_mode = packet_in.valve_mode;
        packet1.desired_position = packet_in.desired_position;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_SET_VALVE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_valve_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_set_valve_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_valve_pack(system_id, component_id, &msg , packet1.valve , packet1.valve_mode , packet1.desired_position );
    mavlink_msg_cmd_set_valve_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_valve_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.valve , packet1.valve_mode , packet1.desired_position );
    mavlink_msg_cmd_set_valve_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_set_valve_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_valve_send(MAVLINK_COMM_1 , packet1.valve , packet1.valve_mode , packet1.desired_position );
    mavlink_msg_cmd_set_valve_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_set_power_source(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_set_power_source_t packet_in = {
        5
    };
    mavlink_cmd_set_power_source_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.power_source = packet_in.power_source;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_SET_POWER_SOURCE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_power_source_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_set_power_source_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_power_source_pack(system_id, component_id, &msg , packet1.power_source );
    mavlink_msg_cmd_set_power_source_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_power_source_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.power_source );
    mavlink_msg_cmd_set_power_source_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_set_power_source_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_power_source_send(MAVLINK_COMM_1 , packet1.power_source );
    mavlink_msg_cmd_set_power_source_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_set_arm_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SET_ARM_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_set_arm_state_t packet_in = {
        5
    };
    mavlink_set_arm_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.arm_state = packet_in.arm_state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SET_ARM_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SET_ARM_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_arm_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_set_arm_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_arm_state_pack(system_id, component_id, &msg , packet1.arm_state );
    mavlink_msg_set_arm_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_arm_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.arm_state );
    mavlink_msg_set_arm_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_set_arm_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_arm_state_send(MAVLINK_COMM_1 , packet1.arm_state );
    mavlink_msg_set_arm_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_myprotocol(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_heartbeat(system_id, component_id, last_msg);
    mavlink_test_prep_cmd(system_id, component_id, last_msg);
    mavlink_test_ack_cmd(system_id, component_id, last_msg);
    mavlink_test_cmd_request_message(system_id, component_id, last_msg);
    mavlink_test_cmd_set_message_interval(system_id, component_id, last_msg);
    mavlink_test_engine_sensors(system_id, component_id, last_msg);
    mavlink_test_tank_sensors(system_id, component_id, last_msg);
    mavlink_test_power_sensor(system_id, component_id, last_msg);
    mavlink_test_engine_computer_status(system_id, component_id, last_msg);
    mavlink_test_cmd_abort(system_id, component_id, last_msg);
    mavlink_test_cmd_goto_state(system_id, component_id, last_msg);
    mavlink_test_cmd_proceed(system_id, component_id, last_msg);
    mavlink_test_cmd_set_valve(system_id, component_id, last_msg);
    mavlink_test_cmd_set_power_source(system_id, component_id, last_msg);
    mavlink_test_set_arm_state(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MYPROTOCOL_TESTSUITE_H
