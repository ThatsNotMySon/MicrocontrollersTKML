#include <avr/io.h>
#include <util/delay.h>

void init();
void display_text(char *str);
void set_cursor(int position);

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

void display_text(char *str)
{
	while(*str) {
		lcd_write_char(*str++);
	}	
}

void lcd_e(void)
{
	PORTC |= (1<<3);	// E high
	wait(1);	
	PORTC &= ~(1<<3);  	// E low
	wait(1);			
}

void lcd_write_char(unsigned char dat)
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	
	// start (EN=1)
	wait(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	
	// start (EN=1)
	wait(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}

void set_cursor(int position)
{
	PORTC = 0x80 + position;	// function set
	lcd_e();
}

void init()
{
	// PORTC output mode and all low (also E and RS pin)
	DDRC = 0xFF;
	PORTC = 0x00;

	// function set
	PORTC = 0x20;	
	lcd_e();

	// function set
	PORTC = 0x20;   
	lcd_e();
	PORTC = 0x80;
	lcd_e();

	// Display on/off control
	PORTC = 0x00;   
	lcd_e();
	PORTC = 0xF0;
	lcd_e();
	
	// clear screen
	PORTC = 0x00;   // Display on/off control
	lcd_e();
	PORTC = 0x01;	// function set
	lcd_e();

	// Entry mode set
	PORTC = 0x00;   
	lcd_e();
	PORTC = 0x60;
	lcd_e();
}


int main(void)
{
	// Init I/O
	DDRD = 0xFF;			// PORTD(7) output, PORTD(6:0) input

	// Init LCD
	init();

	// Write sample string
	display_text("MS-DOS");

	// Loop forever
	while (1)
	{
		PORTD ^= (1<<7);	// Toggle PORTD.7
		wait(250);	
	}

	return 1;
}