/*
* usage.c
*
* Created: 11/16/2013 4:41:26 PM
*  Author: Elmar
*/

#include <Drivers/Buttons/buttons.h>
#include <Drivers/RTC/rtc.h>
#include <Util/TinyPrintf/printf.h>

typedef enum{
	HOURS, MINUTES, SECONDS, DONE
} TestType;

void polExample()
{
	printf("Starting poll example");	
	TestType testType = HOURS;
	Time tempTime;
	tempTime.hours = 0;
	tempTime.minutes = 0;
	tempTime.seconds = 0;
	printf("\nSet hours please");	
	while (testType != DONE){
		if(button_isTyped(BUTTONS_DOWN)){
			switch (testType){
				case HOURS:
					if(tempTime.hours == 0)
						tempTime.hours= 23;
					else
						tempTime.hours--;
				break;
				case MINUTES:
					if(tempTime.minutes == 0)
						tempTime.minutes = 59;
					else
						tempTime.minutes--;
				break;
				case SECONDS:
					if(tempTime.seconds == 0)
						tempTime.seconds = 59;
					else
						tempTime.seconds--;
				break;
				case DONE:
				break;
			}
			printf("\nTime: %d:%d:%d",tempTime.hours, tempTime.minutes, tempTime.seconds);	
		}
		if(button_isTyped(BUTTONS_UP)){
			switch (testType){
				case HOURS:
					tempTime.hours++;
					tempTime.hours %= 24;
				break;
				case MINUTES:
					tempTime.minutes++;
					tempTime.minutes%= 60;
				break;
				case SECONDS:
					tempTime.seconds++;
					tempTime.seconds%= 60;
				break;
				case DONE:
				break;
			}
			printf("\nTime: %d:%d:%d",tempTime.hours, tempTime.minutes, tempTime.seconds);	
		}
		if(button_isTyped(BUTTONS_SELECT)){
			switch (testType){
				case HOURS:
					printf("\nSet minutes please");	
					testType = MINUTES;
				break;
				case MINUTES:
					printf("\nSet seconds please");	
					testType = SECONDS;
				break;
				case SECONDS:
					printf("\nDone setting time!");	
					testType = DONE;
				break;
				case DONE:
				break;
			}
		}
		buttons_update();
	}
	rtc_setTime(&tempTime);
	//free(tempTime);
}