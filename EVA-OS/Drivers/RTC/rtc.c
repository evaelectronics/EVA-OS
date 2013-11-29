/*
* rtc.c
*
* Created: 11/13/2013 8:45:18 PM
*  Author: Elmar
*/

#include <Drivers/RTC/rtc.h>

static void rtc_parseDate(char * input, Date * date);

void rtc_setUp()
{
	i2c_writeReg(RTC_ADDRESS, 0x03, 0x99);	//write to ram
	i2c_writeReg(RTC_ADDRESS, 0x00, 0x01); // cap selection
}

void rtc_setTime(Time * time)
{
	i2c_writeReg(RTC_ADDRESS,0x04,toBcd(time->seconds));
	i2c_writeReg(RTC_ADDRESS,0x05,toBcd(time->minutes));
	i2c_writeReg(RTC_ADDRESS,0x06,toBcd(time->hours));
}

void rtc_setDate(Date * date)
{
	i2c_writeReg(RTC_ADDRESS,0x07,date->day);
	i2c_writeReg(RTC_ADDRESS,0x09,date->month);
	i2c_writeReg(RTC_ADDRESS,0x0A,date->year);
}

static void rtc_parseDate(char * input, Date * date)
{
	date->year = (input[9]-(uint8_t)'0') * 10 + (input[10]-(uint8_t)'0');
	date->day = (input[7]-(uint8_t)'0');
	if((input[6] > (uint8_t)'0') && (input[6] < (uint8_t)'9')){
		date->day += (input[6]-(uint8_t)'0')*10;
	}
	switch (input[0]){
		case 'J':
		switch (input[1]){
			case 'a':
			date->month = JANUARY;
			break;
			default:
			if(input[2]=='n'){
				date->month = JUNE;
				} else {
				date->month = JULY;
			}
			break;
		}
		break;
		case 'F':
		date->month = FEBRUARY;
		break;
		case 'M':
		if(input[2]=='r'){
			date->month = MARCH;
			}else{
			date->month = MAY;
		}
		break;
		case 'A':
		if(input[1]=='p'){
			date->month = APRIL;
			} else {
			date->month = AUGUST;
		}
		break;
		case 'S':
		date->month = SEPTEMBER;
		break;
		case 'O':
		date->month = OCTOBER;
		break;
		case 'N':
		date->month = NOVEMBER;
		break;
		case 'D':
		date->month = DECEMBER;
		break;
	}
}

void rtc_loadFromCompilationTime()
{
	Time * newTime = malloc(sizeof(Time) );
	Date * newDate = malloc(sizeof(Date) );
	rtc_parseDate(__DATE__, newDate);
	newTime->seconds = (__TIME__[6] - 48) * 10 + __TIME__[7] - ((uint8_t)'0') + 3;
	newTime->minutes = (__TIME__[3] - 48) * 10 + __TIME__[4] - ((uint8_t)'0');
	newTime->hours = (__TIME__[0] - 48) * 10 + __TIME__[1] - ((uint8_t)'0');
	rtc_setTime(newTime);
	rtc_setDate(newDate);
	free(newDate);
	free(newTime);
}

uint8_t rtc_isReset()
{
	return 0x99 != i2c_readRegister(RTC_ADDRESS,0x03);
}


void rtc_setAlarm(Time * time)
{
	
}

void rtc_refresh()
{
	rtc_currentTime.hours = toDec(0x3F & i2c_readRegister(RTC_ADDRESS,0x06));
	rtc_currentTime.minutes = toDec(0x7F & i2c_readRegister(RTC_ADDRESS,0x05));
	rtc_currentTime.seconds = toDec(0x7F & i2c_readRegister(RTC_ADDRESS,0x04));
}

uint8_t rtc_numberToMonth(uint8_t number, char * month)
{
	switch (number){
		case JANUARY:
		month = "January";
		return 7;
		case FEBRUARY:
		month = "February";
		return 8;
		case MARCH:
		month = "March";
		return 5;
		case APRIL:
		month = "April";
		return 5;
		case MAY:
		month = "May";
		return 3;
		case JUNE:
		month = "June";
		return 4;
		case JULY:
		month = "July";
		return 4;
		case AUGUST:
		month = "Augustus";
		return 8;
		case SEPTEMBER:
		month = "September";
		return 9;
		case OCTOBER:
		month = "October";
		return 7;
		case NOVEMBER:
		month = "November";
		return 8;
		case DECEMBER:
		month = "December";
		return 8;
	}
	return 0;
}

