#include <avr/io.h>
#include <util/delay.h>
#define BIT(x) (1 << (x))

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
	
	// wait 50ms
	// n<<1 heen
	// n>>1 terug
	
	while (1)
	{
		
		for ( int i = 0x01; i<=0x80; i<<=1 )
		{
			PORTD = i;
			wait(50);
		}
		
		for ( int j = 0x80; j>=0x00; j>>=1 )
		{
			PORTD = j;
			wait(50);
		}
	}
	
	return 1;
}