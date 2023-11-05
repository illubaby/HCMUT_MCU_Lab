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
void huart_communiation_fsm (){

}

void command_parser_fsm() {
	   // Check if the received command is "!RTS#"
//		if (strcmp((const char *)buffer, "!RTS#") == 0) {
	    if (strstr((const char *)buffer, "!RTS#") != NULL) {
	        // Blink the LED for a specified number of times
			HAL_ADC_Start(&hadc1); // Make sure hadc1 is declared and initialized
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY); // Wait for the conversion to be finished
			HAL_ADC_Stop(&hadc1);
			ADC_value = HAL_ADC_GetValue(&hadc1); // Make sure hadc1 is declared and initialized
			HAL_UART_Transmit (& huart2 , ( void *) str , sprintf (str , "%lu\n", ADC_value ), 1000);

//			int blinks = 5; // Number of blinks
//	        for (int i = 0; i < blinks; i++) {
//	            // Toggle the LED on
//	            HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	            HAL_Delay(500); // Delay for 500 ms (modify this value as needed)
//
//	            // Toggle the LED off
//	            HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	            HAL_Delay(500); // Delay for 500 ms (modify this value as needed)
//	        }
	        // Clear the command buffer or handle it as required
	         memset(buffer, 0, sizeof(buffer));
	         index_buffer = 0;
	    }
}
