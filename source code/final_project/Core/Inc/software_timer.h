/*
 * software_timer.h
 *
 *  Created on: 13 thg 12, 2022
 *      Author: Administrator
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TICK 10

extern int timer1_flag;
extern int timer1_counter;

extern int timer2_flag;
extern int timer2_counter;

extern int timer3_flag;
extern int timer3_counter;

void setTimer1(int duration);
void timer1_run();

void setTimer2(int duration);
void timer2_run();

void setTimer3(int duration);
void timer3_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
