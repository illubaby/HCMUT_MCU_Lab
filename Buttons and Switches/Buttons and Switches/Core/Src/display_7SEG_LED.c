///*
// * display_LED.c
// *
// *  Created on: Oct 12, 2023
// *      Author: ADMIN
// */
//int led_buffer[4] = {1, 2, 3, 4};
//void display7SEG(int num) {
//	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
//
//	switch(num) {
//		case 0:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
//		break;
//		case 1:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
//		// (Add the rest of the pins needed to display '1')
//		break;
//		case 2:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
//		break;
//		case 3:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
//		break;
//		case 4:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
//		break;
//		case 5:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
//		break;
//		case 6:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
//		break;
//		case 7:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
//		break;
//		case 8:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
//		break;
//		case 9:
//		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
//		break;
//		default:
//		// Handle invalid input by possibly clearing all segments or displaying a predefined error state
//		break;
//	}
//	return;
//}
//void update7SEG(int index){
//	if(index_led>MAX_LED) index_led = (index_led + 1) % MAX_LED;
//    switch (index){
//        case 0:
//            //Display the first 7SEG with led_buffer[0]
//    		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
//    		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//        	display7SEG(led_buffer[0]);
//            break;
//        case 1:
//            //Display the second 7SEG with led_buffer[1]
//    		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//    		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//        	display7SEG(led_buffer[1]);
//            break;
//        case 2:
//            //Display the third 7SEG with led_buffer[2]
//    		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//    		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//        	display7SEG(led_buffer[2]);
//        	break;
//        case 3:
//        	display7SEG(led_buffer[3]);
//            //Display the forth 7SEG with led_buffer[3]
//    		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//    		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
//            break;
//        default:
//            break;
//    }
//    return;
//}
