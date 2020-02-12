#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8d6

 void wait( int ms )
 {
	 for (int i=0; i<ms; i++)
	 {
		 _delay_ms( 1 );
	 }
 }

int main(void)
{
    /* Replace with your application code */
	DDRC = 0xFF;
	PORTC = 0x80;
	
    while (1) 
    {
		if (PORTC == 0)
		{
			PORTC =0x80;
		}
		PORTC = PORTC >> 1;
		wait(500);
    }
}

