///*
// * Comm_Bus.c
// *
// *  Created on: May 4, 2025
// *      Author: Asteroid
// */
//#include "main.h"
//#include "CommBus.h"
//#include "servo.h"
//#include "motor.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//#define RX_BUFFER_SIZE	256
//#define TX_BUFFER_SIZE	256
//
//static UART_HandleTypeDef *CommBus_huart;
//
//static uint8_t comm_enabled = 1;
//
//
//static char rx_buffer[RX_BUFFER_SIZE];
//static uint16_t rx_index = 0;
//static uint8_t message_ready = 0;
//static uint8_t rx_byte;
//
//static char tx_buffer[TX_BUFFER_SIZE];
//
//CommBus_THM_Detected THM_Decision = THM_EMPTY;
//
//static int servo_angle = 90;
//#define SERVO_ANGLE_MIN 0
//#define SERVO_ANGLE_MAX 180
//#define SERVO_ANGLE_STEP 1
//
//#define DRIVE_SPEED	400
//#define DRIVE_DELAY	100
//
//void CommBus_Init(UART_HandleTypeDef *huart){
//	CommBus_huart = huart;
//	rx_index = 0;
//	message_ready = 0;
//	THM_Decision = THM_EMPTY;
//
//	HAL_UART_Receive_IT(CommBus_huart, &rx_byte, 1);
//}
//
//
//
//static void CommBus_ProcessByte(uint8_t byte){
////	if(message_ready)	return;
//
//	if (byte == '\n'){
//		rx_buffer[rx_index] = '\0';
//		message_ready = 1;
//		rx_index = 0;
//	}
//	else {
//		rx_buffer[rx_index++] = byte;
//
//		if(rx_index >= RX_BUFFER_SIZE){
//			rx_index = 0;
//		}
//	}
//
//}
//
//void CommBus_RxHandler(void){
//
//    if (!comm_enabled) {
//        // Re-arm RX even if disabled, to avoid getting stuck
//        HAL_UART_Receive_IT(CommBus_huart, &rx_byte, 1);
//        return;
//    }
//
//	CommBus_ProcessByte(rx_byte);
//    HAL_UART_Receive_IT(CommBus_huart, &rx_byte, 1);
//}
//
//uint8_t CommBus_MessageAvailable(void){
//	return message_ready;
//}
//
//char* CommBus_GetMessage(void){
//	return rx_buffer;
//}
//
//CommBus_MessageType CommBus_GetMessageType(char *msg){
//	CommBus_MessageType message_type;
//
//	if(msg[0] == 'G' && msg[1] == 'P' && msg[2] == 'S' && msg[3] == ':'){
//		message_type = GPS;
//	}
//	else if (msg[0] == 'U' && msg[1] == 'L' && msg[2] == 'T' && msg[3] == ':'){
//		message_type = ULT;
//	}
//	else if (msg[0] == 'T' && msg[1] == 'H' && msg[2] == 'M' && msg[3] == ':'){
//		message_type = THM;
//	}
//	else if (msg[0] == 'P' && msg[1] == 'I' && msg[2] == 'R' && msg[3] == ':'){
//		message_type = PIR;
//	}
//	else if (msg[0] == 'D' && msg[1] == 'R' && msg[2] == 'V' && msg[3] == ':'){
//		message_type = DRV;
//	}
//	else if (msg[0] == 'S' && msg[1] == 'R' && msg[2] == 'V' && msg[3] == ':'){
//		message_type = SRV;
//	}
//	else {
//		message_type = UNKNOWN;
//	}
//
//	return message_type;
//}
//
//char* CommBus_GetPayload(char *msg){
////	char* colon = strchr(msg, ':');
////	if(colon != NULL){
////		return colon + 1;
////	}
////	else {
////		return "";
////	}
//	char* colon = strchr(msg, ':');
//	if (colon != NULL) {
//	    char* payload = colon + 1;
//
//	    // Remove trailing \r or \n
//	    char* end = payload + strlen(payload) - 1;
//	    while (end > payload && (*end == '\n' || *end == '\r')) {
//	        *end-- = '\0';
//	    }
//
//	    return payload;
//	}
//	return "";
//}
//
//void CommBus_SendMessage(CommBus_MessageType type, const char* payload){
//	char* msg_type;
//	switch(type){
//		case GPS:
//			msg_type = "GPS";
//		break;
//		case ULT:
//			msg_type = "ULT";
//		break;
//		case PIR:
//			msg_type = "PIR";
//		break;
//		default:
//			msg_type = "UNKNOWN";
//	}
//
//	snprintf(tx_buffer, TX_BUFFER_SIZE, "%s:%s\n", msg_type, payload);
//	HAL_UART_Transmit(CommBus_huart, (uint8_t*)tx_buffer, strlen(tx_buffer), HAL_MAX_DELAY);
//}
//
//
//void CommBus_ResetMessageReady(){
//	message_ready = 0;
//	rx_index = 0;
//}
//
//
//void CommBus_ParseTHM(char* payload){
//	switch (atoi(payload)){
//	case 0:
//		LOG_UART("PARSE 0\r\n");
//		THM_Decision = THM_HUM_NOT_DETECTED;
//		break;
//	case 1:
//		LOG_UART("PARSE 1\r\n");
//		THM_Decision = THM_HUM_DETECTED;
//		break;
//	}
//}
//
//void CommBus_ResetTHMDecision(){
//	THM_Decision = THM_HUM_NOT_DETECTED;
//}
//
//
//void CommBus_ParseDRV(char* payload){
//	if (strcmp(payload, "F") == 0){
////		Rover_DriveForward();  // implement this
//		Stepper_MoveForward(DRIVE_SPEED);
//		HAL_Delay(DRIVE_DELAY);
//		Stepper_Stop();
//	}
//	else if (strcmp(payload, "B") == 0){
////		Rover_DriveBackward();
//		Stepper_MoveBackward(DRIVE_SPEED);
//		HAL_Delay(DRIVE_DELAY);
//		Stepper_Stop();
//	}
//	else if (strcmp(payload, "L") == 0){
////		Rover_TurnLeft();
//		Stepper_TurnLeft(DRIVE_SPEED);
//		HAL_Delay(DRIVE_DELAY);
//		Stepper_Stop();
//	}
//	else if (strcmp(payload, "R") == 0){
////		Rover_TurnRight();
//		Stepper_TurnRight(DRIVE_SPEED);
//		HAL_Delay(DRIVE_DELAY);
//		Stepper_Stop();
//	}
//}
//
//void CommBus_ParseSRV(char* payload){
//	if (strcmp(payload, "L") == 0 && servo_angle > SERVO_ANGLE_MIN) {
//		servo_angle -= SERVO_ANGLE_STEP;
//	}
//	else if (strcmp(payload, "R") == 0 && servo_angle < SERVO_ANGLE_MAX) {
//		servo_angle += SERVO_ANGLE_STEP;
//	}
//	Servo_SetAngle(servo_angle);  // adjust to your actual camera servo API
//}
//
///* To call in main.c */
//void CommBus_HandleIncoming(){
//	if(!CommBus_MessageAvailable())	return;
//
//	char *msg = CommBus_GetMessage();
//	CommBus_MessageType type = CommBus_GetMessageType(msg);
//
//	LOG_UART("[RAW] ");
//	LOG_UART(msg);
//	LOG_UART("\r\n");
//
//
//
//	char *payload = CommBus_GetPayload(msg);
//	LOG_UART("[PAYLOAD] ");
//	LOG_UART(payload);
//	LOG_UART("\r\n");
//
//
//
//	LOG_UART("[ATOI] ");
//	if(atoi(payload) == 1){
//		LOG_UART("ONE");
//	}
//	else if (atoi(payload) == 0){
//		LOG_UART("ZERO");
//	}
//	else {
//		LOG_UART("ELSE");
//	}
//	LOG_UART("\r\n");
//
//
//
//	switch (type){
//		case THM:
//			CommBus_ParseTHM(payload);
//			break;
//		case DRV:
//			CommBus_ParseDRV(payload);
//			break;
//		case SRV:
//			CommBus_ParseSRV(payload);
//			break;
//		default:
//			HAL_UART_Transmit(CommBus_huart, (uint8_t*)"[WARN] Unsupported msg type\r\n", 30, HAL_MAX_DELAY);
//			break;
//	}
//
//	CommBus_ResetMessageReady();
//
//}
//
//void CommBus_Enable(void){
//    comm_enabled = 1;
//}
//
//void CommBus_Disable(void){
//    comm_enabled = 0;
//}
//
