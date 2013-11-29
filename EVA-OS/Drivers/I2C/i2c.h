/*
 * i2c.h
 *
 * Created: 9/6/2013 12:34:09 AM
 *  Author: Elmar
 */ 

#ifndef I2C_H_
#define I2C_H_

#include <sam4s.h>
#include <component/twi.h>

void i2c_setUp(Twi * twi_address);
void i2c_setSpeed(uint32_t speed, uint32_t mClk);
void i2c_sendByte(uint8_t data, uint8_t address);
void i2c_sendBytes(uint8_t * data, uint8_t size, uint8_t address);
uint8_t i2c_receiveByte(uint8_t address);
void i2c_receiveBytes(uint8_t * data, uint8_t size, uint8_t address);
void i2c_writeReg(uint8_t address, uint8_t reg, uint8_t val);
uint8_t i2c_readRegister(uint8_t address, uint8_t reg);


#endif /* I2C_H_ */