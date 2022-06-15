<<<<<<< HEAD
#include "rururu.h"

Process P10;
Process P05;
Process test;
Process S10;
Process C10;

void setup(void) {
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)	
	pinMode(10, OUTPUT);	
		
	P10.Properties(true, 0, 2, 0, 0, 1000, "P10", dosomething10);
	P05.Properties(true, 0, 2, 0, 0, 500, "P05", dosomething05);
	test.Properties(true, 0, 2, 0, 0, 333, "TST", dosomethingtest);
	S10.Properties(true, 0, 0, 0, 0, 1000, "S10", dosomethingS10);
	C10.Properties(true, 0, 0, 0, 0, 333, "C10", dosomethingC10);
}

void loop(void) {
	P10.Start();
	P05.Start();
	test.Start();
	S10.Start();
    C10.Start();
=======
#include "rururu.h"

Process P10;
Process P05;
Process test;
Process S10;
Process C10;

void setup(void) {
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)	
	pinMode(10, OUTPUT);	
		
	P10.Properties(true, 0, 2, 0, 0, 1000, "P10", dosomething10);
	P05.Properties(true, 0, 2, 0, 0, 500, "P05", dosomething05);
	test.Properties(true, 0, 2, 0, 0, 333, "TST", dosomethingtest);
	S10.Properties(true, 0, 0, 0, 0, 1000, "S10", dosomethingS10);
	C10.Properties(true, 0, 0, 0, 0, 333, "C10", dosomethingC10);
}

void loop(void) {
	P10.Start();
	P05.Start();
	test.Start();
	S10.Start();
    C10.Start();
>>>>>>> f3b56f0e4a032da3622dd018c760d22198b9fd24
}