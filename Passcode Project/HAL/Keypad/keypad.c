/*
 * keypad.c
 *
 *  Created on: Oct 5, 2021
 *      Author: M.Eltokhy
 */

#include "keypad.h"

uint8 key[4][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' }, {
		'*', '0', '#' } };

uint8 keypad_read(void) {
	uint8 i = 0;
	for (i = 0; i < 3; i++) {
		SET_BIT(PORTD, (i + 1));
		if (dio_read(R3)) {
			CLEAR_BIT(PORTD, (i + 1));
			_delay_ms(200);
			return key[0][i];
		} else if (dio_read(R4)) {
			CLEAR_BIT(PORTD, (i + 1));
			_delay_ms(200);
			return key[1][i];
		} else if (dio_read(R5)) {
			CLEAR_BIT(PORTD, (i + 1));
			_delay_ms(200);
			return key[2][i];
		} else if (dio_read(R6)) {
			CLEAR_BIT(PORTD, (i + 1));
			_delay_ms(200);
			return key[3][i];
		}
		CLEAR_BIT(PORTD, (i + 1));
	}
	return 0;
}

void led_blink_green(void) {
	dio_write(Red_led, low);
	for (uint8 i = 0; i < 4; i++) {
		dio_write(Green_led, low);
		_delay_ms(250);
		dio_write(Green_led, high);
		_delay_ms(250);
	}
}

void led_blink_red(void) {
	dio_write(Green_led, low);
	for (uint8 i = 0; i < 4; i++) {
		dio_write(Red_led, low);
		_delay_ms(250);
		dio_write(Red_led, high);
		_delay_ms(250);
	}
}

void action_for_key(uint8 *key, uint8 *correct_password, uint8 *index,
		uint8 *password, uint8 *entered_password) {
	if (*key) {
		if (*key == '#') {
			for (uint8 i = 0; i < 4; i++) {
				if (password[i] == entered_password[i]) {
					continue;
				} else {
					*correct_password = 0;
					*index = 0;
				}
			}
			if (*correct_password) {
				lcd_password_accepted();
				led_blink_green();
				reset_password(entered_password, index);
			} else {
				lcd_password_rejected();
				led_blink_red();
				reset_password(entered_password, index);
			}
		} else if (*key == '*') {
			lcd_start_program();
			reset_password(entered_password, index);
		} else {
			entered_password[*index] = *key;
			(*index)++;
			lcd_data('*');
		}
	}
}

void reset_password(uint8 *entered_password, uint8 *index) {
	for (uint8 i = 0; i < 4; i++) {
		entered_password[i] = 0;
	}
	*index = 0;
}
