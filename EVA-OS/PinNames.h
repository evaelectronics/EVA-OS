/*
 * PinNames.h
 *
 * Created: 9/14/2013 9:46:30 AM
 *  Author: Elmar
 */ 


#ifndef PINNAMES_H_
#define PINNAMES_H_

#include "sam.h"

#define CHARGE_ENABLE_PIN	0
#define CHARGE_ENABLE_PORT	PIOA
#define USB_CONNECTED_PIN	1
#define USB_CONNECTED_PORT	PIOA
#define NOTIFICAT_LED_PIN	2
#define NOTIFICAT_LED_PORT	PIOA
#define I2C_SDA_PIN			3
#define I2C_SCL_PIN			4
#define I2C_PORT			PIOA
#define BT_RX_PIN			5
#define BT_TX_PIN			6
#define BT_RTS_PIN			7
#define BT_CTS_PIN			8
#define BT_SHUTDOWN_PIN		9
#define BT_PORT				PIOA
#define FLASH_CS			11
#define FLASH_MISO			12
#define FLASH_MOSI			13
#define FLASH_CLK			14
#define FLASH_PORT			PIOA
#define BATT_SHUTDOWN_PIN	15
#define BATT_SHUTDOWN_PORT	PIOA
#define MIC_CLK_PIN			16
#define MIC_CLK_PORT		PIOA 
#define MMA_INT2_PIN		17
#define MMA_INT2_PORT		PIOA
#define MIC_DATA_PIN		18
#define MIC_DATA_PORT		PIOA
#define BARO_INT2_PIN		20
#define BARO_INT2_PORT		PIOA
#define IRDA_RXD_PIN		21
#define IRDA_TXD_PIN		22
#define IRDA_PORT			PIOA
#define BARO_INT1_PIN		23
#define BARO_INT1_PORT		PIOA
#define SD_DETECT_PIN		26
#define SD_DATA2_PIN		27
#define SD_DATA3_PIN		28
#define SD_CMD_PIN			29
#define SD_CLK_PIN			30
#define SD_DATA0_PIN		31
#define SD_DATA1_PIN		32
#define SD_PORT				PIOA

#define ALS_PIN				0
#define ALS_PORT			PIOB
#define RTC_PIN				1
#define RTS_PORT			PIOB
#define BACKLGHT_CNTRL_PIN	2
#define BACKLGHT_CNTRL_PORT	PIOB
#define MMA_INT1_PIN		3		
#define MMA_INT1_PORT		PIOB
#define SPKER_SHUTDNW_PIN	12
#define SPKER_SHUTDNW_PORT	PIOB
#define DAC1_PIN			13
#define	DAC1_PORT			PIOB
#define DAC2_PIN			14
#define DAC2_PORT			PIOB

#define LCD_DATA0_PIN		0
#define LCD_DATA1_PIN		1
#define LCD_DATA2_PIN		2
#define LCD_DATA3_PIN		3
#define LCD_DATA4_PIN		4
#define LCD_DATA5_PIN		5
#define LCD_DATA6_PIN		6
#define LCD_DATA7_PIN		7
#define LCD_RD_PIN			8
#define LCD_WR_PIN			9
#define LCD_RS_PIN			10
#define LCD_CS_PIN			11
#define LCD_RESET_PIN		12
#define LCD_DATA_PORT		PIOC
#define BATT_VOLTAGE_PIN	13			
#define BATT_VOLTAGE_PORT	PIOC
#define BUTTON_1_PIN		16
#define BUTTON_2_PIN		17
#define BUTTON_3_PIN		18
#define BUTTON_4_PIN		19
#define BUTTON_5_PIN		20
#define BUTTON_PORT			PIOC
#define DEBUG_LED0_PIN		24
#define DEBUG_LED1_PIN		25
#define DEBUG_LED2_PIN		26
#define DEBUG_LED3_PIN		27
#define DEBUG_LED4_PIN		28
#define DEBUG_LED5_PIN		29
#define DEBUG_LED6_PIN		30
#define DEBUG_LED7_PIN		31
#define DEBUG_LED_PORT		PIOC



#endif /* PINNAMES_H_ */