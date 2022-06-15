#include <Arduino.h>
#include "rururu.h"
// *.cpp로 쓸때는 사용해야함

void dosomethingS10(Process *p) {
	_printf("%d ", p->resetTime);
}

void dosomethingtest(Process *p) {
	switch(p->cnt) {
		case 0:			
			break;
		case 1:
			break;
	}
}

void dosomething10(Process *p) {	
	switch(p->cnt) {
		case 0:
			digitalWrite(LED_BUILTIN, HIGH);		
			break;
		case 1:	
			digitalWrite(LED_BUILTIN, LOW);			
			break;
	}
}

void dosomething05(Process *p) {
	switch(p->cnt) {
		case 0:
			digitalWrite(10, HIGH);		
			break;
		case 1:	
			digitalWrite(10, LOW);
			break;
	}
}

void dosomethingC10(Process *p) {
	_printf("%s ", "C10C10 C10C10 C10C10");
}