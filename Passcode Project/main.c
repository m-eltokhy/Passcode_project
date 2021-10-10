/*
 * main.c
 *
 *  Created on: Oct 5, 2021
 *      Author: M.Eltokhy
 */
#include "MCAL/DIO/dio.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "HAL/LCD/lcd.h"
#include "HAL/Keypad/keypad.h"

uint8 password[4] = { '1', '2', '3', '4' }, entered_password[4] = { 0 };

int main() {
	dio_init();
	lcd_init();
	lcd_start_program();
	uint8 key, index = 0, correct_password = 1;
	while (1) {
		key = keypad_read();
		action_for_key(&key, &correct_password, &index, password, entered_password);
	}
	return 0;
}
