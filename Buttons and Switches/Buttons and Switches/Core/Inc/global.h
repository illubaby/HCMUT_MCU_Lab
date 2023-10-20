/*
 * global.h
 *
 *  Created on: Sep 28, 2023
 *      Author: KAI
 */
#include "software_timer.h"
#include "button.h"
#include "main.h"
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 	1
#define AUTO_RED	2
#define AUTO_YELLOW 3
#define AUTO_GREEN  4

#define MAN_RED		12
#define MAN_GREEN   13
#define MAN_YELLOW	14
extern int led_status;
extern int counter;
extern int led_buffer[4];
extern int index_led;
extern int MAX_LED;
#endif /* INC_GLOBAL_H_ */
