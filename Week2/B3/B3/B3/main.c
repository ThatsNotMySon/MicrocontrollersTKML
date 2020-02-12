#include <avr/io.h>
#include <util/delay.h>

#define F_CPU = 8e6

#define zero 0b01111110
#define one  0b01100000
#define two  0b10110110
#define three  0b11110010
#define four  0b11101000
#define five  0b11011010
#define six  0b11011110
#define seven  0b01110000
#define eight  0b11111110
#define nine 0b11111010
#define a  0b11111100
#define b  0b11001110
#define c  0b00011110
#define d  0b11100110
#define e  0b10011110
#define f  0b10011100
#define error 0b10111110

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

void display(int digit){
	switch(digit){
		case 0:
			PORTC = zero;
			break;
		case 1:
			PORTC = one;
			break;
		case 2:
			PORTC = two;
			break;
		case 3:
			PORTC = three;
			break;
		case 4:
			PORTC = four;
			break;
		case 5:
			PORTC = five;
			break;
		case 6:
			PORTC = six;
			break;
		case 7:
			PORTC = seven;
			break;
		case 8:
			PORTC = eight;
			break;
		case 9:
			PORTC = nine;
			break;
		case 10:
			PORTC = a;
			break;
		case 11:
			PORTC = b;
			break;
		case 12:
			PORTC = c;
			break;
		case 13:
			PORTC = d;
			break;
		case 14:
			PORTC = e;
			break;
		case 15:
			PORTC = f;
			break;
		default:
		PORTC = error;
		break;
	}
}

int main(void)
{
	/* Replace with your application code */
	DDRC = 0xFF;
	
	PORTC = 0;
	
	for(int i =0;i <= 16;i++ ){
		display(i);
		wait(1000);
	}
	
	while (1)
	{
	}

}

