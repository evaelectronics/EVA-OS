/*
 * time.c
 *
 * Created: 11/28/2013 11:20:39 PM
 *  Author: Elmar
 */ 

#include <time/time.h>

uint32_t time_getTimeDifference(Time * time1, Time * time2)	//time 1 is the latest
{
	uint32_t secondsTime1 = (time1->hours*3600) + (time1->minutes*60) + (time1->seconds);
	uint32_t secondsTime2 = (time2->hours*3600) + (time2->minutes*60) + (time2->seconds);
	if(secondsTime2 > secondsTime1){
		uint32_t maxTime = ((time1->twentyFour)? 82800 : 39600) + 3599;
		return (maxTime - secondsTime2) + secondsTime1;
	}	
	return secondsTime1 - secondsTime2;
}

void time_setTime(uint8_t hours, uint8_t minutes, uint8_t seconds, Time * time)
{
	if(hours>11)
		time->twentyFour = 1;
	time->hours = hours;
	time->minutes = minutes;
	time->seconds = seconds;
}

/*

23:59:59 <-> 00:00:01



*/