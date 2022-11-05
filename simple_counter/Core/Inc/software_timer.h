/*
 * software_timer.h
 *
 *  Created on: 5 thg 11, 2022
 *      Author: Guest_demo
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define MAX_TIMER 	3
#define CYCLE 		10
#define TIME_UNIT	1000

#define TIM_NOPRESS		0
#define TIM_BLINKLED	1
#define	TIM_AUTOMOD		2

void initTimer();
void setTimer(int index, int duration); //duration count as milisecond (duration==1000 ~ 1000ms)
int getCurrTimer(int index); //get current counter for timer, unit milisec.
char isTimerFlagOn(int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
