/*
 * task.h
 *
 *  Created on: Nov 29, 2023
 *      Author: ADMIN
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_


void task1(){
	HAL_GPIO_TogglePin(TEST_GPIO_Port,TEST_Pin);
}
void task2(){// print the delay time
	HAL_GPIO_TogglePin(TASK2_GPIO_Port,TASK2_Pin);
}

#endif /* INC_TASK_H_ */
