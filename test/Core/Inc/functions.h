/*
 * functions.h
 *
 *  Created on: Sep 29, 2024
 *      Author: lukeoarnone
 */

#ifndef INC_FUNCTIONS_H_
#define INC_FUNCTIONS_H_

void ledBlink(unsigned int port, int pin, int start_state, int speed);
void pwmBlink();
void initDigital(char port, int pin, char IO, char clock);

#endif /* INC_FUNCTIONS_H_ */
