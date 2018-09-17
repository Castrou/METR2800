/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include <avr/io.h>
#define PHOTODIODE1 0b101 //PC5
#define PHOTODIODE2 0b100  //PC4
#define PHOTOTRANSISTOR1 0b011 //PC3
#define PHOTOTRANSISTOR2 0b010 //PC2
int sensors[4]={PHOTODIODE1,PHOTODIODE2,PHOTOTRANSISTOR1,PHOTOTRANSISTOR2};
int adcvalues[4];
int main (void)
{
	ADCSRA|=(1<<ADEN);
	DDRD|=(1<<DDD0)|(1<<DDD1)|(1<<DDD2)|(1<<DDD3);
	ADMUX |= (1<<REFS0);
		ADMUX|=1<<MUX2;
	int ledlights[4]={DDD0,DDD1,DDD2,DDD3};
	while(true){
	//checking all sensors
		for (int i=0;i<sizeof(sensors);i++)
		{
			
			ADMUX=sensors[i]|(1<<REFS0);
			ADCSRA|=1<<ADSC;
			while(ADCSRA & (1<<ADSC));
			adcvalues[i]=ADC;
			//shines brighter than my future
			if (adcvalues[i]>=1024*2.2/5&& ADMUX==((1<<REFS0)|(sensors[i])))
			{
				PORTD|=1<<i;
			}
			else{
				PORTD&=~(1<<i);
			}
		}
		/*
		ADMUX=1<<REFS0;
		ADMUX|=sensors[0];
		ADCSRA|=1<<ADSC;
		
		while(ADCSRA & (1<<ADSC));
		if (ADC>=1024*2.2/5&& ADMUX==((1<<REFS0)|(sensors[0])))
		{
			PORTD|=1<<ledlights[0];
		}
		else{
			PORTD&=~(1<<ledlights[0]);
		}
		ADMUX=1<<REFS0;
		ADMUX|=sensors[2];
		ADCSRA|=1<<ADSC;
		while(ADCSRA & (1<<ADSC));
		if (ADC>=1024*2.2/5&& ADMUX==((1<<REFS0)|(sensors[2])))
		{
			//PORTD|=1<<ledlights[2];
		}
		else{
			PORTD&=~(1<<ledlights[2]);
		}*/
		//PORTD=1<<PORTD1;
		}
	/* Insert system clock initialization code here (sysclk_init()). */



	/* Insert application code here, after the board has been initialized. */
}
