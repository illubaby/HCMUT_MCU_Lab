/*
 * software_timer.c
 *
 *  Created on: Sep 30, 2023
 *      Author: ADMIN
 */
int timer_counter[4];
int timer_flag[4];

int HCLK = 8000000;
int Prescaler = 7999;
int Period = 9;
int TIMER_CYCLE;

void set_TIMER_CYCLE(){
    float timer_frequency = (float)HCLK / (Prescaler + 1);
    timer_frequency = timer_frequency / (Period + 1);

    TIMER_CYCLE = (int)((1.0f / timer_frequency) * 1000 + 0.5);  // Added 0.5 for rounding
}

void setTimer(int timerIndex, int duration) {
    if (timerIndex >= 0 && timerIndex < 3) {
        timer_counter[timerIndex] = duration / TIMER_CYCLE;
        timer_flag[timerIndex] = 0;
    }
}

void timer_run() {
    for (int i = 0; i < 4; ++i) {
        if (timer_counter[i] > 0) {
            timer_counter[i]--;
            if (timer_counter[i] == 0) {
                timer_flag[i] = 1;
            }
        }
    }
}
