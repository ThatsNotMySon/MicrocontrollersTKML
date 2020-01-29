/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		if(PINC & 0x01) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
		}
	}
}

int main (void)
{	
	DDRD = 0b11111111;			// All pins PORTD are set to output 
	DDRC = 0b00000000;
	
	while (1)
	{
		if (PINC & 0x80) {
		PORTD = 0x80;			// Write 10101010b PORTD
		}
		else {
			PORTD = 0x00;
		}
	}
	
	return 1;
}