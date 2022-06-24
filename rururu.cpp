#include <Arduino.h>
#include "rururu.h"
// *.cpp로 쓸때는 사용해야함

extern RTC_DS1307 RTC_DS;
extern String list[];
extern const char *commandstr[], *daysOfTheWeek[];
extern size_t cmdstr_size, list_size;

void Find_CRLF(char *str, size_t size, unsigned int *crlf);

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

void InputFunc(Process *p) {
	if (Serial.available()) {
		//byte b = Serial.read();
		//_printf("0x%02X", b);		
		String Str = Serial.readString();		
		String cl_cut;
		
		char *chararray = (char*)malloc(sizeof(char*) * Str.length());
		if (chararray == NULL) {
			_printf("malloc failed\n");
		}
		else {
			unsigned int crlf[2] = {0,};
			unsigned int repeat = 0;
			Str.toCharArray(chararray, Str.length());		
			Find_CRLF(chararray, Str.length(), crlf); 
			
			if ((crlf[0] == 0) && crlf[1]) {				
				repeat = crlf[1];
			} 
			else if (crlf[0] && (crlf[1] == 0)) {
				repeat = crlf[0];
			}
			else if (crlf[0] && crlf[1]) {				
				repeat = max(crlf[0], crlf[1]);
			}
			else if ((crlf[0] == 0) && (crlf[1] == 0)) {
				repeat = 0;
			}

			//for (uint32_t i = 0; i < strlen(chararray); i++) 
			Serial.print("Str: ");
			Serial.print(Str);
			Serial.println();
			_printf("len %d, %d, %d\n", Str.length(), crlf[0], crlf[1]);
			cl_cut = Str.substring(0, Str.length() - crlf[0] - crlf[1]); // CR LF 2바이트 자르기
			Serial.print(">> " + cl_cut);
			
			//Command(cl_cut);

			for (uint32_t i = 0; i < repeat; i++) 
				Serial.print(">> \n");
			free(chararray);
		}		
	}
}

void Command(String str) {
	str.toLowerCase();
	for (unsigned int i = 0; i < list_size; i++)
		list[i].toLowerCase();

	if (str.equals(list[0])) {	
		RTC_DS.adjust(DateTime(2022, 6, 17, 13, 24, 35));
		Serial.println("RTC Time reset");
	}
	else if (str.compareTo(list[1]) == 0) {
		for(unsigned int i = 0; i < cmdstr_size; i++)
			Serial.println(commandstr[i]);
		Serial.println();
	}
	else if (str.equals(list[2])) {
		DateTime now = RTC_DS.now();
		_printf("%d/%02d/%02d %s %02d:%02d:%02d\n", now.year(), now.month(), now.day(), daysOfTheWeek[now.dayOfTheWeek()], now.hour(), now.minute(), now.second());
	}
	else if (str.equals(list[3])) {
		Serial.println("Kill Process");
	}
	else if (str.equals(list[4])) {
		//Serial.print();
	}
	else {
		Serial.println("Invalid command");
		Serial.println(commandstr[1]);
		Serial.println();
	}
}

void RTCProcess(Process *p) {
	//DateTime now = RTC_DS.now();
	//_printf("%d/%02d/%02d %s %02d:%02d:%02d", now.year(), now.month(), now.day(), daysOfTheWeek[now.dayOfTheWeek()], now.hour(), now.minute(), now.second());
	//_printf("\n%02d:%02d:%02d -> ", now.hour(), now.minute(), now.second());
#if !DEBUG
	//Serial.println();
#endif	
}

void Find_CRLF(char *str, size_t size, unsigned int* crlf) {	
	size_t i = 0;
	for (i = 0; i < size; i++) {
		if (str[i] == '\0') {
			//_printf("NULL\n");			
		}
		if (str[i] == '\n') {
			crlf[0]++;
		}
		if (str[i] == '\r') {
			crlf[1]++;
		}		
	}	
}