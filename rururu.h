<<<<<<< HEAD
#define DEBUG

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
		
	void Start(void);
	void Kill(void);
	void Properties(boolean run_t, unsigned char cnt_t, unsigned char maxpro_t, unsigned int ct_t, unsigned int pt_t, unsigned int rst_t, const char* str_t, void (*fp_t)(Process *));
	~Process(void);	
};

// rururu.ino
void dosomethingtest(Process *p);
void dosomething05(Process *p);
void dosomething10(Process *p);
void dosomethingS10(Process *p);
=======
#define DEBUG

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
		
	void Start(void);
	void Kill(void);
	void Properties(boolean run_t, unsigned char cnt_t, unsigned char maxpro_t, unsigned int ct_t, unsigned int pt_t, unsigned int rst_t, const char* str_t, void (*fp_t)(Process *));
	~Process(void);	
};

// rururu.ino
void dosomethingtest(Process *p);
void dosomething05(Process *p);
void dosomething10(Process *p);
void dosomethingS10(Process *p);
>>>>>>> f3b56f0e4a032da3622dd018c760d22198b9fd24
void dosomethingC10(Process *p);