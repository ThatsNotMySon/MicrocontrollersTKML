#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

typedef enum{P5, P6, P7}MPORT;
typedef enum{S1, S2,S3, START, END}STATE;
	
void doS1();
void doS2();
void doS3();
void doStart();
void doEnd();

STATE currentState = START;

typedef struct {
	void (*current)(void);
	void (*port)(void);
	STATE destinationState;
} STATE_TRANSITION;

// x = 5 states and y = 3 ports
STATE_TRANSITION fsm[3][5] = {
	{
		{
			S1, P5, S2
		},
		{
			S2, P5, S3		
		},
		{
			S3, P5, END
		},
		{
			START, P5, S2
		},
		{
			END, P5, END
		}
	},
	{
		{
			S1, P6, S1
		},
		{
			S2, P6, S1		
		},
		{
			S3, P6, END
		},
		{
			START, P6, S1
		},
		{
			END, P6, END
		}
	},
	{
		{
			S1, P7, START
		},
		{
			S2, P7, START		
		},
		{
			S3, P7, START
		},
		{
			START, P7, START
		},
		{
			END, P7, START
		}
	}
};
	
	
void doStart(){
	PORTD = 0x01;
}
	
void doS1(){
	PORTD = 0x02;
}

void doS2(){
	PORTD = 0x04;
}

void doS3(){
	PORTD = 0x08;
}

void doEnd(){
	PORTD = 0x00;
}

void handleInput(MPORT mPort){
	currentState = fsm[mPort][currentState].destinationState;
	
	switch(currentState){
		case START:
			doStart();
			break;
		case S1:
			doS1();
			break;
		case S2:
			doS2();
			break;
		case S3:
			doS3();
			break;
		case END:
			doEnd();
			break;
	}
}


void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

int main (void)
{
	DDRD = 0x0F; //Eerste vier bits is output en laatste vier is input
	
	handleInput(P7);
	while (1)
	{
		if (PIND & 0x20) //PD5
		{
			handleInput(P5);
	
		} 
		else if (PIND & 0x40) //PD6
		{
			handleInput(P6);
			
		} 
		else if (PIND & 0x80) //PD7
		{
			handleInput(P7);
		}
		wait(250);
	}
	
	return 1;
}