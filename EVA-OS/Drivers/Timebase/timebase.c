/*
 * timebase.c
 *
 * Created: 3-9-2013 23:30:14
 *  Author: P
 */ 


#include <sam4s.h>


volatile uint32_t timebase = 0;

void timebase_Init_Timer(){	

	PMC->PMC_PCER0 = (1 << ID_TC0);												//Enable peripheral clock TC0
	TC0->TC_CHANNEL[0].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK2 | TC_CMR_CPCTRG;		// Use timer clock 2 (MCK/8)
	TC0->TC_CHANNEL[0].TC_RC  = 15000;											// Set RC value
	TC0->TC_CHANNEL[0].TC_IER = TC_IER_CPCS;									// Enable interrupt on RC compare - Interrupt Enable Register
	TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;					// Enable counter and enable software trigger
	
	NVIC_DisableIRQ(TC0_IRQn);		//Not actually needed
	NVIC_ClearPendingIRQ(TC0_IRQn);	//Not actually needed
	NVIC_SetPriority(TC0_IRQn, 9);
	NVIC_EnableIRQ(TC0_IRQn);	
}


void TC0_Handler(void)
{	
	volatile uint32_t status_Register = TC0->TC_CHANNEL[0].TC_SR;	
	timebase++;	
}