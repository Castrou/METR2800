/*
 * ICOR_SAT.c
 *
 * Created: 14/09/2018 10:16:17 PM
 * Author : Cameron, Bryan, Juan, Victor
 */ 

#include <avr/io.h>
#include <detect.h>
#include <motor.h>
#include <servo.h>
#include <util.h>

/* Initialise function
 * param: None
 * return: None
 */
void init(void) {
	
	//Detection
	ADCSRA|=(1<<ADEN);
	DDRD|=(1<<DDD0)|(1<<DDD1)|(1<<DDD2)|(1<<DDD3);
	ADMUX |= (1<<REFS0);
	ADMUX|=1<<MUX2;
	
}

int main(void)
{
    /* main loop */
    while (1) {
    
	}
}

