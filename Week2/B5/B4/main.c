#include <avr/io.h>
#include "LCD.h"
#include "Functions.h"

int main(void)
{
	// Init I/O
	DDRD = 0xFF;			// PORTD(7) output, PORTD(6:0) input

	// Init LCD
	lcd_init();

	// Write sample string
	lcd_display_text("BSOD");

	// Loop forever
	while (1)
	{
		PORTD ^= (1<<7);	// Toggle PORTD.7
		functions_wait(250);	
	}

	return 1;
}