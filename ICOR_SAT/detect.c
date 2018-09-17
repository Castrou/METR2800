/*
 * detect.c
 *
 * Created: 14/09/2018 10:17:36 PM
 *  
 */ 

// Definitions
#define PHOTODIODE1 0b101 //PC5
#define PHOTODIODE2 0b100  //PC4
#define PHOTOTRANSISTOR1 0b011 //PC3
#define PHOTOTRANSISTOR2 0b010 //PC2

#define ADCMAX 1024

// Global Variables
int sensors[4] = {PHOTODIODE1, PHOTODIODE2, PHOTOTRANSISTOR1, PHOTOTRANSISTOR2};
int adcValues[4];

// Functions
void init_detection() {
	
	ADCSRA	|= (1<<ADEN);
	DDRD	|= (1<<DDD0)|(1<<DDD1)|(1<<DDD2)|(1<<DDD3);
	ADMUX	|= (1<<REFS0);
	ADMUX	|= (1<<MUX2);
	
	int ledLights[4] = {DDD0, DDD1, DDD2, DDD3};
		
}

void sensor_check() {
	//checking all sensors
	for (int i=0;i<sizeof(sensors);i++) {
	
		ADMUX = sensors[i] | (1<<REFS0);
		ADCSRA |= (1<<ADSC);
		while (ADCSRA & (1<<ADSC));
		adcValues[i] = ADC;
		
		//shines brighter than my future
		if (adcValues[i] >= ADCMAX*2.2/5 && ADMUX == ((1<<REFS0)|(sensors[i]))) {
			
			PORTD |= (1<<i);
			
		} else {
			
			PORTD &= ~(1<<i);
			
		}
	}
}