/*
 * pedes_fsm.c
 *
 *  Created on: 13 thg 12, 2022
 *      Author: Quan
 */

#include "pedes_fsm.h"
#include "global.h"
#include "hardware_layer.h"
#include "input_reading.h"
#include "software_timer.h"
#include "stdio.h"
#include "main.h"
#include "stdint.h"

void pedestrian_fsm(){
	switch (pedes_state){
	case NONE:
		set_color_pedestrian_light(0);
		if(is_button_pressed(PEDES_IDX)){
			if(
				(state==AUTO_RED&&counter1>=3)||
			     state==SETTING_RED||
			   ((state==MANUAL)&&(manual_state==1||manual_state==3))
			) pedes_state = GREEN;
			else pedes_state=RED;
		}
		break;
	case GREEN:
		set_color_pedestrian_light(XANH);
		if(
			(state==AUTO_GREEN)||
			(state==SETTING_GREEN)||
			(state==MANUAL&&manual_state==2)
		) pedes_state=NONE;
		//PWM
		//__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1, counter1/red_duration*100);
		break;
	case RED:
		set_color_pedestrian_light(DO);
		if(
			(state==AUTO_RED&&counter1>=3)
			||state==SETTING_RED
			||((state==MANUAL)&&(manual_state==1||manual_state==3))
		) pedes_state = GREEN;

		break;
	default:
		break;
	}
}
