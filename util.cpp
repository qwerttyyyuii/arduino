#include <Arduino.h>
#include "rururu.h"
// *.cpp로 쓸때는 사용해야함
boolean mutex = true;

void _printf(const char *s, ...) {
	va_list args; 
	va_start(args, s); 
	int n = vsnprintf(NULL, 0, s, args); //문자열 길이를 먼저 구함    
	char *str = new char[n+1]; //메모리 할당    
	vsprintf(str, s, args); //실제 내용을 복사    
	va_end(args); 
	Serial.print(str); 
	delete [] str; //메모리 해제
}

void Process::Properties(boolean run_t, unsigned char cnt_t, unsigned char maxpro_t, unsigned int ct_t, unsigned int pt_t, unsigned int rst_t, const char* str_t, void (*fp_t)(Process *)) {
	this->run = run_t;
	this->cnt = cnt_t;
	this->MAX_PROCESS = maxpro_t;
	this->currTime = ct_t;
	this->prevTime = pt_t;
	this->resetTime = rst_t;
	this->name = str_t;
	this->fp = fp_t;
}

void Process::Start() {
	if (this->run == false) return;
	this->currTime = millis();

	if (this->currTime >= this->prevTime + this->resetTime) {
		if (mutex) {
			mutex = false;
#ifdef DEBUG
			if (this->cnt || this->MAX_PROCESS) 
				_printf("PID: %s-%02d // ", this->name, this->cnt);	
			else
				_printf("PID: %s-00 // ", this->name);
#endif
			this->fp(this);
		}
#ifdef DEBUG
		Serial.println();
#endif		
		if (this->cnt || this->MAX_PROCESS) {
			this->cnt++;
			if (this->cnt == this->MAX_PROCESS) this->cnt = 0;
		}	
		this->prevTime = this->currTime;
		mutex = true;
	}
}

void Process::Kill(void) {
	this->run = false;;
	if(this) free(this);
}

Process::~Process(void) {
	//if (buffer) free(buffer);
}