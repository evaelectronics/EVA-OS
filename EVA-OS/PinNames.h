/*
 * PinNames.h
 *
 * Created: 9/14/2013 9:46:30 AM
 *  Author: Elmar & P
 */ 


#ifndef PINNAMES_H_
#define PINNAMES_H_

#include <sam4s.h>

#define F_CPU 120000000UL

#define CHARGE_ENABLE_PIN	(1<<0) 		/**< \brief  Pin that Enables Li-Po charging	OUTPUT	ACTIVE HIGH*/
#define CHARGE_ENABLE_PORT	PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define USB_CONNECTED_PIN	(1<<1)		/**< \brief  Pin that indicates a connected USB cable	INPUT	ACTIVE HIGH*/
#define USB_CONNECTED_PORT	PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define NOTIFICAT_LED_PIN	(1<<2)		/**< \brief  Pin that controls the notification led	OUTPUT	ACTIVE LOW*/
#define NOTIFICAT_LED_PORT	PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define I2C_SDA_PIN			(1<<3)		/**< \brief  Pin that provides data to the I2C bus	BIDIRECTIONAL*/
#define I2C_SCL_PIN			(1<<4)		/**< \brief  Pin that provides clock to the I2C bus OUTPUT*/
#define I2C_PORT			PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define BT_RX_PIN			(1<<5)		/**< \brief  Pin that receives data from the BT controller	INPUT*/
#define BT_TX_PIN			(1<<6)		/**< \brief  Pin that provides data to the BT controller	OUTPUT*/
#define BT_RTS_PIN			(1<<7)		/**< \brief  Pin that proved a ready-to-send signal to the BT controller	OUTPUT*/
#define BT_CTS_PIN			(1<<8)		/**< \brief  Pin that receives a clear-to-send signal from the BT controller	INPUT*/
#define BT_SHUTDOWN_PIN		(1<<9)		/**< \brief  Pin that puts the BT controller in shutdown mode	OUTPUT	ACTIVE LOW*/
#define BT_PORT				PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define FLASH_CS			(1<<11)		/**< \brief  Pin that provides chip select to the flash memory	OUTPUT	ACTIVE LOW*/
#define FLASH_MISO			(1<<12)		/**< \brief  Pin that receives data from the flash memory	INPUT*/
#define FLASH_MOSI			(1<<13)		/**< \brief  Pin that provides data to the flash memory	OUTPUT*/
#define FLASH_CLK			(1<<14)		/**< \brief  Pin that provides clock to the flash memory	OUTPUT*/
#define FLASH_PORT			PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define BATT_SHUTDOWN_PIN	(1<<15)		/**< \brief  Pin that shuts down the battery supply	OUTPUT	ACTIVE LOW*/
#define BATT_SHUTDOWN_PORT	PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define MIC_CLK_PIN			(1<<16)		/**< \brief  Pin that provides clock to the microphone OUTPUT*/
#define MIC_CLK_PORT		PIOA 		/**< \brief  Port used by Corresponding Pin('s)*/
#define MMA_INT2_PIN		(1<<17)		/**< \brief  Pin that receives interrupt request 2 from the accelerometer	INPUT	ACTIVE LOW*/
#define MMA_INT2_PORT		PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define MIC_DATA_PIN		(1<<18)		/**< \brief  Pin that receives data from the microphone INPUT*/
#define MIC_DATA_PORT		PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define BARO_INT2_PIN		(1<<20)		/**< \brief  Pin that receives interrupt request 2 from the barometer	INPUT	ACTIVE LOW*/
#define BARO_INT2_PORT		PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define IRDA_RXD_PIN		(1<<21)		/**< \brief  Pin that receives modulated data from the infrared module	INPUT*/
#define IRDA_TXD_PIN		(1<<22)		/**< \brief  Pin that provides modulated data to the infrared module	OUTPUT*/
#define IRDA_PORT			PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define BARO_INT1_PIN		(1<<23)		/**< \brief  Pin that receives interrupt request 1 from the barometer	INPUT	ACTIVE LOW*/
#define BARO_INT1_PORT		PIOA		/**< \brief  Port used by Corresponding Pin('s)*/
#define SD_DETECT_PIN		(1<<26)		/**< \brief  Pin that indicates a micro SD card is present	INPUT	ACTIVE LOW*/
#define SD_DATA2_PIN		(1<<27)		/**< \brief  Pin that receives the third bit of data from the micro SD card	INPUT*/
#define SD_DATA3_PIN		(1<<28)		/**< \brief  Pin that receives the fourth bit of data from the micro SD card	INPUT*/
#define SD_CMD_PIN			(1<<29)		/**< \brief  Pin that provides the instructions to the micro SD card	OUTPUT*/
#define SD_CLK_PIN			(1<<30)		/**< \brief  Pin that provides the clock to the micro SD card	OUTPUT*/
#define SD_DATA0_PIN		(1<<31)		/**< \brief  Pin that receives the first bit of data from the micro SD card	INPUT*/
#define SD_DATA1_PIN		(1<<32)		/**< \brief  Pin that receives the second bit of data from the micro SD card	INPUT*/
#define SD_PORT				PIOA		/**< \brief  Port used by Corresponding Pin('s)*/

