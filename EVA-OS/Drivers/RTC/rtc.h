/*
 * rtc.h
 *
 * Created: 11/13/2013 8:45:28 PM
 *  Author: Elmar
 */ 


#ifndef RTC_H_
#define RTC_H_

#include <sam4s.h>
#include <Libs/System/systemservice.h>
#include <Drivers/I2C/i2c.h>

#define RTC_ADDRESS 0x51

Time rtc_currentTime;
Date rtc_currentDate;

void rtc_setTime(Time * time);
void rtc_setAlarm(Time * time);
void rtc_loadFromCompilationTime();
void rtc_refresh();
void rtc_setUp();
uint8_t rtc_isReset();
uint8_t rtc_numberToMonth(uint8_t number, char * month);




#endif /* RTC_H_ */