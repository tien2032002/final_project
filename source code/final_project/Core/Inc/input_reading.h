/*
 * input_reading.h
 *
 *  Created on: 13 thg 12, 2022
 *      Author: Administrator
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define NO_OF_BUTTONS 4

#define STATE_IDX	0
#define SETTING_IDX	1
#define	MANUAL_IDX	2
#define PEDES_IDX	3

extern int button_flag[NO_OF_BUTTONS];//flag for reset button
extern int FlagFor3secPressed[NO_OF_BUTTONS];


void input_reading(void);
int is_button_pressed(int index);

#endif /* INC_INPUT_READING_H_ */
