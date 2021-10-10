/*
 * keypad.h
 *
 *  Created on: Oct 5, 2021
 *      Author: M.Eltokhy
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "../../MCAL/DIO/dio.h"
#include "../LCD/lcd.h"

uint8 keypad_read(void);
void led_blink_green(void);
void led_blink_red(void);
void action_for_key(uint8*,uint8*,uint8*,uint8*,uint8*);
void reset_password(uint8*,uint8*);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
