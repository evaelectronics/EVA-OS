/*
 * time.h
 *
 * Created: 11/28/2013 11:20:48 PM
 *  Author: Elmar
 */ 


#ifndef TIME_H_
#define TIME_H_

#include <sam4s.h>

typedef enum {
	JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
} Month;

typedef enum {
	MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
} Day;

typedef struct {
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t twentyFour;
} Time;

typedef struct {
	Day day;
	Month month;
	uint8_t year;
} Date;


uint32_t time_getTimeDifference(Time * time1, Time * time2);

#endif /* TIME_H_ */