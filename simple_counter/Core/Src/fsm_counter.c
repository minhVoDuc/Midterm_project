/*
 * fsm_counter.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Guest_demo
 */

#include "fsm_counter.h"
#include "main.h"
#include "global.h"
#include "display_led.h"

int anyPressing = 0;

void fsm_simple_buttons_run(){
	display_num(counterVar);
	switch(counterState){
	/*-init state: initialize any params-*/
	case N_INIT:
	// Action
		clear_all_led();
	// Changing state
		counterState = N_STABLE;
		break;

	/*------STABLE state: no action------*/
	case N_STABLE:
	// Changing state
		if (isBtnPressed(BTN_RST)){
			counterState = P_RESET;
			anyPressing = 1;
		}
		else if (isBtnLongPressed(BTN_INC)){
			if (isTimerFlagOn(TIM_AUTOMOD)){
				counterState = A_INC;
			}
			anyPressing = 1;
		}
		else if (isBtnLongPressed(BTN_DEC)){
			if (isTimerFlagOn(TIM_AUTOMOD)){
				counterState = A_DEC;
			}
			anyPressing = 1;
		}
		else if (isBtnPressed(BTN_INC)){
			counterState = P_INC;
			anyPressing = 1;
		}
		else if (isBtnPressed(BTN_DEC)){
			counterState = P_DEC;
			anyPressing = 1;
		}
		else if (isTimerFlagOn(TIM_NOPRESS)){
			counterState = N_UNSTABLE;
			setTimer(TIM_AUTOMOD, 0);
			anyPressing = 0;
		}
		else{
			if (!anyPressing){
				setTimer(TIM_NOPRESS, 10000);
			}
			anyPressing = 1;
		}
		break;

	/*---UNSTABLE state: auto decrease counter---*/
	case N_UNSTABLE:
	// Action
		if (isTimerFlagOn(TIM_AUTOMOD)){
			counterVar = (counterVar + MAX_COUNT - 1) % MAX_COUNT;
			setTimer(TIM_AUTOMOD, 1000);
		}
	// Changing state
		if (counterVar == 0) counterState = N_STABLE;
		else if (isBtnPressed(BTN_INC)) counterState = P_INC;
		else if (isBtnPressed(BTN_DEC)) counterState = P_DEC;
		break;

	/*------RESET state: counter = 0-----*/
	case P_RESET:
	// Acion
		counterVar = 0;
	// Changing state
		if (!isBtnPressed(BTN_RST))	counterState = N_STABLE;
		break;

	/*----INC state: increase counter----*/
	case P_INC:
	// Action
		counterVar = (counterVar + 1) % MAX_COUNT;
	// Changing state
		counterState = N_STABLE;
		break;

	/*---AUTO INC state: auto increase counter---*/
	case A_INC:
	// Action
		counterVar = (counterVar + 1) % MAX_COUNT;
		setTimer(TIM_AUTOMOD, 1000);
	// Changing state
		counterState = N_STABLE;
		break;

	/*----DEC state: decrease counter----*/
	case P_DEC:
	// Action
		counterVar = (counterVar + MAX_COUNT - 1) % MAX_COUNT;
	// Changing state
		counterState = N_STABLE;
		break;

	/*---AUTO DEC state: auto decrease counter---*/
	case A_DEC:
	// Action
		counterVar = (counterVar + MAX_COUNT - 1) % MAX_COUNT;
		setTimer(TIM_AUTOMOD, 1000);
	// Changing state
		counterState = N_STABLE;
		break;
	/*-------------------------------------------*/

	default:
		break;
	}
}
