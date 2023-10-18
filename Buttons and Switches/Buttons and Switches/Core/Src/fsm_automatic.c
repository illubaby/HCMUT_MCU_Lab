/*
 * fsm_automatic.c
 *
 *  Created on: Oct 10, 2023
 *      Author: ADMIN
 */
#include "fsm_automatic.h"
#include "main.h"
void fsm_automatic_run(){
	switch(led_status){
	case INIT:
//		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
		if (isButtonPressed(0)==1){
			led_status = AUTO_RED;
		}

		break;
	case AUTO_RED:
		if (isButtonPressed(0)==1){
			led_status = AUTO_YELLOW;
		}
			if (timer_flag[0] == 1 ){
				HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
				HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
				setTimer(0,500);
			}
		break;
	   case AUTO_YELLOW:

	        if (isButtonPressed(0) == 1) {
	            led_status = AUTO_GREEN;
	        }
	        if (timer_flag[0] ==1) {
//				HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
//				HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	            HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
	            setTimer(0,500);
	        }

	        break;
	    case AUTO_GREEN:

	        if (isButtonPressed(0) == 1) {
	            led_status = INIT;
	        }
	        if (timer_flag[0] ==1) {
//				HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
//				HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	            HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	            setTimer(0,500);
	        }

	        break;
	default:
		break;
	}
}
