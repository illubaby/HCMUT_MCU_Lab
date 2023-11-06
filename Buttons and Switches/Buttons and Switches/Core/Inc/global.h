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

#define INIT   1
#define MODE_2 2
#define MODE_3 3
#define NODE_4 4
#define RED_LIGHT 5
#define GREEN_LIGHT 6
#define YELLOW_LIGHT 7

#define MAN_RED		12
#define MAN_GREEN   13
#define MAN_YELLOW	14
extern int led_status;
extern int counter;
extern int led_buffer[4];
extern int index_led;
extern int MAX_LED;
#endif /* INC_GLOBAL_H_ */
