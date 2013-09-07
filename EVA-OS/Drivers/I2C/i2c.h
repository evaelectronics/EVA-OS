/*
 * i2c.h
 *
 * Created: 9/6/2013 12:34:09 AM
 *  Author: Elmar
 */ 

#ifndef I2C_H_
#define I2C_H_

void i2c_setUp(uint32_t twi_address);
void i2c_setSpeed(uint32_t speed, uint32_t mClk);
void i2c_sendByte(uint8_t data, uint8_t address);
void i2c_sendBytes(uint8_t * data, uint8_t size, uint8_t address);
uint8_t i2c_receiveByte(uint8_t address);
void i2c_receiveBytes(uint8_t * data, uint8_t size, uint8_t address);


#endif /* I2C_H_ */