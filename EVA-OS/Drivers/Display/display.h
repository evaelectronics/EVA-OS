/*
 * display.h
 *
 * Created: 20-9-2013 0:29:34
 *  Author: Aran Dokoupil
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <sam4s.h>

//the bits that make up the LCD 8-bit data bus
#define LCD_BUS LCD_DATA0_PIN | LCD_DATA1_PIN | LCD_DATA2_PIN | LCD_DATA3_PIN | LCD_DATA4_PIN | LCD_DATA5_PIN | LCD_DATA6_PIN | LCD_DATA7_PIN 


/*macro's used for readable and easy toggling of the control signals*/
#define CS_LO() LCD_DATA_PORT->PIO_CODR = LCD_CS_PIN /**< \brief Set chip select low*/
#define CS_HI() LCD_DATA_PORT->PIO_SODR = LCD_CS_PIN /**< \brief Set chip select high*/

#define RS_LO() LCD_DATA_PORT->PIO_CODR = LCD_RS_PIN /**< \brief Set the bus in command mode*/
#define RS_HI() LCD_DATA_PORT->PIO_SODR = LCD_RS_PIN /**< \brief Set the bus in data mode*/

#define WR_LO() LCD_DATA_PORT->PIO_CODR = LCD_WR_PIN /**< \brief Set the write signal low*/
#define WR_HI() LCD_DATA_PORT->PIO_SODR = LCD_WR_PIN /**< \brief Set the write signal high*/

#define RD_LO() LCD_DATA_PORT->PIO_CODR = LCD_RD_PIN /**< \brief Set the read signal low*/
#define RD_HI() LCD_DATA_PORT->PIO_SODR = LCD_RD_PIN /**< \brief Set the read signal high*/

#define RESET_LO() LCD_DATA_PORT->PIO_CODR = LCD_RESET_PIN /**< \brief Set the reset signal low*/
#define RESET_HI() LCD_DATA_PORT->PIO_SODR = LCD_RESET_PIN /**< \brief Set the reset signal high*/



#define HEIGHT 128 /**< \brief Specifies the height of the display */
#define WIDTH 160 /**< \brief  Specifies the width of the display*/
#define COLOUR 3 /**< \brief Specifies the amount of coloured sub pixels the display has */

#define RED 0 /**< \brief Specifies the index of the screen buffer where <b>red</b> is stored */
#define GREEN 1 /**< \brief Specifies the index of the screen buffer where <b>green</b> is stored */
#define BLUE 2 /**< \brief Specifies the index of the screen buffer where <b>blue</b> is stored */


/*prototypes*/
void display_writePixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue);
void display_init();
void display_screenRefresh();
void display_copyPixel(uint8_t firstX, uint8_t firstY, uint8_t secondX, uint8_t secondY);

#endif /* DISPLAY_H_ */