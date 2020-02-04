#include <avr/io.h>
#include <util/delay.h>

typedef struct {
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT;

PATTERN_STRUCT pattern[] = {
	{0xFF, 100}, {0x4E, 100}, {0x24, 100}, {0x18, 100},
	{0x00, 0},
};


void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

int main (void)
{
	DDRD = 0xFF;
	
	while (1==1)
	{
		// Set index to begin of pattern array
		int index = 0;
		// as long as delay has meaningful content
		while( pattern[index].delay != 0 ) {
			// Write data to PORTD
			PORTD = pattern[index].data;
			// wait
			wait(pattern[index].delay);
			// increment for next round
			index++;
		}
	}
	
	return 1;
}