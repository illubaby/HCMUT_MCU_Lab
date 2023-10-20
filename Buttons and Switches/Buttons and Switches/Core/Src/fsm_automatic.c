/*
 * fsm_automatic.c
 *
 *  Created on: Oct 10, 2023
 *      Author: ADMIN
 */
#include "fsm_automatic.h"
#include "main.h"
#include "7_SEG_Display.h"

int red1_time = 5;
int green1_time = 2;
int yellow1_time  = 2;

int red1_time_temp ;
int green1_time_temp ;
int yellow1_time_temp ;

int green2_time = 0;
int yellow2_time  = 0;
int led1 = 0;
int led2 = 0;

void update_Led_buffer(){
	led_buffer[0] = led1%10;
	led_buffer[1] = led1/10;
	led_buffer[2] = led2%10;
	led_buffer[3] = led2/10;

}
void setTrafficLights(GPIO_PinState RED1, GPIO_PinState YELLOW1, GPIO_PinState GREEN1,
					GPIO_PinState RED2, GPIO_PinState YELLOW2, GPIO_PinState GREEN2) {
  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RED1);
  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, YELLOW1);
  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GREEN1);
  HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RED2);
  HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, YELLOW2);
  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GREEN2);
}


void update_counter() {
    // Handle the Red light state
    if (counter > green1_time + yellow1_time) {
        led1 = counter - (green1_time + yellow1_time);

        if (green2_time > 0) {
            setTrafficLights(GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET,
                             GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET);
            led2 = green2_time;
            green2_time--;
        } else if (yellow2_time > 0) {
            setTrafficLights(GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET,
                             GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET);
            led2 = yellow2_time;
            yellow2_time--;
        } else {
            setTrafficLights(GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET,
                             GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET);
        }
    }

    // Handle the Green light state
    else if (counter > yellow1_time && counter <= (green1_time + yellow1_time)) {
        led1 = counter - yellow1_time;
        led2 = counter;
        setTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET,
                         GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET);
    }
    // Handle the Yellow light state
    else if (counter > 0 && counter <= yellow1_time) {
        led1 = counter;
        led2 = counter;
        setTrafficLights(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET,
                         GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET);
    }

    // Reset counter and calculate time for the second light (led2)
    if (counter == 0) {
        counter = green1_time + yellow1_time + red1_time;

        if (red1_time > green1_time ) {	// We must prioritize the green light first
            green2_time = green1_time;
            yellow2_time = red1_time - green1_time;
        }
        else if (red1_time> yellow1_time){ // then if green bigger then red, we prioritize yellow
        	yellow2_time = yellow1_time;
        	green2_time = red1_time - yellow1_time;
        }
        else {								// finally, we assign all time for the green, yellow = 0;
        	green2_time = red1_time;
        	yellow2_time = 0 ;
        }
    } else {
        update_Led_buffer();
        counter--;
    }
}

void fsm_manual_run(){
	switch(led_status){
	case INIT:
		if (isButtonPressed(0)==1){
	        setTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET,
	                         GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET);
	        red1_time_temp = red1_time;
			led_status = AUTO_RED;
		}
		if (timer_flag[1]==1){
			update_counter();
			setTimer(1, 1000);
		}
		if (timer_flag[2]==1){
			update7SEG(index_led++);
			if (index_led>2) index_led = 0 ;
			setTimer(2, 100);
		}

		break;
	case AUTO_RED:
		if (isButtonPressed(0)==1){
	        setTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET,
	                         GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET);
	        yellow1_time_temp = yellow1_time;
			led_status = AUTO_YELLOW;
		}
		// display led
			if (timer_flag[0] == 1 ){
				HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
				HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
				setTimer(0,500);
			}
		// display 7 seg led
			if (timer_flag[2]==1){
				led1 = 1;
				led2 = red1_time_temp;
				update_Led_buffer();
				update7SEG(index_led++);
				if (index_led>2) index_led = 0 ;
				setTimer(2, 100);
			}
		//if press the second button
			if (isButtonPressed(1)==1){
				red1_time_temp +=1;
			}
		// if press the third button
			if (isButtonPressed(2)==1){
				red1_time = red1_time_temp;
			}
		break;
	case AUTO_YELLOW:

	        if (isButtonPressed(0) == 1) {
		        setTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET,
		                         GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET);
		        green1_time_temp = green1_time;
	            led_status = AUTO_GREEN;
	        }
	        if (timer_flag[0] ==1) {
	            HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	            HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
	            setTimer(0,500);
	        }
			// display 7 seg led
				if (timer_flag[2]==1){
					led1 = 2;
					led2 = yellow1_time_temp;
					update_Led_buffer();
					update7SEG(index_led++);
					if (index_led>2) index_led = 0 ;
					setTimer(2, 100);
				}
			//if press the second button
				if (isButtonPressed(1)==1){
					yellow1_time_temp +=1;
				}
			// if press the third button
				if (isButtonPressed(2)==1){
					yellow1_time = yellow1_time_temp;
				}
	        break;
	case AUTO_GREEN:

	        if (isButtonPressed(0) == 1) {
		        setTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET,
		                         GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET);
	            led_status = INIT;
	        }
	        if (timer_flag[0] ==1) {
	            HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	            HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	            setTimer(0,500);
	        }
			// display 7 seg led
				if (timer_flag[2]==1){
					led1 = 3;
					led2 = green1_time_temp;
					update_Led_buffer();
					update7SEG(index_led++);
					if (index_led>2) index_led = 0 ;
					setTimer(2, 100);
				}
			//if press the second button
				if (isButtonPressed(1)==1){
					green1_time_temp +=1;
				}
			// if press the third button
				if (isButtonPressed(2)==1){
					green1_time = green1_time_temp;
				}
	        break;
	default:
		break;
	}
}
