/*
 * systemservice.c
 *
 * Created: 11/29/2013 1:01:26 AM
 *  Author: Elmar
 */ 

#include <System/systemservice.h>

void system_init(void)
{
}

uint8_t toBcd(uint8_t number)
{
	return ((number / 10) << 4) | (number % 10);
}

uint8_t toDec(uint8_t bcd)
{
	return (bcd>>4)*10 + (bcd & 0x0F);
}