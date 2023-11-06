/*
 * software_timer.h
 *
 *  Created on: Sep 30, 2023
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[4];

void set_TIMER_CYCLE();
void setTimer(int timerIndex,int duration);

void timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
