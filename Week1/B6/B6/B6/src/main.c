#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

void blink4Hz()
{
	PORTD = 0x80;
	wait(250);
	PORTD = 0x00;
	wait(250);
}

void blink1Hz()
{
	PORTD = 0x80;
	wait(1000);
	PORTD = 0x00;
	wait(1000);
}

int main (void)
{
	DDRD = 0xFF;
	bool isDefaultState = true;
	
	while (1==1)
	{
		isDefaultState ? blink1Hz() : blink4Hz();
			
		if ((PINC & 0xFF) && isDefaultState == true)
		{
			isDefaultState = false;
		} else if ((PINC & 0xFF) && isDefaultState == false) {
			isDefaultState = true;
		}
	}
	
	return 1;
}