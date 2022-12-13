/*
 * setting_fsm.c
 *
 *  Created on: 13 thg 12, 2022
 *      Author: Administrator
 */
#include "setting_fsm.h"
#include "global.h"
#include "hardware_layer.h"
#include "input_reading.h"
#include "software_timer.h"
#include "stdio.h"
#include "main.h"
#include "stdint.h"


char str[50];

void setting_fsm() {
	switch (state) {
	case SETTING_RED:
		//reset flag for manual button
		is_button_pressed(MANUAL_IDX);
		//hien thi mau do tren den giao thong 1
		set_color_light1(DO);
		//neu an nut 2 thi se tang red_duration
		if(is_button_pressed(SETTING_IDX)){
			red_duration++;
			if(red_duration>=10) red_duration=1;
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_red=%d\r\n"
							,red_duration),1000) ;

		}
		//gui tin hieu uart de hien thi thoi gian
					//can bo sung them ham trong hardware_layer

		//neu an nut 1 thi chuyen sang trang thai setting_green
		if (is_button_pressed(STATE_IDX)){
			state=SETTING_GREEN;
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_green=%d\r\n"
										,green_duration),1000) ;
			}
		break;
	case SETTING_GREEN:
		//reset flag for manual button
		is_button_pressed(MANUAL_IDX);
		//hien thi mau xanh tren den giao thong 1
		set_color_light1(XANH);
		//neu an nut 2 thi se tang red_duration
		if(is_button_pressed(SETTING_IDX)){
			green_duration++;
			if(green_duration>=10) green_duration=1;
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_green=%d\r\n"
							,green_duration),1000) ;

		}
		//gui tin hieu uart de hien thi thoi gian
					//can bo sung them ham trong hardware_layer

		//neu an nut 1 thi chuyen sang trang thai setting_yellow
		if (is_button_pressed(STATE_IDX)){
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_yellow=%d\r\n"
										,yellow_duration),1000) ;
			state=SETTING_YELLOW;
			}
		break;
	case SETTING_YELLOW:
		//reset flag for manual button
		is_button_pressed(MANUAL_IDX);
		//hien thi mau vang tren den giao thong 1
		set_color_light1(VANG);
		//neu an nut 2 thi se tang red_duration
		if(is_button_pressed(SETTING_IDX)){
			yellow_duration++;
			if(yellow_duration>=10) yellow_duration=1;
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_yellow=%d\r\n"
							,yellow_duration),1000) ;

		}
		//gui tin hieu uart de hien thi thoi gian
					//can bo sung them ham trong hardware_layer

		//neu an nut 1 thi chuyen sang trang thai manual
		if (is_button_pressed(STATE_IDX)){
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"manual\r\n"
										),1000) ;
			state=MANUAL;
			}
		break;
		default:
			break;
	}
}
