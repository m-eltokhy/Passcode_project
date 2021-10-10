/*
 * lcd.c
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#include "lcd.h"

void lcd_init(void){
	_delay_ms(100);
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x06);

}

void lcd_cmd(uint8 cmd){
	dio_write(RS, low);
	PORTA=cmd;
	dio_write(E, high);
	_delay_ms(3);
	dio_write(E, low);
	_delay_ms(100);
}

void lcd_data(uint8 data){
	dio_write(RS, high);
	PORTA=data;
	dio_write(E, high);
	_delay_ms(3);
	dio_write(E, low);
	_delay_us(10);
}

void lcd_string(uint8 str[12]){
	uint8 ctr=0;
	while(str[ctr]!='\n'){
		lcd_data(str[ctr]);
		ctr++;
	}
}

void lcd_start_program(void){
	SET_BIT(PORTB,3);
	CLEAR_BIT(PORTB,4);
	lcd_cmd(0x01);
	lcd_string("Enter Password:\n");
	lcd_cmd(0xC0);
}

void lcd_password_accepted(void){
	lcd_cmd(0x01);
	lcd_string("Password\n");
	lcd_cmd(0xC0);
	lcd_string("Accepted\n");
}

void lcd_password_rejected(void){
	lcd_cmd(0x01);
	lcd_string("Password\n");
	lcd_cmd(0xC0);
	lcd_string("Rejected\n");
}
