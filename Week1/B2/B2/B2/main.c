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
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main (void)
{	
	DDRD = 0b01111111;					// PORTD.7 input all other bits output 
	PORTC = 0x10;						// ??		
	
	while (1)
	{
		if (PINC & 0x80) 
		{
			PORTD = 0x01;				// write 1 to all the bits of PortD
		}
		else 
		{
			PORTD = 0x00;				// write 0 to all the bits of PortD
		}
	}

	return 1;
}
