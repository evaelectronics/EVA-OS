/*
 * main.c
 *
 * Created: 8/18/2013 5:25:04 PM
 *  Author: Elmar
 */ 

#include "sam.h"

void main(void)
{
		SystemInit();										//Initialize the SAM system
		WDT->WDT_MR = WDT_MR_WDDIS;							//Disable watchdog
		
		PIOC->PIO_PER = (1<<24)|(1<<25);			// enable register
		PIOC->PIO_OER = (1<<24)|(1<<25);			// Output Enable Register
		PIOC->PIO_SODR	= (1<<24)|(1<<25);		// Set output data register
		
		while (1) {
			PIOC->PIO_PER = (1<<24)|(1<<25);			// enable register
			PIOC->PIO_PDR = (1<<24)|(1<<25);			// enable register
		}
}