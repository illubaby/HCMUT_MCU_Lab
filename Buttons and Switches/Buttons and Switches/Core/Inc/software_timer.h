/*
 * software_timer.h
 *
 *  Created on: Sep 30, 2023
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;


void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
