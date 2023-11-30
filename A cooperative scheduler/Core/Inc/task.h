/*
 * task.h
 *
 *  Created on: Nov 29, 2023
 *      Author: ADMIN
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_
#include "fsm.h"

void task1(){
	HAL_GPIO_TogglePin(TEST_GPIO_Port,TEST_Pin);
}
void task2(){// print the delay time
	HAL_GPIO_TogglePin(TASK2_GPIO_Port,TASK2_Pin);
}
void task3(){
	HAL_GPIO_TogglePin(TASK3_GPIO_Port,TASK3_Pin);
}
void task4(){
	uart_communiation_fsm();
}
void task5(){
		  if( buffer_flag == 1){
			  buffer_flag = 0;
			  command_parser_fsm ();
		  }
}

#endif /* INC_TASK_H_ */
