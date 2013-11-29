/*
 * i2c.c
 *
 * Created: 9/6/2013 12:33:32 AM
 *  Author: Elmar
 */ 
#include <sam4s.h>
#include <TinyPrintf/printf.h>

static Twi *twi;

void i2c_setUp(Twi * twi_address)
{
	printf("Setting up i2c...\n");
	twi = twi_address;
	PMC->PMC_PCER0 = 1 << ID_TWI0;		// Enable TWI clock
	twi->TWI_IDR = ~0UL;				/* Disable TWI interrupts */
	twi->TWI_SR;						/* Dummy read in status register */
	twi->TWI_CR = TWI_CR_SWRST;			/* Reset TWI peripheral */
	twi->TWI_RHR;						/* Set SWRST bit to reset TWI peripheral */
	twi->TWI_CR = TWI_CR_MSDIS;			/* Set Master Disable bit and Slave Disable bit */
	twi->TWI_CR = TWI_CR_SVDIS;	
	twi->TWI_CR = TWI_CR_MSEN;			/* Set Master Enable bit */


	twi->TWI_CWGR = TWI_CWGR_CHDIV(73) | TWI_CWGR_CLDIV(73) | TWI_CWGR_CKDIV(1);	// 400khz
																					// (1/(400000))/2 = ((x*2^1)+4)*(1/120000000); x = 73
}


void i2c_sendByte(uint8_t data, uint8_t address)
{
	twi->TWI_CR = TWI_CR_MSEN | TWI_CR_SVDIS;									
	twi->TWI_MMR = TWI_MMR_DADR(address);				
	twi->TWI_THR = data;
	twi->TWI_CR = TWI_CR_STOP;
	while ((twi->TWI_SR & TWI_SR_TXRDY) == 1);
	while ((twi->TWI_SR & TWI_SR_TXCOMP) == 1);
}

void i2c_writeReg(uint8_t address, uint8_t reg, uint8_t val)
{
	twi->TWI_CR = TWI_CR_MSEN | TWI_CR_SVDIS;
	twi->TWI_MMR = TWI_MMR_DADR(address) | TWI_MMR_IADRSZ_1_BYTE;
	twi->TWI_MMR &= ~(TWI_MMR_MREAD);
	twi->TWI_IADR = reg;
	twi->TWI_THR = val;
	twi->TWI_CR = TWI_CR_STOP;
	while ((twi->TWI_SR & TWI_SR_TXRDY) == 0);
	while ((twi->TWI_SR & TWI_SR_TXCOMP) == 0);
}

void i2c_sendBytes(uint8_t *data, uint8_t size, uint8_t address)
{
	uint8_t cnt = size;
	twi->TWI_MMR = 0;
	twi->TWI_MMR = TWI_MMR_MREAD | TWI_MMR_DADR(address);
	twi->TWI_IADR = 0;
	/* Send all bytes */
	while (cnt > 0) {
		//status = twi->TWI_SR;
		if (!(twi->TWI_SR & TWI_SR_TXRDY)) {
			continue;
		}
		twi->TWI_THR = *data++;
		cnt--;
	}
	twi->TWI_CR = TWI_CR_STOP;
	while (!(twi->TWI_SR & TWI_SR_TXCOMP)) {
	}
	twi->TWI_SR;
}

uint8_t i2c_receiveByte(uint8_t address)
{
	uint8_t data = 0;
	twi->TWI_MMR = TWI_MMR_DADR(address) | TWI_MMR_MREAD;
	twi->TWI_CR = TWI_CR_START;
	twi->TWI_CR = TWI_CR_STOP;
	while((twi->TWI_SR & TWI_SR_RXRDY) == 0);
	data = twi->TWI_RHR;
	while((twi->TWI_SR & TWI_SR_TXCOMP) == 0);
	return data;
}

uint8_t i2c_readRegister(uint8_t address, uint8_t reg)
{
	uint8_t data = 0;
	twi->TWI_MMR = TWI_MMR_DADR(address) | TWI_MMR_MREAD | TWI_MMR_IADRSZ_1_BYTE;
	twi->TWI_IADR = reg;
	twi->TWI_CR = TWI_CR_START | TWI_CR_STOP;
	while((twi->TWI_SR & TWI_SR_RXRDY) == 0);
	data = twi->TWI_RHR;
	while((twi->TWI_SR & TWI_SR_TXCOMP) == 0);
	return data;
}

void i2c_sendAddress(uint8_t address)
{
	twi->TWI_MMR = TWI_MMR_DADR(address);
	while((twi->TWI_SR & TWI_SR_TXCOMP) == 0);
}



void i2c_readRegisterMultiple(uint8_t address, uint8_t reg, uint8_t * data, uint8_t size)
{
	uint8_t i = 0;
	twi->TWI_MMR = TWI_MMR_DADR(address) | TWI_MMR_MREAD | TWI_MMR_IADRSZ_1_BYTE;
	twi->TWI_CR = TWI_CR_START;
	while(i < ( size - 1 )){
		while((twi->TWI_SR & TWI_SR_RXRDY) == 0);
		data[i] = twi->TWI_RHR;
		i++;
	}
	twi->TWI_CR = TWI_CR_STOP;
	while((twi->TWI_SR & TWI_SR_RXRDY) == 0);
	data[i] = twi->TWI_RHR;
	while((twi->TWI_SR & TWI_SR_TXCOMP) == 0);
}
