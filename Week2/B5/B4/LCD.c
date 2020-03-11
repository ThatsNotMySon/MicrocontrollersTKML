/*
 * LCD.c
 *
 * Created: 11-3-2020 21:21:03
 *  Author: mjays
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "Functions.h"

void lcd_display_text(char *str)
{
	while(*str) {
		lcd_write_char(*str++);
	}
}

void lcd_e(void)
{
	PORTC |= (1<<LCD_E);	// E high
	functions_wait(1);
	PORTC &= ~(1<<LCD_E);  	// E low
	functions_wait(1);
}

void lcd_write_char(unsigned char dat)
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	
	// start (EN=1)
	functions_wait(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	
	// start (EN=1)
	functions_wait(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}

void lcd_set_cursor(int position)
{
	PORTC = 0x00;
	lcd_e();
	PORTC = 0x80 + position;	// function set
	lcd_e();
}

void lcd_init()
{
	// PORTC output mode and all low (also E and RS pin)
	DDRC = 0xFF;
	PORTC = 0x00;

	// function set
	PORTC = 0x20;
	lcd_e();

	// function set
	PORTC = 0x20;
	lcd_e();
	PORTC = 0x80;
	lcd_e();

	// Display on/off control
	PORTC = 0x00;
	lcd_e();
	PORTC = 0xF0;
	lcd_e();
	
	// clear screen
	PORTC = 0x00;
	lcd_e();
	PORTC = 0x01;
	lcd_e();

	// Entry mode set
	PORTC = 0x00;
	lcd_e();
	PORTC = 0x60;
	lcd_e();
}
