#include "rururu.h"

Process P10;
Process P05;
Process KEY;
Process RTC;

RTC_DS1307 RTC_DS;

void setup(void) {
	Serial.begin(115200);
	RTC_DS.begin();
	if (!RTC_DS.isrunning())
		RTC_DS.adjust(DateTime(2022, 6, 17, 13, 24, 35)); // initialize

	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)	
	pinMode(10, OUTPUT);
		
	P10.Initailize(true, 0, 2, 0, 0, 1000, "P10", dosomething10);
	P05.Initailize(true, 0, 2, 0, 0, 500,  "P05", dosomething05);	
	KEY.Initailize(true, 0, 0, 0, 0, 50,   "KEY", InputFunc);
	RTC.Initailize(true, 0, 0, 0, 0, 1000, "RTC", RTCProcess);
	delay(300);
}

void loop(void) {
	P10.Thread();
	P05.Thread();
	KEY.Thread();
	RTC.Thread();
}