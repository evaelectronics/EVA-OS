/*
 * pressure.c
 *
 * Created: 11/12/2013 6:38:01 PM
 *  Author: Elmar
 */ 
#include <libs/Pressure/pressure.h>

void pressure_init()
{
	i2c_writeReg(PRESSURE_ADDRESS,0x26,0xB8);		//
	i2c_writeReg(PRESSURE_ADDRESS,0x13,0x07);		//
	i2c_writeReg(PRESSURE_ADDRESS,0x26,0xB9);		//
}

void pressure_temperature()
{
	i2c_readRegister(PRESSURE_ADDRESS,0x04);		//Most significant
	i2c_readRegister(PRESSURE_ADDRESS,0x05);		//Least significant
}