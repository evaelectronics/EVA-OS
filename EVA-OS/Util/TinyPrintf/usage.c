/*
 * usage.c
 *
 * Created: 12-11-2013 0:05:18
 *  Author: Aran Dokoupil
 */ 

/********************************************************************************************************************************************************/
/*					a quick demo to show the functions of printf, due to hardware constraints there is no initialization of the back light				*/
/*									the back light should be enabled separately be it in hardware or in software.										*/
/*  I, the author, can in no way be held responsible for the damages, be it to equipment or personnel, caused by forcing the back light into submission */
/*								running this piece of poorly written software should make multiple formatted sentences appear							*/
/*					 this example code is meant to illustrate the multiple standard and non-standard keyword in our printf implementation				*/
/********************************************************************************************************************************************************/

#include <sam4s.h>
#include <PinNames.h>
#include <Display/display.h>
#include <Delay/delay.h>
#include <Terminal/terminal.h>
#include <Graphical/graphical.h>
#include <TinyPrintf/printf.h>



/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int printf_main(void)
{	
	/* Initialize the SAM system */
	SystemInit();
	WDT->WDT_MR = WDT_MR_WDDIS; //disable watchdog
 	pinDefinitions();
 	display_init(); //initialize the display
	printf_init(NULL, terminal_putc); //initialize printf, use NULL and terminal_putc to print to the display.
	terminal_init(BLACK);	//initialize the terminal, parameter is the background colour, use standard colours or define own by using graphical_createRGBColour(red,green,blue);
	
	printf("Hello world!\n");//print a basic string to the screen, printf automatically refreshes the screen and the default font colour is white.
	delay_ms(1000);
	printf("Printing an int: %d\n", -563); //use the %d keyword to add a numeric variable to the string. The formats supported by this implementation are: 'd' 'u' 'c' 's' 'x' 'X'.
	delay_ms(1000);
	printf("%kPrinting in a colour!\n", YELLOW); //an addition keyword of %k is available to change the colour of the following text.
	delay_ms(1000);
	printf("I'm an %kimportant%k word!\n", RED, WHITE); //multiple %k's can be used to highlight certain words or variables.
	delay_ms(1000);
	printf("Important variable: %k%d%k\n", CYAN, 42, WHITE); 
	
	while(1){
    }
}