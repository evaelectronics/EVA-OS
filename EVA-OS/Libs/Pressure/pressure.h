/*
 * pressure.h
 *
 * Created: 11/12/2013 6:38:12 PM
 *  Author: Elmar
 */ 


#ifndef PRESSURE_H_
#define PRESSURE_H_

#include <Drivers/I2C/i2c.h>
#define PRESSURE_ADDRESS 0x60


void pressure_init();
void pressure_temperature();



#endif /* PRESSURE_H_ */