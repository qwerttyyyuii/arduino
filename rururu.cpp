#include <Arduino.h>
#include "rururu.h"
// *.cpp로 쓸때는 사용해야함

extern RTC_DS1307 RTC_DS;
extern String list[];
extern const char *commandstr[], *daysOfTheWeek[];
extern size_t cmdstr_size, list_size;

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
		if (Str.equals("\r\n")) {
			// 엔터 몇개 들어왔는지 체크해야함
			int cnt = 0;
			for (int i = 0; i < cnt; i++)
				Serial.print(">> \n");
		}
		else {	
			// 여기도 엔터 많이 들어와도 무시하고 하나만 하게
			cl_cut = Str.substring(0, Str.length() - 2); // CR LF 2바이트 자르기
			Serial.print(">> " + cl_cut + "\n");
			Command(cl_cut);
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