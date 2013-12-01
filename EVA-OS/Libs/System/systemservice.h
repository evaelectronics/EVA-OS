/*
 * systemservice.h
 *
 * Created: 11/29/2013 1:01:43 AM
 *  Author: Elmar
 */ 


#ifndef SYSTEMSERVICE_H_
#define SYSTEMSERVICE_H_

#include <sam4s.h>
#include <Util/Time/time.h>
#include <PinNames.h>
#include <stdlib.h>

uint8_t toDec(uint8_t bcd);
uint8_t toBcd(uint8_t number);
void system_init();



#endif /* SYSTEMSERVICE_H_ */