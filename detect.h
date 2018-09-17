#define PHOTODIODE1 0b101 //PC5
#define PHOTODIODE2 0b100  //PC4
#define PHOTOTRANSISTOR1 0b011 //PC3
#define PHOTOTRANSISTOR2 0b010 //PC2
int sensors[4];
int adcvalues[4];
void detect (void);