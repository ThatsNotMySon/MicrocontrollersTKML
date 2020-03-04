#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8d6

void wait (int ms);
void lcd_command( unsigned char dat);
void init_lcd( void );
void lcd_writeChar( unsigned char dat );
void lcd_writeLine1 ( char text1[] );
void lcd_writeLine2 ( char text2[] );

 void wait( int ms )
 {
	 for (int i=0; i<ms; i++)
	 {
		 _delay_ms( 1 );
	 }
 }

int main(void)
{
	init_lcd();
	wait(250);
	
	char sentence[10] = "a";
	
	lcd_writeLine1(sentence);
	
	return 0;
}

void lcd_writeLine1 ( char text1[] )
{
	// eerst de eerste 8 karakters = regel 1
	// eerste pos regel 1
	lcd_command(0x80);
	for (int i=0; i<16; i++) {
		lcd_writeChar( text1[i] );
	}
}

void lcd_writeLine2 ( char text2[] )
{
	// dan de eerste 8 karakters = regel 2
	// eerste pos regel 2
	lcd_command(0xC0);
	for (int i=0; i<16; i++) {
		lcd_writeChar( text2[i] );
	}
}

// Initialisatie ldr
//
void init_lcd(void)
{
	// return home
	lcd_command( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	lcd_command( 0x28 );
	// display: on, cursor off, blinking off
	lcd_command( 0x0C );
	// entry mode: cursor to right, no shift
	lcd_command( 0x06 );
	// RAM adress: 0, first position, line 1
	lcd_command( 0x80 );
}

void lcd_writeChar( unsigned char dat )
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}void lcd_command ( unsigned char dat )
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x08; // data (RS=0),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x08; // data (RS=0),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}