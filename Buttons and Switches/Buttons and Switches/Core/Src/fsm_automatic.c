///*
// * fsm_automatic.c
// *
// *  Created on: Oct 10, 2023
// *      Author: ADMIN
// */
//#include "fsm_automatic.h"
//void fsm_manual_run(){
//	switch(led_status){
//	case MAN_RED:
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin , GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin , GPIO_PIN_SET);
//		if (timer1_flag ==1 ){
//			led_status = AUTO_RED;
//			setTimer1(5000);
//		}
//		if (isButton1Pressed()==1){
//			led_status = MAN_GREEN;
//			setTimer1(10000);	// in MAN_GREEN, after 10 second not press: change to auto
//		}
//		break;
//	case MAN_GREEN:
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin , GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin , GPIO_PIN_SET);
//		if (timer1_flag ==1 ){
//			led_status = AUTO_GREEN;
//			setTimer1(2000);
//		}
//		if (isButton1Pressed()==1){
//			led_status = MAN_YELLOW;
//			setTimer1(10000);
//		}
//		break;
//	case AUTO_YELLOW:
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin , GPIO_PIN_RESET);
//		if (timer1_flag ==1 ){
//			led_status = AUTO_YELLOW;
//			setTimer1(3000);
//		}
//		if (isButton1Pressed()==1){
//			led_status = MAN_RED;
//			setTimer1(10000);
//		}
//		break;
//	default:
//		break;
//	}
//}
//void fsm_automatic_run(){
//	switch(led_status){
//	case INIT:
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin , GPIO_PIN_SET);
//		led_status = AUTO_RED;
//
//		break;
//	case AUTO_RED:
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin , GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin , GPIO_PIN_SET);
//		if (isButton1Pressed()==1){
//			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
//			led_status = AUTO_GREEN;
//		}
//		if (timer1_flag ==1 ){
//			led_status = AUTO_GREEN;
//			setTimer1(5000);
//		}
//
//		break;
//	case AUTO_GREEN:
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin , GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin , GPIO_PIN_SET);
//		if (isButton1Pressed()==1){
//			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
//			led_status = AUTO_YELLOW;
//		}
//		if (timer1_flag ==1 ){
//			led_status = AUTO_YELLOW;
//			setTimer1(2000);
//		}
//		break;
//	case AUTO_YELLOW:
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin , GPIO_PIN_RESET);
//		if (isButton1Pressed()==1){
//			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
//			led_status = AUTO_RED;
//		}
//		if (timer1_flag ==1 ){
//			led_status = AUTO_RED;
//			setTimer1(3000);
//		}
//		break;
//	default:
//		break;
//	}
//};