#define ALS_PIN				(1<<0)		/**< \brief  Pin that receives analog data from the ambient light sensor	INPUT	ANALOG*/
#define ALS_PORT			PIOB		/**< \brief  Port used by Corresponding Pin('s)*/
#define RTC_PIN				(1<<1)		/**< \brief  Pin that receives accurate 32.768hz time reference form the RTC module	INPUT */
#define RTC_PORT			PIOB		/**< \brief  Port used by Corresponding Pin('s)*/
#define BACKLGHT_CNTRL_PIN	(1<<2)		/**< \brief  Pin that provides a control interface for the backlight driver	OUTPUT*/
#define BACKLGHT_CNTRL_PORT	PIOB		/**< \brief  Port used by Corresponding Pin('s)*/
#define MMA_INT1_PIN		(1<<3)		/**< \brief  Pin that  receives interrupt request 1 from the accelerometer	INPUT	ACTIVE LOW*/
#define MMA_INT1_PORT		PIOB		/**< \brief  Port used by Corresponding Pin('s)*/
#define SPKR_SHUTDN_PIN		(1<<12)		/**< \brief  Pin that shuts down the speaker amplifier	OUTPUT ACTIVE LOW*/
#define SPKR_SHUTDN_PORT	PIOB		/**< \brief  Port used by Corresponding Pin('s)*/
#define DAC1_PIN			(1<<13)		/**< \brief  Pin that provides the first channel of analog signal to the speaker amplifier	OUTPUT	ANALOG*/
#define	DAC1_PORT			PIOB		/**< \brief  Port used by Corresponding Pin('s)*/
#define DAC2_PIN			(1<<14)		/**< \brief  Pin that provides the second channel of analog signal to the speaker amplifier	OUTPUT	ANALOG*/
#define DAC2_PORT			PIOB		/**< \brief  Port used by Corresponding Pin('s)*/

