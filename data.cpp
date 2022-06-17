#include <Arduino.h>

const char* daysOfTheWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

String list[] = {"reset", "list", "time", "kill"};
size_t list_size = sizeof(list) / sizeof(String);

const char* commandstr[] = {
	"Reset : RTC Time reset",
	"List : Command List",
	"Time : Current Time",
	"Kill : Process Kill",
};
size_t cmdstr_size = sizeof(commandstr) / sizeof(char *);