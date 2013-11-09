/*
 * terminal.h
 *
 * Created: 25-10-2013 21:05:50
 *  Author: Aran Dokoupil
 */ 


#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <stdio.h>

#define LINESIZE 11	/**< \brief height of a letter + one pixel clearance*/
#define EDGEDISTANCE 1	/**< \brief distance from the edge to the screen to the first pixel of a letter*/
#define MAXCHARACTERSX 78 /**< \brief maximum amount of characters possibly present on a single line.*/
#define MAXCHARACTERSY 11 /**< \brief maximum lines possibly present on the screen*/
#define LASTNONPRINTCHAR 31 /**< \brief last ASCII character that doesn't print*/
#define LASTPRINTCHAR 127 /**< \brief last ASCII character that does print*/

#define BACKGROUNDCOLOR 0,0,0 /**< \brief the default colour of the background */
#define TEXTCOLOR 192,192,192 /**< \brief the default colour of text */


/*Prototypes*/
void terminal_init();
void terminal_addString(char *text, uint8_t textLength, uint8_t line, uint8_t red, uint8_t green, uint8_t blue);
void terminal_addLetterPos(char letter, uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue);
void terminal_shiftUpDisplay(uint8_t pixels);
void terminal_clearLine(uint8_t line, uint8_t red, uint8_t green, uint8_t blue);
void terminal_redrawAllText();
int terminal_placeFormatedLetter_printf(char letter);
void terminal_placeFormatedLetter(char letter, uint8_t red, uint8_t green, uint8_t blue);

#endif /* TERMINAL_H_ */