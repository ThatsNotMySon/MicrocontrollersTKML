#include <avr/io.h>
#include <avr/interrupt.h>
#include "Functions.h"
#include "Tests.h"
#include "LCD.h"

int value = 0;
int CompareValue = 0x0F;

// Interrupt routine timer2 overflow
//
ISR( TIMER2_OVF_vect )
{
	value++; // Increment counter
}

void setupTimer()
{
	OCR2 = CompareValue; // Compare value of counter 2
	TIMSK |= 1<<7; // T2 compare match interrupt enable
	TCCR2 = 0b00011111; // Initialize T2: ext.counting, rising edge
	// compare output mode, CTC, RUN
	sei(); // turn_on intr all
}

int main(void)
{
	//STEP 1 LCD
	lcd_init();	// Init LCD

	//set 2 COUNTER
	DDRD &= ~(1<<7); // set PORTD.7 for input
	DDRA = 0xFF; // set PORTB for output (shows countregister)
	DDRB = 0xFF; // set PORTC for output (shows tenth value)
	setupTimer();

	// Loop forever
	while (1)
	{
		PORTA = TCNT2; // show value counter 2
		PORTB = value; // show value tenth counter
		
		functions_wait(1000); // every 10 ms
	}
	
	return 1;
}