/*
 * software_timer.c
 *
 *  Created on: Sep 30, 2023
 *      Author: ADMIN
 */
int timer_counter[20];
int timer_flag[20];
int TIMER_CYCLE = 10;

void setTimer(int timerIndex, int duration) {
    if (timerIndex >= 0 && timerIndex < 20) {
        timer_counter[timerIndex] = duration / TIMER_CYCLE;
        timer_flag[timerIndex] = 0;
    }
}

void timer_run() {
    for (int i = 0; i < 20; ++i) {
        if (timer_counter[i] > 0) {
            timer_counter[i]--;
            if (timer_counter[i] == 0) {
                timer_flag[i] = 1;
            }
        }
    }
}
