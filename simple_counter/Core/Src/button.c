/*
 * button.c
 *
 *  Created on: 5 thg 11, 2022
 *      Author: Guest_demo
 */

#include "button.h"
#include "main.h"
#include "software_timer.h"

//Init time for long press
#define	LONG_DURATION	300

//Work for multiple buttons
#define IS_PRESSED		GPIO_PIN_RESET
#define IS_RELEASED		GPIO_PIN_SET

//Store button state in buffer after debouncing
//static GPIO_PinState buttonBuffer[MAX_BUTTON];

//Store button state in 2 buffers for debouncing
int KeyReg0[MAX_BUTTON] = {IS_RELEASED};
int KeyReg1[MAX_BUTTON] = {IS_RELEASED};
int KeyReg2[MAX_BUTTON] = {IS_RELEASED};
int KeyReg3[MAX_BUTTON] = {IS_RELEASED};

int Over1Sec[MAX_BUTTON] = {0};

int TimeOutForKeyPress[MAX_BUTTON] = {LONG_DURATION};
int flagBtn[MAX_BUTTON] = {0};
int flagBtnLong[MAX_BUTTON] = {0};

void button_reading(void){
	for (int i = 0; i < MAX_BUTTON; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		switch (i){ //check which button is being read now
		case BTN_RST:
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, BTN_RST_Pin);
			break;
		case BTN_INC:
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, BTN_INC_Pin);
			break;
		case BTN_DEC:
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, BTN_DEC_Pin);
			break;
		default:
			break;
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];

				if (KeyReg3[i] == IS_PRESSED){
					TimeOutForKeyPress[i] = LONG_DURATION;
					subKeyProcess(i);
				}
				else{
					flagBtnLong[i] = 0;
					Over1Sec[i] = 0;
				}
			} else {
				TimeOutForKeyPress[i] --;
				if (TimeOutForKeyPress[i] == 0){
					KeyReg3[i] = IS_RELEASED;
				}
			}
		}
	}
}

void subKeyProcess(int index){
	flagBtn[index] = 1;
	if (Over1Sec[index] == 0){
		Over1Sec[index] = 1;
	}
	else{
		flagBtnLong[index] = 1;
		flagBtn[index] = 0;
	}
}

int isBtnPressed(int index){
	if (flagBtn[index] == 1){
		flagBtn[index] = 0;
		return 1;
	}
	return 0;
}

int isBtnLongPressed(int index){
	return (flagBtnLong[index] == 1);
}
