/*
 * fsm.c
 *
 *  Created on: Nov 5, 2023
 *      Author: ADMIN
 */
#include "main.h"
#include "fsm.h"
#include "string.h"
#include "stdio.h"
int command_flag = 0;
int state = 0 ;
char command_data[MAX_BUFFER_SIZE];

void command_parser_fsm() {
	    if (strstr((const char *)buffer, "!RST#") != NULL) {
	    	state = INFO;
	    }
	    else if (strstr((const char *)buffer, "!OK#") != NULL) {
	    	state = INIT;
	    }
}

void uart_communiation_fsm (){
	switch(state){
	case INIT:
		break;
	case INFO:
		HAL_ADC_Start(&hadc1); // Make sure hadc1 is declared and initialized
		HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY); // Wait for the conversion to be finished
		HAL_ADC_Stop(&hadc1);
		ADC_value = HAL_ADC_GetValue(&hadc1); // Make sure hadc1 is declared and initialized

		int len = sprintf(str," !ADC=%lu# \r\n",ADC_value); // the total number of character
		HAL_UART_Transmit (& huart2 , ( void *) str , len, 1000);

        // Clear the command buffer or handle it as required
         memset(buffer, 0, sizeof(buffer));
         index_buffer = 0;

         HAL_Delay(1000);
		break;
	default:
		break;
	}


}
