/*
 * functions.c
 *
 *  Created on: Sep 29, 2024
 *      Author: lukeoarnone
 */

#include "functions.h"
#include "main.h"

void ledBlink(unsigned int port, int pin, int start_state, int speed) { //e.g. "PA10" has port A ("GPIOA") and pin 10 ("GPIO_PIN_10")
	HAL_GPIO_WritePin(port, pin, !start_state);
	HAL_Delay(speed);
	HAL_GPIO_WritePin(port, pin, start_state);
	HAL_Delay(speed);
}

void pwmBlink() {
	for(int i=0; i<=100; i++){
		TIM2->CCR1 = i;
		HAL_Delay(10);
		  }

	for(int i=100; i>=0; i--){
		TIM2->CCR1 = i;
		HAL_Delay(10);
	}
}

void initDigital(char port, int pin, char IO, char clock) { // pin must be in the format GPIO_PIN_X, where X is the pin number
	GPIO_InitTypeDef GPIO_structure = {0}; // GPIO details list
	unsigned int port_code;

	switch (port) {
		case 'A':
			__HAL_RCC_GPIOA_CLK_ENABLE();
			port_code = GPIOA;
			break;
		case 'B':
			__HAL_RCC_GPIOB_CLK_ENABLE();
			port_code = GPIOB;
			break;
		case 'C':
			__HAL_RCC_GPIOC_CLK_ENABLE();
			port_code = GPIOC;
			break;
		case 'D':
			__HAL_RCC_GPIOD_CLK_ENABLE();
			port_code = GPIOD;
			break;
		default:
			return;
			break;
	}


	HAL_GPIO_WritePin(port_code, pin, 0); // set pin to output nothing
	GPIO_structure.Pin = pin; // pin number

	if (IO == 'O') {
		GPIO_structure.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_structure.Pull = GPIO_NOPULL;
	}
	else if (IO == 'I') {
		GPIO_structure.Mode = GPIO_MODE_INPUT;
		GPIO_structure.Pull = GPIO_PULLUP;
	}
	else {
		return;
	}

	if (clock == 'H') {
		GPIO_structure.Speed = GPIO_SPEED_FREQ_LOW;
	}
	else if (clock == 'L') {
		GPIO_structure.Speed = GPIO_SPEED_FREQ_LOW;
	}
	else {
		return;
	}

	HAL_GPIO_Init(port_code, &GPIO_structure); // where port is "GPIOX", where X is the port letter
}
