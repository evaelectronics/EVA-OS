/*
 * display_registers.h
 *
 * Created: 20-9-2013 0:30:30
 *  Author: Aran Dokoupil
 */ 


#ifndef DISPLAY_REGISTERS_H_
#define DISPLAY_REGISTERS_H_k


/*COMMANDS*/

#define NOP 		0x00	/**< \brief No Operation*/
#define SWRESET 	0x01	/**< \brief Software Reset*/
#define RDDIDIF 	0x04	/**< \brief Read Display Identification Information*/
#define RDDST 		0x09	/**< \brief Read Display Status*/
#define RDDPM 		0x0A	/**< \brief Read Display Power Mode*/
#define RDDMADCTL	0x0B	/**< \brief Read Display MADCTL*/
#define RDDCOLMOD  	0x0C	/**< \brief Read Display COLMOD*/
#define RDDIM 		0x0D	/**< \brief Read Display Image Mode*/
#define RDDSM 		0x0E	/**< \brief Read Display Signal Mode*/
#define SLPIN 		0x10	/**< \brief Sleep In*/
#define SLPOUT 		0x11	/**< \brief Sleep Out*/
#define PTLON 		0x12	/**< \brief Partial Mode On*/
#define NORON 		0x13	/**< \brief Normal Display Mode On*/
#define INVOFF 		0x20	/**< \brief Display Inversion Off*/
#define INVON 		0x21	/**< \brief Display Inversion On*/
#define GAMSET 		0x26	/**< \brief Gamma Set*/
#define DISPOFF 	0x28	/**< \brief Display Off*/
#define DISPON 		0x29	/**< \brief Display On*/
#define CASET 		0x2A	/**< \brief Column Address Set*/
#define PASET 		0x2B	/**< \brief Page Address Set*/
#define RAMWR 		0x2C	/**< \brief Memory Write*/
#define RGBSET 		0x2D	/**< \brief Color Set*/
#define RAMRD 		0x2E	/**< \brief Memory Read*/
#define PLTAR 		0x30	/**< \brief Partial Area*/
#define VSCRDEF 	0x33	/**< \brief Vertical Scrolling Definition*/
#define TEOFF 		0x34	/**< \brief Tearing Effect Line OFF*/
#define TEON 		0x35	/**< \brief Tearing Effect Line ON*/
#define MADCTL 		0x36	/**< \brief Memory Access Control*/
#define VSCRSADD 	0x37	/**< \brief Vertical Scrolling Start Address*/
#define IDMOFF 		0x38	/**< \brief Idle Mode Off*/
#define IDMON 		0x39	/**< \brief Idle Mode On*/
#define COLMOD 		0x3A	/**< \brief Interface Pixel Format*/
#define SETOSC		0xB0	/**< \brief  Set Internal Oscillator*/
#define SETPOWER 	0xB1	/**< \brief Set Power */
#define SETDISPLAY 	0xB2	/**< \brief  Set Display Control */
#define SETCYC 		0xB4	/**< \brief  Set display cycle */
#define SETBGP		0xB5	/**< \brief  Set VBGP Voltage*/
#define SETCOM 		0xB6	/**< \brief  Set VCOM Voltage*/
#define SETEXTC 	0xB9	/**< \brief  Set Extended Command Set*/
#define SETOTP 		0xBB	/**< \brief  Set OTP related setting*/
#define SETVDC 		0xBC	/**< \brief set internal digital and GRAM voltage*/
#define SETSTBA 	0xC0	/**< \brief  Set Source Option*/
#define SETID 		0xC3	/**< \brief  Set ID*/
#define SETUADJ	 	0xC6	 
#define SETECO	 	0xCB	 
#define SETPANEL	0xCC	/**< \brief  Set Panel Characteristic Register*/
#define GETHID 		0xD0	/**< \brief Read Product ID*/
#define RDID1 		0xDA	/**< \brief Read ID1*/
#define RDID2 		0xDB	/**< \brief Read ID2*/
#define RDID3 		0xDC	/**< \brief Read ID3*/
#define SETGAMMA 	0xE0	/**< \brief  Set Gamma Curve Related Setting*/
#define SETEQ		0xE3	/**< \brief  Set EQ*/





































#endif /* DISPLAY_REGISTERS_H_ */