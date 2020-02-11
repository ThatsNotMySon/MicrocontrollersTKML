#include <avr/io.h>
#include <avr/interrupt.h>


ISR( INT0_vect )
{
	volatile int count = 0;
	while(count < 10000){count++;}
	PORTD = 1 << 1;
}

ISR( INT1_vect )
{	
	volatile int count = 0;
	while(count < 10000){count++;}
	PORTD = 1 << 2;
}
ISR( INT2_vect )
{
	volatile int count = 0;
	while(count < 10000){count++;}
	PORTD = 1 << 3;
}

ISR( INT3_vect )
{	
	volatile int count = 0;
	while(count < 10000){count++;}
	PORTD = 1;
}

int main( void )
{
	// Init I/O
	DDRD = 0xFF;			// PORTD(7:3) output, PORTD(2:0) input	0b11111100

	// Init Interrupt hardware
	EICRA |= 0xFF;			// INT1 falling edge, INT0 rising edge  0b00001011
	EIMSK |= 0x0F;			// Enable INT1 & INT0					0b00000011
	
	// Enable global interrupt system
	//SREG = 0x80;			// Of direct via SREG of via wrapper
	PORTD = 0x01;	
	sei();	
			

	while (1)
	{	
	}

	return 1;
}

