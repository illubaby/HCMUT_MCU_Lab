/*
 * 7_SEG_Display.c
 *
 *  Created on: Oct 13, 2023
 *      Author: ADMIN
 */

#include "main.h"

void display7SEG(int num,
        GPIO_TypeDef* a_GPIO_Port, uint16_t a_Pin,
        GPIO_TypeDef* b_GPIO_Port, uint16_t b_Pin,
        GPIO_TypeDef* c_GPIO_Port, uint16_t c_Pin,
        GPIO_TypeDef* d_GPIO_Port, uint16_t d_Pin,
        GPIO_TypeDef* e_GPIO_Port, uint16_t e_Pin,
        GPIO_TypeDef* f_GPIO_Port, uint16_t f_Pin,
        GPIO_TypeDef* g_GPIO_Port, uint16_t g_Pin) {
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);

	switch(num) {
		case 0:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
		break;
		case 1:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
		// (Add the rest of the pins needed to display '1')
		break;
		case 2:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
		break;
		case 3:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
		break;
		case 4:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
		break;
		case 5:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
		break;
		case 6:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
		break;
		case 7:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
		break;
		case 8:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
		break;
		case 9:
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
		break;
		default:
		// Handle invalid input by possibly clearing all segments or displaying a predefined error state
		break;
	}
	return;
}
int led_buffer[2];
int index_led;
int MAX_LED = 2;
void update7SEG(int index){
	if(index_led>MAX_LED) index_led = (index_led + 1) % MAX_LED;
    switch (index){
        case 0:
            //Display the first 7SEG with led_buffer[0]
    		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
    		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
    		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
    		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
    		display7SEG(5, a1_GPIO_Port, a1_Pin, b1_GPIO_Port, b1_Pin, c1_GPIO_Port, c1_Pin, d1_GPIO_Port, d1_Pin, e1_GPIO_Port, e1_Pin, f1_GPIO_Port, f1_Pin, g1_GPIO_Port, g1_Pin);
            break;
        case 1:
            //Display the second 7SEG with led_buffer[1]
    		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
    		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
    		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
    		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
    		display7SEG(5, a2_GPIO_Port, a2_Pin, b2_GPIO_Port, b2_Pin, c2_GPIO_Port, c2_Pin, d2_GPIO_Port, d2_Pin, e2_GPIO_Port, e2_Pin, f2_GPIO_Port, f2_Pin, g2_GPIO_Port, g2_Pin);
            break;

        default:
            break;
    }
    return;
}
