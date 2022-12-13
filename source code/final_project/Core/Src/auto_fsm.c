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
	case AUTO_RED:
		//hien thi mau do tren den giao thong 1
		set_color_light1(1);
		//dem lui moi 1s
		if(timer1_flag==1){
			counter1--;
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"red=%d\r\n"
								  		,counter1),1000) ;
			setTimer1(1000);
		}
		//neu counter1 == 0 chuyen trang thai sang auto_green
		if (counter1<=0) {
			counter1=green_duration;//nap lai thoi gian cho duration
			state=AUTO_GREEN;
		}//nguoc lai van o trang thai auto_red

		//neu an nut 1 thi chuyen sang trang thai setting
		if (is_button_pressed(0))
			{
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"setting_red=%d\r\n"
										,counter1),1000);
			state=SETTING_RED;
			}
		break;
	case AUTO_GREEN:
		//hien thi mau xanh tren den giao thong 1
		set_color_light1(2);
		//gui tin hieu uart de hien thi thoi gian
			//can bo sung them ham trong hardware_layer
		//dem lui moi 1s
		if(timer1_flag==1){
			counter1--;
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"green=%d\r\n"
											  		,counter1),1000) ;
			setTimer1(1000);
		}
		//neu counter1 == 0 chuyen trang thai sang auto_yellow
		if (counter1==0) {
			counter1=yellow_duration;//nap lai thoi gian cho duration
			state=AUTO_YELLOW;
		}//nguoc lai van o trang thai auto_green

		//neu an nut 1 thi chuyen sang trang thai setting_red
		if (is_button_pressed(0))
		{
			state=SETTING_RED;
		}
		break;
	case AUTO_YELLOW:
		//hien thi mau xanh tren den giao thong 1
		set_color_light1(3);
		//gui tin hieu uart de hien thi thoi gian
			//can bo sung them ham trong hardware_layer
		//dem lui moi 1s
		if(timer1_flag==1){
			HAL_UART_Transmit(&huart2 ,(void*)str,sprintf(str,"yellow=%d\r\n"
														  		,counter1),1000) ;
			counter1--;
			setTimer1(1000);
		}
		//neu counter1 == 0 chuyen trang thai sang auto_red
		if (counter1==0) {
			counter1=red_duration;//nap lai thoi gian cho duration
			state=AUTO_RED;
		}//nguoc lai van o trang thai auto_yellow

		//neu an nut 1 thi chuyen sang trang thai setting_red
		if (is_button_pressed(0))
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

