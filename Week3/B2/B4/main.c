#include <avr/io.h>
#include <avr/interrupt.h>
void InitTimer0(){
	SREG_I_bit = 1;
	OCR0 = 233;
	TCCR0 = 0x28;
	TCCR0 |= 0x05;
	OCIE0_bit = 1;
}

void Timer0Overflow_ISR() IVT_ADDR_TIMER0_COMP {
	// Timer event code
}


int main(void)
{
	InitTimer0();
	return 1;
}