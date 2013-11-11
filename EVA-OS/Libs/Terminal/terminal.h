/*
 * terminal.h
 *
 * Created: 25-10-2013 21:05:50
 *  Author: Aran Dokoupil
 */ 


#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <stdio.h>
#include <Graphical/graphical.h>

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
void terminal_putc(struct RGBcolour *p, char letter);
void terminal_shiftUpDisplay(uint8_t pixels);
int terminal_placeFormatedLetter_printf(char letter);
void terminal_placeFormatedLetter(char letter, struct RGBcolour *colour);

#endif /* TERMINAL_H_ */