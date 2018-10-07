/*
 * detect.c
 *
 * Created: 14/09/2018 10:17:36 PM
 *  
 */ 

// Definitions
#define PHOTODIODE1 0b011 //PC3
#define PHOTODIODE2 0b010  //PC2
#define PHOTOTRANSISTOR1 0b001 //PC1
#define PHOTOTRANSISTOR2 0b000 //PC0

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

	/*TCCR1A=(0<<COM1B0)|(1<<WGM10)|(1<<WGM11)|(1<<COM1B1);
	TCCR1B=(0<<CS11)|(1<<WGM12)|(1<<CS10)|(0<<CS02)|(1<<WGM13);
	OCR1A=20000;
	OCR1B=900;*/
	TCCR0A=(1<<COM0B0)|(1<<WGM01)|(1<<WGM00)|(0<<COM0B1);
	TCCR0B=(0<<CS01)|(1<<WGM02)|(1<<CS00)|(1<<CS02);
	OCR0A=18;
	OCR0B=1;
		
}

void sensor_check() {
	//checking all sensors
	for (int i=0;i<sizeof(sensors);i++) {
	
		ADMUX = sensors[i] | (1<<REFS0);
		ADCSRA |= (1<<ADSC);
		while (ADCSRA & (1<<ADSC));
		adcValues[i] = ADC;
		
		//shines brighter than my future
		if (adcValues[i] >= ADCMAX*2.5/5 && ADMUX == ((1<<REFS0)|(sensors[i]))) {
			
			PORTD |= (1<<i);
			
		} else {
			
			PORTD &= ~(1<<i);
			
		}
	}
	if (adcvalues[0]>=1024*2.5/5||adcvalues[1]>=1024*2.5/5)
	movement(adcvalues[0]-adcvalues[1],'h');
	if (adcvalues[2]>=1024*2.5/5||adcvalues[3]>=1024*2.2/5)
	movement(adcvalues[2]-adcvalues[3],'v');
}
void movement(int intensdiff, char plane){
	// insert pmw code here
	// plane meaning rotation about an axis
	//if the top phototrans>=4.6 & the bottom>=4.6 hit
	if(plane=='v'){
		//vertical movement
		/*if (intensdiff>0&& OCR1B>900){

			OCR1B-=2;

		}
		if (intensdiff<0&& OCR1B<2100){

			OCR1B+=2;
		}*/
		if (intensdiff>10&& OCR0B>1){

			OCR0B-=1;

		}
		else if (intensdiff<-10&& OCR0B<2){

			OCR0B+=1;
		}
		else{
		  PORTD|=1<<PORTD4;
		  for(int i=0;i<400;i++);
		}
	}

}