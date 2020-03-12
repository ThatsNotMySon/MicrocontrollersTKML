/*
 * Tests.c
 *
 * Created: 11-3-2020 21:33:46
 *  Author: mjays
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "Functions.h"
#include "Tests.h"

void tests_lcd_text()
{
	// Init I/O
	DDRD = 0xFF;			// PORTD(7) output, PORTD(6:0) input

	// Init LCD
	lcd_init();

	// Write sample string
	lcd_display_text(TESTS_STATIC_EXAMPLE_STRING);

	// Loop forever
	while (1)
	{
		PORTD ^= (1<<7);	// Toggle PORTD.7
		functions_wait(250);
	}
}

void tests_lcd_cursor()
{
	// Init I/O
	DDRD = 0xFF;			// PORTD(7) output, PORTD(6:0) input

	// Init LCD
	lcd_init();

	// Write sample string
	lcd_display_text(TESTS_STATIC_EXAMPLE_CHAR);
	lcd_set_cursor(10);
		
	functions_wait(2000);
	lcd_clear();
		
	lcd_display_text(TESTS_STATIC_EXAMPLE_CHAR);
		
	// Loop forever
	while (1)
	{
		PORTD ^= (1<<7);	// Toggle PORTD.7
		functions_wait(250);
	}
}