/*
 * fsm.h
 *
 *  Created on: Nov 5, 2023
 *      Author: ADMIN
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_
#include "main.h"
#define MAX_BUFFER_SIZE 30
#define INIT 	1
#define INFO	2
#define END 3
extern int state;
extern uint8_t buffer[MAX_BUFFER_SIZE]; // Use the same size as declared in main.c
extern uint8_t index_buffer;
extern uint32_t ADC_value ;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
extern char str[32];

void command_parser_fsm ();

void huart_communiation_fsm ();

#endif /* INC_FSM_H_ */
