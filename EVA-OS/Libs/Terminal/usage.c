/*
 * usage.c
 *
 * Created: 9-11-2013 1:26:43
 *  Author: Aran Dokoupil
 */ 
/********************************************************************************************************************************************************/       
/*				a quick demo to show the functions of the terminal, due to hardware constraints there is no initialization of the back light			*/
/*									the back light should be enabled separately be it in hardware or in software.										*/
/*  I, the author, can in no way be held responsible for the damages, be it to equipment or personnel, caused by forcing the back light into submission */
/*				running this piece of poorly written software should make the sentence "Hello World!" appear on the screen multiple times.				*/
/*				 once it reaches the bottom of the screen, the above text should scroll up one line to make room for the next data entry				*/
/********************************************************************************************************************************************************/ 

#include <sam4s.h>
#include <Display/display.h>
#include <Terminal/terminal.h>
#include <Delay/delay.h>

#define LETTER_DELAY 100 /**< \brief The delay time between printing letters*/

/**
 * \brief Application entry point (sometimes).
 *
 * \return Unused (ANSI-C compatibility).
 */
int /*terminal_*/main(void) //comment "terminal_" to see the magic happen.
{			
    /* Initialize the SAM system */
	SystemInit();
	WDT->WDT_MR = WDT_MR_WDDIS; //disable watchdog
 	pinDefinitions(); //set IO pins in correct state
 	display_init();	 //initialize the display
	terminal_init(); //initialize the terminal

    while(1){		
		terminal_placeFormatedLetter('H',TEXTCOLOR); //place a H
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('e',TEXTCOLOR); //place a e
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('l',TEXTCOLOR); //place a l
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('l',TEXTCOLOR); //place a l
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('o',TEXTCOLOR); //place a o
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter(' ',TEXTCOLOR); //place a  
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('W',TEXTCOLOR); //place a W
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('o',TEXTCOLOR); //place a o
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('r',TEXTCOLOR); //place a r
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('l',TEXTCOLOR); //place a l
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('d',TEXTCOLOR); //place a d
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter('!',TEXTCOLOR); //place a !
		display_screenRefresh();					 //make it visible
		delay_ms(LETTER_DELAY);						 //wait a moment to take it all in
		terminal_placeFormatedLetter(' ',TEXTCOLOR); //place a 		
		display_screenRefresh();					  //make it visible
		delay_ms(LETTER_DELAY);						  //wait a moment to take it all in
		delay_ms(LETTER_DELAY);						  //wait an additional moment to take it aaaaaallll in
    }
}