#define LCD_DATA0_PIN		(1<<0)		/**< \brief  Pin that provides the first bit of data for the LCD module	BIDIRECTIONAL*/
#define LCD_DATA1_PIN		(1<<1)		/**< \brief  Pin that provides the second bit of data for the LCD module	BIDIRECTIONAL*/
#define LCD_DATA2_PIN		(1<<2)		/**< \brief  Pin that provides the third bit of data for the LCD module	BIDIRECTIONAL*/
#define LCD_DATA3_PIN		(1<<3)		/**< \brief  Pin that provides the fourth bit of data for the LCD module	BIDIRECTIONAL*/
#define LCD_DATA4_PIN		(1<<4)		/**< \brief  Pin that provides the fifth bit of data for the LCD module	BIDIRECTIONAL*/
#define LCD_DATA5_PIN		(1<<5)		/**< \brief  Pin that provides the sixth bit of data for the LCD module	BIDIRECTIONAL*/
#define LCD_DATA6_PIN		(1<<6)		/**< \brief  Pin that provides the seventh bit of data for the LCD module	BIDIRECTIONAL*/
#define LCD_DATA7_PIN		(1<<7)		/**< \brief  Pin that provides the eighth bit of data for the LCD module	BIDIRECTIONAL*/
#define LCD_RD_PIN			(1<<8)		/**< \brief  Pin that provides the read signal for the LCD module	OUTPUT	ACTIVE LOW*/
#define LCD_WR_PIN			(1<<9)		/**< \brief  Pin that provides the write signal for the LCD module	OUTPUT	ACTIVE LOW*/
#define LCD_RS_PIN			(1<<10)		/**< \brief  Pin that provides the register select signal for the LCD module	OUTPUT	LOW = WRITE COMMAND HIGH = WRITE DATA*/
#define LCD_CS_PIN			(1<<11)		/**< \brief  Pin that provides the chip select signal for the LCD module	OUTPUT	ACTIVE LOW*/
#define LCD_RESET_PIN		(1<<12)		/**< \brief  Pin that provides a reset signal for the LCD module	OUTPUT	ACTIVE LOW*/
#define LCD_DATA_PORT		PIOC		/**< \brief  Port used by Corresponding Pin('s)*/
#define BATT_VOLTAGE_PIN	(1<<13)		/**< \brief  Pin that receives the battery voltage divided by two	INPUT	ANALOG */
#define BATT_VOLTAGE_PORT	PIOC		/**< \brief  Port used by Corresponding Pin('s)*/
#define BUTTON_1_PIN		(1<<16)		/**< \brief  Pin that receives the state of the user button's and toggles the power state of the system	INPUT	ACTIVE HIGH*/
#define BUTTON_2_PIN		(1<<17)		/**< \brief  Pin that receives the state of the user button's	INPUT	ACTIVE HIGH*/
#define BUTTON_3_PIN		(1<<18)		/**< \brief  Pin that receives the state of the user button's	INPUT	ACTIVE HIGH*/
#define BUTTON_4_PIN		(1<<19)		/**< \brief  Pin that receives the state of the user button's	INPUT	ACTIVE HIGH*/
#define BUTTON_5_PIN		(1<<20)		/**< \brief  Pin that receives the state of the user button's	INPUT	ACTIVE HIGH*/
#define BUTTON_PORT			PIOC		/**< \brief  Port used by Corresponding Pin('s)*/
#define DEBUG_LED0_PIN		(1<<24)		/**< \brief  Pin that provides the signal for the first debug LED	OUTPUT	ACTIVE LOW*/
#define DEBUG_LED1_PIN		(1<<25)		/**< \brief  Pin that provides the signal for the second debug LED	OUTPUT	ACTIVE LOW*/
#define DEBUG_LED2_PIN		(1<<26)		/**< \brief  Pin that provides the signal for the third debug LED	OUTPUT	ACTIVE LOW*/
#define DEBUG_LED3_PIN		(1<<27)		/**< \brief  Pin that provides the signal for the fourth debug LED	OUTPUT	ACTIVE LOW*/
#define DEBUG_LED4_PIN		(1<<28)		/**< \brief  Pin that provides the signal for the fifth debug LED	OUTPUT	ACTIVE LOW*/
#define DEBUG_LED5_PIN		(1<<29)		/**< \brief  Pin that provides the signal for the sixth debug LED	OUTPUT	ACTIVE LOW*/
#define DEBUG_LED6_PIN		(1<<30)		/**< \brief  Pin that provides the signal for the seventh debug LED	OUTPUT	ACTIVE LOW*/
#define DEBUG_LED7_PIN		(1<<31)		/**< \brief  Pin that provides the signal for the eighth debug LED	OUTPUT	ACTIVE LOW*/
#define DEBUG_LED_PORT		PIOC		/**< \brief  Port used by Corresponding Pin('s)*/



#endif /* PINNAMES_H_ */