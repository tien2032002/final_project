/*
 * hardware_layer.c
 *
 *  Created on: 13 thg 12, 2022
 *      Author: Administrator
 */


#include "hardware_layer.h"
#include "main.h"
#include "stdio.h"
void set_color_light1(int color){
	switch (color){
	case 0://khong mau
		HAL_GPIO_WritePin(Light1_1_GPIO_Port, Light1_1_Pin, RESET);
		HAL_GPIO_WritePin(Light1_2_GPIO_Port, Light1_2_Pin, RESET);
		break;
	case DO://mau do
		HAL_GPIO_WritePin(Light1_1_GPIO_Port, Light1_1_Pin, SET);
		HAL_GPIO_WritePin(Light1_2_GPIO_Port, Light1_2_Pin, RESET);
		break;
	case XANH://mau xanh
		HAL_GPIO_WritePin(Light1_1_GPIO_Port, Light1_1_Pin, RESET);
		HAL_GPIO_WritePin(Light1_2_GPIO_Port, Light1_2_Pin, SET);
		break;
	case VANG://mau vang
		HAL_GPIO_WritePin(Light1_1_GPIO_Port, Light1_1_Pin, SET);
		HAL_GPIO_WritePin(Light1_2_GPIO_Port, Light1_2_Pin, SET);
		break;
	default:
		break;
	}
}

void set_color_light2(int color){
	switch (color){
		case 0://khong mau
			HAL_GPIO_WritePin(Light2_1_GPIO_Port, Light2_1_Pin, RESET);
			HAL_GPIO_WritePin(Light2_2_GPIO_Port, Light2_2_Pin, RESET);
			break;
		case DO://mau do
			HAL_GPIO_WritePin(Light2_1_GPIO_Port, Light2_1_Pin, RESET);
			HAL_GPIO_WritePin(Light2_2_GPIO_Port, Light2_2_Pin, SET);
			break;
		case XANH://mau xanh
			HAL_GPIO_WritePin(Light2_1_GPIO_Port, Light2_1_Pin, SET);
			HAL_GPIO_WritePin(Light2_2_GPIO_Port, Light2_2_Pin, RESET);
			break;
		case VANG://mau vang
			HAL_GPIO_WritePin(Light2_1_GPIO_Port, Light2_1_Pin, SET);
			HAL_GPIO_WritePin(Light2_2_GPIO_Port, Light2_2_Pin, SET);
			break;
		default:
			break;
		}
}

void set_color_pedestrian_light(int color){
	switch (color){
		case 0://khong mau
			HAL_GPIO_WritePin(Pedes_light1_GPIO_Port, Pedes_light1_Pin, RESET);
			HAL_GPIO_WritePin(Pedes_light2_GPIO_Port, Pedes_light2_Pin, RESET);
			break;
		case DO://mau do
			HAL_GPIO_WritePin(Pedes_light1_GPIO_Port, Pedes_light1_Pin, SET);
			HAL_GPIO_WritePin(Pedes_light2_GPIO_Port, Pedes_light2_Pin, RESET);
			break;
		case XANH://mau xanh
			HAL_GPIO_WritePin(Pedes_light1_GPIO_Port, Pedes_light1_Pin, RESET);
			HAL_GPIO_WritePin(Pedes_light2_GPIO_Port, Pedes_light2_Pin, SET);
			break;
		case VANG://mau vang
			HAL_GPIO_WritePin(Pedes_light1_GPIO_Port, Pedes_light1_Pin, SET);
			HAL_GPIO_WritePin(Pedes_light2_GPIO_Port, Pedes_light2_Pin, SET);
			break;
		default:
			break;
		}
}
