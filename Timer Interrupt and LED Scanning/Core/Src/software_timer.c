/*
 * software_timer.c
 *
 *  Created on: Sep 30, 2023
 *      Author: ADMIN
 */
int timer0_counter = 0;
int timer1_counter = 0;
int timer2_counter = 0;
int timer3_counter = 0;
int timer4_counter = 0;
int timer0_flag = 1;
int timer1_flag = 1;
int timer2_flag = 1;
int timer3_flag = 1;
int timer4_flag = 1;
int TIMER_CYCLE = 10;
void setTimer0(int duration){
	timer0_counter = duration /TIMER_CYCLE;
	timer0_flag = 0;
}
void setTimer1(int duration){
	timer1_counter = duration /TIMER_CYCLE;
	timer1_flag = 0;
}
void setTimer2(int duration){
	timer2_counter = duration /TIMER_CYCLE;
	timer2_flag = 0;
}
void setTimer3(int duration){
	timer3_counter = duration / TIMER_CYCLE;
	timer3_flag = 0;
}
void setTimer4(int duration){
	timer4_counter = duration / TIMER_CYCLE;
	timer4_flag = 0;
}
void timer_run(){
	if ( timer0_counter > 0) {
		timer0_counter--;
		if ( timer0_counter == 0) timer0_flag = 1;
	}

	if ( timer1_counter > 0) {
		timer1_counter--;
		if ( timer1_counter == 0) timer1_flag = 1;
	}

	if ( timer2_counter > 0) {
		timer2_counter--;
		if ( timer2_counter == 0) timer2_flag = 1;
	}
	if ( timer3_counter > 0) {
		timer3_counter--;
		if ( timer3_counter == 0) timer3_flag = 1;
	}
	if ( timer4_counter > 0) {
		timer4_counter--;
		if ( timer4_counter == 0) timer4_flag = 1;
	}
}
