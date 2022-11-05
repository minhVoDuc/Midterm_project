/*
 * display_led.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Guest_demo
 */

#include "display_led.h"
#include "main.h"

void display_num(int num){
	switch (num){
	case 0: // display 0 using leds: a, b, c, d, e, f
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
								SEG3_Pin | SEG4_Pin | SEG5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
		break;
	case 1: // display 1 using leds: b, c
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG3_Pin | SEG4_Pin |
								SEG5_Pin | SEG6_Pin, 1);
		break;
	case 2: // display 2 using leds: a, b, d, e, g
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG3_Pin |
								SEG4_Pin | SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin | SEG5_Pin, 1);
		break;
	case 3: // display 3 using leds: a, b, c, d, g
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
								SEG3_Pin | SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin | SEG5_Pin, 1);
		break;
	case 4: // display 4 using leds: b, c, f, g
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin | SEG5_Pin |
								SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG3_Pin | SEG4_Pin, 1);
		break;
	case 5: // display 5 using leds: a, c, d, f, g
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin |
								SEG5_Pin | SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG4_Pin, 1);
		break;
	case 6: // display 6 using leds: a, c, d, e, f, g
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin |
								SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
		break;
	case 7: // diplay 7 using leds: a, b, c
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin | SEG4_Pin | SEG5_Pin |
								SEG6_Pin, 1);
		break;
	case 8: // display 8 using leds: a, b, c, d, e, f, g
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
								SEG3_Pin | SEG4_Pin | SEG5_Pin |
								SEG6_Pin, 0);
		break;
	case 9: // display 9 using leds: a, b, c, d, f, g
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
								SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
		break;
	default:
		break;
	}
}

void clear_all_led(){
	HAL_GPIO_WritePin(GPIOA, LED_TEST_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
									SEG3_Pin | SEG4_Pin | SEG5_Pin |
									SEG6_Pin, 1);
}
