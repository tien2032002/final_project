/*
 * auto_fsm.c
 *
 *  Created on: Nov 26, 2022
 *      Author: legolas
 */


#include "auto_fsm.h"
#include "global.h"
#include "scheduler.h"
#include "hardware_layer.h"
#include "input_reading.h"
#include "software_timer.h"
#include "stdio.h"
#include "main.h"
#include "stdint.h"
char str[50];
void fsm(){
	switch(state){
	case INIT:
		red_duration=5;
		green_duration=3;
		yellow_duration=2;
		counter1=red_duration;
		HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"red=%d\r\n"
							  		,counter1),1000) ;
		setTimer1(1000);
		state=AUTO_RED;
	case AUTO_RED:
		//reset flag for setting button and manual button
		is_button_pressed(SETTING_IDX);
		is_button_pressed(MANUAL_IDX);
		//hien thi mau do tren den giao thong 1
		set_color_light1(DO);
		//hien thi den giao thong 2
		if (counter1>=yellow_duration) set_color_light2(XANH);
		else set_color_light2(VANG);
		//dem lui moi 1s
		if(timer1_flag==1){
			counter1--;
			if (counter1<=0) {
				counter1=green_duration;//nap lai thoi gian cho duration
				state=AUTO_GREEN;
				HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"green=%d\r\n"
												  		,counter1),1000) ;
			}//nguoc lai van o trang thai auto_red
			else
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"red=%d\r\n"
								  		,counter1),1000) ;
			setTimer1(1000);
		}

		//neu an nut 1 thi chuyen sang trang thai setting
		if (is_button_pressed(STATE_IDX))
			{
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_red=%d\r\n"
										,red_duration),1000);
			state=SETTING_RED;
			}
		break;
	case AUTO_GREEN:
		//reset flag for setting button and manual button
		is_button_pressed(SETTING_IDX);
		is_button_pressed(MANUAL_IDX);
		//hien thi mau xanh tren den giao thong 1
		set_color_light1(XANH);
		//hien thi den giao thong 2
		set_color_light2(DO);
		//gui tin hieu uart de hien thi thoi gian
			//can bo sung them ham trong hardware_layer
		//dem lui moi 1s
		if(timer1_flag==1){
			counter1--;
			if (counter1<=0) {
				counter1=yellow_duration;//nap lai thoi gian cho duration
				state=AUTO_YELLOW;
				HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"yellow=%d\r\n"
												  		,counter1),1000) ;
			}//nguoc lai van o trang thai auto_green
			else
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"green=%d\r\n"
											  		,counter1),1000) ;
			setTimer1(1000);
		}
		//neu counter1 == 0 chuyen trang thai sang auto_yellow


		//neu an nut 1 thi chuyen sang trang thai setting_red
		if (is_button_pressed(STATE_IDX))
		{
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_red=%d\r\n"
										,red_duration),1000);
			state=SETTING_RED;
		}
		break;
	case AUTO_YELLOW:
		//reset flag for setting button and manual button
		is_button_pressed(SETTING_IDX);
		is_button_pressed(MANUAL_IDX);
		//hien thi mau xanh tren den giao thong 1
		set_color_light1(VANG);
		//hien thi den giao thong 2
		set_color_light2(DO);
		//gui tin hieu uart de hien thi thoi gian
			//can bo sung them ham trong hardware_layer
		//dem lui moi 1s
		if(timer1_flag==1){
			counter1--;
			//neu counter1 == 0 chuyen trang thai sang auto_red
			if (counter1==0) {
				counter1=red_duration;//nap lai thoi gian cho duration
				HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"red=%d\r\n"
															  		,counter1),1000) ;
				state=AUTO_RED;
			}//nguoc lai van o trang thai auto_yellow
			else HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"yellow=%d\r\n"
														  		,counter1),1000) ;
			setTimer1(1000);
		}


		//neu an nut 1 thi chuyen sang trang thai setting_red
		if (is_button_pressed(STATE_IDX))
		{
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_red=%d\r\n"
							,red_duration),1000) ;
			state=SETTING_RED;

		}
		break;
	default:
		break;
	}
}

