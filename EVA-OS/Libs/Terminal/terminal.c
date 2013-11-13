/*
 * Terminal.c
 *
 * Created: 25-10-2013 21:05:37
 *  Author: Aran Dokoupil
 */ 


#include <Display/display.h>
#include <Graphical/graphical.h>
#include <Terminal/terminal.h>
#include <Terminal/system_font.h>
#include <stdio.h>
#include <sys/stat.h>

struct RGBcolour *terminal_backgroundColour; //default background colour, gets defined when initialized 
 
 /*! \brief Initializes the terminal for use.
 *	
 *	rewrites the screen buffer with the background colour and refreshes the screen
 *  			       
 */
void terminal_init(struct RGBcolour *colour){
	terminal_backgroundColour = colour;	
	for(uint8_t x = 0; x < WIDTH; x++){ //for the height
		for(uint8_t y = 0; y < HEIGHT; y++){ //and width of the screen
			graphical_writePixel(x,y,terminal_backgroundColour); //write the background colour
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
			graphical_copyPixel(x, y, x, y+pixels);
		}
	}
	for(uint8_t x = 0; x < WIDTH; x++){ //sets the remaining unwritten pixels to the background colour
		for (uint8_t y = HEIGHT-pixels; y < HEIGHT; y++)
		{
			graphical_writePixel(x,y,terminal_backgroundColour);
		}
	}	
}


 /*! \brief Function used to call placeFormatedLetter so that it can be used by printf
 *	
 *	This function also casts the void pointer to the RGBcolour pointer since that is what placeformatedletter expects.
 *
 *	\param 	p Void pointer that contains the RGBcolour of the char that has to be printed
 *	\param	letter The character that appears on the screen
 *		       
 */
void terminal_putc(void *p, char letter){		
	terminal_placeFormatedLetter(letter, (struct RGBcolour*) p);	
}

 /*! \brief Places a letter that format's itself on the screen
 *	
 *	letters placed by this function will word wrap and scroll the screen automatically moving the oldest printed characters off-screen
 *  
 *	\param 	letter The letter that needs to be printed in ASCII
 *	\param	red,green,blue The RGB colour that the character will be printed in.
 *		       
 */
void terminal_placeFormatedLetter(char letter, struct RGBcolour *colour){		
		
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
					graphical_writePixel(pixelCursorXPos-colum, pixelCursorYPos+row, colour); //draw a pixel on that row-colum in the specified colour
				}		
			}
		}
	}
}

int _write(void *reent, int fd, char *prt, size_t len)
{
	size_t i;
	for(i=0; i<len; i++){
		terminal_placeFormatedLetter((*prt),WHITE);
	}
	return len;
}

int _close(int file) {
	return 0;
}

int _isatty(int file) {
	return 1;
}

int _lseek(int file, int ptr, int dir) {
	return 0;
}

int _open(const char *name, int flags, int mode) {
	return -1;
}

int _read(int file, char *ptr, int len) {
	return 0;
}

int _fstat(int file, struct stat *st) {
	st->st_mode = S_IFCHR;
	return 0;
}





