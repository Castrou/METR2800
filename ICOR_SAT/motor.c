/*
 * motor.c
 *
 * Created: 14/09/2018 10:20:34 PM
 *  Author: Juan
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

//Sets clockspeed of Atmega385 and enable delay functions
#define F_CPU 8000000UL
#include <util/delay.h>

/*
*
*      Motor Control
*
* | Input_1 | Input_2 | Motor Function
* -------------------------------------
* |  low    |   low   |     Stop
* -------------------------------------
* |  high   |   low   |Turn Anti-Clockwise
* -------------------------------------
* |   low   |  high   | Turn Clockwise
* -------------------------------------
* |  high   |  high   |     Stop
*
*/

void init_motor(void) {
	
	//Set up initial parameters
	DDRB = 0x00; //Clear all pins
	DDRB |= (1<<1)|(1<<2); //enable outputs
	
	//Setup timer with PWM
	TCCR1A |= (1<<COM1A1)|(1 << WGM11) | (1 << WGM10)|(1<<COM1B1);
	TCCR1B |= (1<<CS11);
	//start in off state
	OCR1A = 0;
	OCR1B = 0;
	
}

