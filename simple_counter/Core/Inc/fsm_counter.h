/*
 * fsm_counter.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Guest_demo
 */

#ifndef INC_FSM_COUNTER_H_
#define INC_FSM_COUNTER_H_

#define N_INIT		10
#define N_STABLE	11
#define	P_RESET		12
#define P_INC		13
#define P_DEC		14
#define A_INC		15
#define A_DEC		16
#define N_UNSTABLE	17

#define MAX_COUNT	10

void fsm_simple_buttons_run();

#endif /* INC_FSM_COUNTER_H_ */
