/*
 * Functions.c
 *
 * Created: 11-3-2020 21:26:03
 *  Author: mjays
 */ 
#include <util/delay.h>

void functions_wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}
