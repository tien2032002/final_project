/*
 * software_timer.c
 *
 *  Created on: 13 thg 12, 2022
 *      Author: Administrator
 */


#include "software_timer.h"

int timer1_flag=0;
int timer1_counter=0;

int timer2_flag=0;
int timer2_counter=0;

int timer3_flag=0;
int timer3_counter=0;

void setTimer1( int duration){
	timer1_counter=duration/TICK;
	timer1_flag=0;
}

void timer1_run(int index){
	if(timer1_counter>0){
		timer1_counter--;
		if(timer1_counter<=0) timer1_flag=1;
	}
}

void setTimer2( int duration){
	timer2_counter=duration/TICK;
	timer2_flag=0;
}

void timer2_run(int index){
	if(timer2_counter>0){
		timer2_counter--;
		if(timer2_counter<=0) timer2_flag=1;
	}
}

void setTimer3( int duration){
	timer3_counter=duration/TICK;
	timer3_flag=0;
}

void timer3_run(int index){
	if(timer3_counter>0){
		timer3_counter--;
		if(timer3_counter<=0) timer3_flag=1;
	}
}

