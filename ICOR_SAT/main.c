/*
 * ICOR_SAT.c
 *
 * Created: 14/09/2018 10:16:17 PM
 * Author : Cameron, Bryan, Juan, Victor
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

// Peripheral Drivers
#include <detect.h>
#include <motor.h>
#include <servo.h>
#include <util.h>

//Sets clockspeed of Atmega385 and enable delay functions
#define F_CPU 8000000UL
#include <util/delay.h>

/* Initialise function
 * param: None
 * return: None
 */
void init(void) {
	
	init_motor();
	init_detection();
	init_servo();
	
}

int main(void)
{
	
	
    /* main loop */
    while (1) {
		
		
	}
}

