/*
 * software_timer.h
 *
 *  Created on: Sep 30, 2023
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#define NUMBER_OF_TIMER_FLAG 2
extern int timer_flag[NUMBER_OF_TIMER_FLAG];

void set_TIMER_CYCLE();
void setTimer(int timerIndex,int duration);

void timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
