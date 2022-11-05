/*
 * button.h
 *
 *  Created on: 5 thg 11, 2022
 *      Author: Guest_demo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define MAX_BUTTON	3

#define BTN_RST	0
#define BTN_INC	1
#define BTN_DEC	2

void button_reading(void);
int isBtnPressed(int index);
int isBtnLongPressed(int index);
void subKeyProcess(int index);

#endif /* INC_BUTTON_H_ */
