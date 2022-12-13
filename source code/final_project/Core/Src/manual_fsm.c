/*
 * manual_fsm.c
 *
 *  Created on: 13 thg 12, 2022
 *      Author: Administrator
 */


#include "manual_fsm.h"
#include "global.h"
#include "hardware_layer.h"
#include "input_reading.h"
#include "software_timer.h"
#include "stdio.h"
#include "main.h"
#include "stdint.h"

char str[50];

void manual_fsm() {
	switch(state){
	case MANUAL:
			//reset flag for setting reset button
			is_button_pressed(SETTING_IDX);
			set_color_light1(manual_state);
			if (is_button_pressed(MANUAL_IDX)) manual_state++;
			if (manual_state>3) manual_state=1;
			else if (is_button_pressed(STATE_IDX)){
				HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"auto_red=%d\r\n",
											red_duration),1000) ;
				counter1=red_duration;
				state=AUTO_RED;
			}
			is_button_pressed(SETTING_IDX);

			break;
		default:
			break;
	}
}
