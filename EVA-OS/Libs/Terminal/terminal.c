/*
 * Terminal.c
 *
 * Created: 25-10-2013 21:05:37
 *  Author: Aran Dokoupil
 */ 

#include <Display/display.h>
#include <Terminal/terminal.h>
#include <Terminal/system_font.h>
 
 /*! \brief Initializes the terminal for use.
 *	
 *	rewrites the screen buffer with the background colour and refreshes the screen
 *  			       
 */
void terminal_init(){	
	for(uint8_t x = 0; x < WIDTH; x++){ //for the height
		for(uint8_t y = 0; y < HEIGHT; y++){ //and width of the screen
			display_writePixel(x,y,BACKGROUNDCOLOR); //write the background colour
		}
	}
	display_screenRefresh();
}


 /*! \brief shifts up all pixels of the screen buffer by param amount
 *	
 *	Shifts up the pixels in the Y direction overwriting the topmost pixels and filling the bottommost pixels with the default background colour
 *  
 *	\param pixels The amount of pixels the screen should be shifted up by.
 *			       
 */
void terminal_shiftUpDisplay(uint8_t pixels){	
	for(uint8_t x = 0; x < WIDTH; x++){	//shifts all the pixels from top to bottom-pixels
		for (uint8_t y = 0; y < HEIGHT-pixels; y++)
		{
			display_copyPixel(x, y, x, y+pixels);
		}
	}
	for(uint8_t x = 0; x < WIDTH; x++){ //sets the remaining unwritten pixels to the background colour
		for (uint8_t y = HEIGHT-pixels; y < HEIGHT; y++)
		{
			display_writePixel(x,y,BACKGROUNDCOLOR);
		}
	}	
}

 /*! \brief Places a letter that format's itself on the screen
 *	
 *	letters placed by this function will word wrap and scroll the screen automatically moving the oldest printed characters off-screen
 *  
 *	\param 	letter The letter that needs to be printed in ASCII
 *	\param	red,green,blue The RGB colour that the character will be printed in.
 *		       
 */
void terminal_placeFormatedLetter(char letter, uint8_t red, uint8_t green, uint8_t blue){		
		
	static uint8_t pixelCursorXPos = EDGEDISTANCE; //position for new characters in pixels
	static uint8_t pixelCursorYPos = EDGEDISTANCE+5; //position for new characters in pixels
	
	if(!(letter > LASTNONPRINTCHAR && letter <= LASTPRINTCHAR-1) && letter != '\n'){//checks if the input character is a known character
		letter = UNKNOWCHAR; //otherwise default to the unknown character
	}
	
	if(letter != '\n'){ //checks if the character is printable 
		pixelCursorXPos += systemFont[letter-ASCIIFONTSTART][SPACINGINDEX]; //if it is move the cursor over by its width
	}
	
	if(pixelCursorXPos+systemFont[letter-ASCIIFONTSTART][SPACINGINDEX] >= WIDTH || letter == '\n'){ //checks if the next character crosses the screen border
		if( letter == '\n'){
			pixelCursorXPos = EDGEDISTANCE;	//puts the x cursor back to the start of the line.
		}else{
			pixelCursorXPos = EDGEDISTANCE + systemFont[letter-ASCIIFONTSTART][SPACINGINDEX]; //puts the x cursor back to the start of the line.
		}						
		pixelCursorYPos += LINESIZE; //moves the y cursor one line down			
		if(pixelCursorYPos > HEIGHT-EDGEDISTANCE-LINESIZE){ // checks if the Y cursor crosses the screen border
			pixelCursorYPos = HEIGHT-EDGEDISTANCE-LINESIZE; //if it does clip the cursor to the last line
			terminal_shiftUpDisplay(LINESIZE); //and scroll the rest of the text one line up.
		}
	}	
	
	if(letter != '\n'){ //checks if the input character is a printable character
		for(uint8_t row = 0; row < SPACINGINDEX; row++){ //for the height of the character			
			for(uint8_t colum = 0; colum < systemFont[letter-ASCIIFONTSTART][SPACINGINDEX]; colum++){ // and the width of the character
				if(systemFont[letter-ASCIIFONTSTART][row] & (1<<colum)){ //if the bit on the row-colum place is high
					display_writePixel(pixelCursorXPos-colum, pixelCursorYPos+row, red, green, blue); //draw a pixel on that row-colum in the specified colour
				}		
			}
		}
	}
}





