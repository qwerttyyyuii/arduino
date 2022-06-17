#include "RTClib.h"
#define DEBUG false

// util.ino
void _printf(const char *s, ...);

class Process {
public:
	boolean run;
	unsigned char cnt;
	unsigned char MAX_PROCESS;
	unsigned int currTime;
	unsigned int prevTime;
	unsigned int resetTime;
	const char* name;
	void (*fp)(Process *);

	void Initailize(boolean run_t, unsigned char cnt_t, unsigned char maxpro_t, unsigned int ct_t, unsigned int pt_t, unsigned int rst_t, const char* str_t, void (*fp_t)(Process *));
	void Thread(void);
	void Kill(void);
};

// rururu.ino
void dosomething05(Process *p);
void dosomething10(Process *p);
void InputFunc(Process *p);
void RTCProcess(Process *p);

void Command(String str);