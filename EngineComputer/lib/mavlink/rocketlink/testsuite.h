/** @file
 *    @brief MAVLink comm protocol testsuite generated from rocketlink.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef ROCKETLINK_TESTSUITE_H
#define ROCKETLINK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_rocketlink(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_rocketlink(system_id, component_id, last_msg);
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
        5
    };
    mavlink_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.nothin = packet_in.nothin;
        
        
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
    mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.nothin );
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.nothin );
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
    mavlink_msg_heartbeat_send(MAVLINK_COMM_1 , packet1.nothin );
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_pre_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PRE_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pre_cmd_t packet_in = {
        5
    };
    mavlink_pre_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.message_id = packet_in.message_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PRE_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PRE_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pre_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pre_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pre_cmd_pack(system_id, component_id, &msg , packet1.message_id );
    mavlink_msg_pre_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pre_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.message_id );
    mavlink_msg_pre_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pre_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pre_cmd_send(MAVLINK_COMM_1 , packet1.message_id );
    mavlink_msg_pre_cmd_decode(last_msg, &packet2);
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
        17235,17339,17,84,151,218,29,96
    };
    mavlink_engine_computer_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.voltage = packet_in.voltage;
        packet1.state = packet_in.state;
        packet1.state_proceed = packet_in.state_proceed;
        packet1.state_abort = packet_in.state_abort;
        packet1.abort_flags = packet_in.abort_flags;
        packet1.cpu_load = packet_in.cpu_load;
        packet1.power_source = packet_in.power_source;
        
        
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
    mavlink_msg_engine_computer_status_pack(system_id, component_id, &msg , packet1.state , packet1.state_proceed , packet1.state_abort , packet1.time , packet1.abort_flags , packet1.cpu_load , packet1.power_source , packet1.voltage );
    mavlink_msg_engine_computer_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_computer_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.state , packet1.state_proceed , packet1.state_abort , packet1.time , packet1.abort_flags , packet1.cpu_load , packet1.power_source , packet1.voltage );
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
    mavlink_msg_engine_computer_status_send(MAVLINK_COMM_1 , packet1.state , packet1.state_proceed , packet1.state_abort , packet1.time , packet1.abort_flags , packet1.cpu_load , packet1.power_source , packet1.voltage );
    mavlink_msg_engine_computer_status_decode(last_msg, &packet2);
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
        17235,17339,17443,151,218,29,96,163,230,41,108,175
    };
    mavlink_engine_sensors_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.fuel_injector_pressure = packet_in.fuel_injector_pressure;
        packet1.ox_injector_pressure = packet_in.ox_injector_pressure;
        packet1.thrust = packet_in.thrust;
        packet1.fuel_main_valve_status = packet_in.fuel_main_valve_status;
        packet1.fuel_main_valve_position = packet_in.fuel_main_valve_position;
        packet1.fuel_main_valve_goal_position = packet_in.fuel_main_valve_goal_position;
        packet1.fuel_main_valve_motor_power = packet_in.fuel_main_valve_motor_power;
        packet1.ox_main_valve_status = packet_in.ox_main_valve_status;
        packet1.ox_main_valve_position = packet_in.ox_main_valve_position;
        packet1.ox_main_valve_goal_position = packet_in.ox_main_valve_goal_position;
        packet1.ox_main_valve_motor_power = packet_in.ox_main_valve_motor_power;
        packet1.ignitor_flags = packet_in.ignitor_flags;
        
        
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
    mavlink_msg_engine_sensors_pack(system_id, component_id, &msg , packet1.fuel_main_valve_status , packet1.fuel_main_valve_position , packet1.fuel_main_valve_goal_position , packet1.fuel_main_valve_motor_power , packet1.ox_main_valve_status , packet1.ox_main_valve_position , packet1.ox_main_valve_goal_position , packet1.ox_main_valve_motor_power , packet1.fuel_injector_pressure , packet1.ox_injector_pressure , packet1.thrust , packet1.ignitor_flags );
    mavlink_msg_engine_sensors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_engine_sensors_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.fuel_main_valve_status , packet1.fuel_main_valve_position , packet1.fuel_main_valve_goal_position , packet1.fuel_main_valve_motor_power , packet1.ox_main_valve_status , packet1.ox_main_valve_position , packet1.ox_main_valve_goal_position , packet1.ox_main_valve_motor_power , packet1.fuel_injector_pressure , packet1.ox_injector_pressure , packet1.thrust , packet1.ignitor_flags );
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
    mavlink_msg_engine_sensors_send(MAVLINK_COMM_1 , packet1.fuel_main_valve_status , packet1.fuel_main_valve_position , packet1.fuel_main_valve_goal_position , packet1.fuel_main_valve_motor_power , packet1.ox_main_valve_status , packet1.ox_main_valve_position , packet1.ox_main_valve_goal_position , packet1.ox_main_valve_motor_power , packet1.fuel_injector_pressure , packet1.ox_injector_pressure , packet1.thrust , packet1.ignitor_flags );
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
        17235,17339,17,84,151,218,29,96,163,230,41,108,175
    };
    mavlink_tank_sensors_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.fuel_tank_pressure = packet_in.fuel_tank_pressure;
        packet1.ox_tank_pressure = packet_in.ox_tank_pressure;
        packet1.fuel_vent_valve_status = packet_in.fuel_vent_valve_status;
        packet1.fuel_vent_valve_position = packet_in.fuel_vent_valve_position;
        packet1.fuel_vent_valve_goal_position = packet_in.fuel_vent_valve_goal_position;
        packet1.fuel_vent_valve_motor_power = packet_in.fuel_vent_valve_motor_power;
        packet1.ox_vent_valve_status = packet_in.ox_vent_valve_status;
        packet1.ox_vent_valve_position = packet_in.ox_vent_valve_position;
        packet1.ox_vent_valve_goal_position = packet_in.ox_vent_valve_goal_position;
        packet1.ox_vent_valve_motor_power = packet_in.ox_vent_valve_motor_power;
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
    mavlink_msg_tank_sensors_pack(system_id, component_id, &msg , packet1.fuel_vent_valve_status , packet1.fuel_vent_valve_position , packet1.fuel_vent_valve_goal_position , packet1.fuel_vent_valve_motor_power , packet1.ox_vent_valve_status , packet1.ox_vent_valve_position , packet1.ox_vent_valve_goal_position , packet1.ox_vent_valve_motor_power , packet1.fuel_tank_pressure , packet1.ox_tank_pressure , packet1.fuel_tank_fill_level , packet1.ox_tank_fill_level , packet1.fill_lines_detected );
    mavlink_msg_tank_sensors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tank_sensors_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.fuel_vent_valve_status , packet1.fuel_vent_valve_position , packet1.fuel_vent_valve_goal_position , packet1.fuel_vent_valve_motor_power , packet1.ox_vent_valve_status , packet1.ox_vent_valve_position , packet1.ox_vent_valve_goal_position , packet1.ox_vent_valve_motor_power , packet1.fuel_tank_pressure , packet1.ox_tank_pressure , packet1.fuel_tank_fill_level , packet1.ox_tank_fill_level , packet1.fill_lines_detected );
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
    mavlink_msg_tank_sensors_send(MAVLINK_COMM_1 , packet1.fuel_vent_valve_status , packet1.fuel_vent_valve_position , packet1.fuel_vent_valve_goal_position , packet1.fuel_vent_valve_motor_power , packet1.ox_vent_valve_status , packet1.ox_vent_valve_position , packet1.ox_vent_valve_goal_position , packet1.ox_vent_valve_motor_power , packet1.fuel_tank_pressure , packet1.ox_tank_pressure , packet1.fuel_tank_fill_level , packet1.ox_tank_fill_level , packet1.fill_lines_detected );
    mavlink_msg_tank_sensors_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cmd_set_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CMD_SET_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cmd_set_state_t packet_in = {
        5,72
    };
    mavlink_cmd_set_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cmd = packet_in.cmd;
        packet1.new_state = packet_in.new_state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CMD_SET_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cmd_set_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_state_pack(system_id, component_id, &msg , packet1.cmd , packet1.new_state );
    mavlink_msg_cmd_set_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cmd , packet1.new_state );
    mavlink_msg_cmd_set_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cmd_set_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_state_send(MAVLINK_COMM_1 , packet1.cmd , packet1.new_state );
    mavlink_msg_cmd_set_state_decode(last_msg, &packet2);
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
        17235,139,206,17
    };
    mavlink_cmd_set_valve_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pulse_duration = packet_in.pulse_duration;
        packet1.valve = packet_in.valve;
        packet1.cmd = packet_in.cmd;
        packet1.goal_position = packet_in.goal_position;
        
        
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
    mavlink_msg_cmd_set_valve_pack(system_id, component_id, &msg , packet1.valve , packet1.cmd , packet1.goal_position , packet1.pulse_duration );
    mavlink_msg_cmd_set_valve_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cmd_set_valve_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.valve , packet1.cmd , packet1.goal_position , packet1.pulse_duration );
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
    mavlink_msg_cmd_set_valve_send(MAVLINK_COMM_1 , packet1.valve , packet1.cmd , packet1.goal_position , packet1.pulse_duration );
    mavlink_msg_cmd_set_valve_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_rocketlink(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_heartbeat(system_id, component_id, last_msg);
    mavlink_test_pre_cmd(system_id, component_id, last_msg);
    mavlink_test_ack_cmd(system_id, component_id, last_msg);
    mavlink_test_engine_computer_status(system_id, component_id, last_msg);
    mavlink_test_engine_sensors(system_id, component_id, last_msg);
    mavlink_test_tank_sensors(system_id, component_id, last_msg);
    mavlink_test_cmd_set_state(system_id, component_id, last_msg);
    mavlink_test_cmd_set_valve(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ROCKETLINK_TESTSUITE_H
