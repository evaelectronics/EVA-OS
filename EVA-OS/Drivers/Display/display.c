/*
* display.c
*
* Created: 20-9-2013 0:29:21
*  Author: Aran Dokoupil
*/


#include <sam4s.h>
#include <stdlib.h>
#include <stdio.h>
#include <Display/display.h>
#include <Display/display_registers.h>
#include <Display/display_mask.h>
#include <PinNames.h>
#include <Delay/delay.h>
#include <Graphical/graphical.h>

/*prototypes*/
static inline void display_quickWriteByte(uint8_t data)__attribute__((always_inline));
static inline void display_readMode() __attribute__((always_inline));
static inline void display_writeMode() __attribute__((always_inline));
static inline void display_writeCommand(uint8_t data) __attribute__((always_inline));

static inline void display_writeByte(uint8_t data) __attribute__((always_inline));
static inline void display_enable_extended_command() __attribute__((always_inline));



/*! \brief Sends a byte over the LCD bus and clocks it in.
*
*	A quicker lcd write function since it omits making the bus an output. this is used where speed is more important than safety.
*
*	\param data The byte that should appear on the bus.
*
*/
static inline void display_quickWriteByte(uint8_t data){
	WR_LO(); //set clock low
	LCD_DATA_PORT->PIO_ODSR = data; //put data on the bus
	WR_HI(); //set clock high again
}

/*! \brief Sends a command over the LCD bus and clocks it in.
*
*	Writes a byte to the 8-bit bus and controls the signals to specify this is a command.
*
*	\param data The command that should appear on the bus.
*
*/
static inline void display_writeCommand(uint8_t data){
	display_writeMode();
	RS_LO();
	LCD_DATA_PORT->PIO_ODSR = data;
	WR_HI();
	WR_LO();
	RS_HI();
}


/*! \brief Sends a byte over the LCD bus and clocks it in.
*
*	A slower lcd write function since it makes the bus an output. this is used where safety is more important than speed.
*
*	\param data The byte that should appear on the bus.
*
*/
static inline void display_writeByte(uint8_t data){
	display_writeMode();
	LCD_DATA_PORT->PIO_ODSR = data;
	WR_HI();
	WR_LO();
}


/*! \brief controls the sleep state of the screen
*
*	\param state Turns the display off if zero, turns the display on if not zero
*
*/

void display_set_state(uint8_t state){
	display_writeCommand(DISPOFF|(state && 1));	//write the on/off command
}


/*! \brief controls the sleep state of the screen
*
*	\param sleep Sets the display in sleep mode if zero, wakes up the display if not zero
*
*/
void display_set_sleep(uint8_t sleep){
	display_writeCommand(SLPIN|!(sleep && 1)); //write the sleep command
}

/*! \brief sends a ramWrite command
*
*  ramWrite initializes the display to receive a framebuffer of data.
*
*/
void display_ramWrite(){
	display_writeCommand(RAMWR); //write the ramWrite command;
}


/*! \brief sends the specified macdata to the display
*
*	macdata is used to specifies interface parameters such as the order of red green and blue bytes.
*
*	\param macData the macdata to be send
*
*/
void display_set_MAC(uint8_t macData){
	display_writeCommand(MADCTL); //send the macdata instruction
	display_writeByte(macData);// and sends the mac data
}


/*! \brief enables the use of extended display commands
*
*	by default the display doesn't except extended commands for legacy support
*
*/
static inline void display_enable_extended_command(){
	display_writeCommand(SETEXTC); //send extended command command
	display_writeByte(SETEXTC_PARAM1);	//three protection byte's that NEED to be written for command extension
	display_writeByte(SETEXTC_PARAM2);	//otherwise extended command won't be enabled
	display_writeByte(SETEXTC_PARAM3);
}

/*! \brief Initializes the display for use with the microcontroller
*
*	writes all the needed commands to correctly interface with the display
*
*/
void display_init(){
	CS_LO();
	RESET_HI();
	delay_ms(100);
	RESET_LO();
	delay_ms(100);
	RESET_HI();
	
	display_set_state(1);
	display_set_MAC(MADCTL_RGB_BGR_ORDER);
	display_enable_extended_command();
	display_set_sleep(0);

	display_writeCommand(SETUADJ); //set's LCD timing frequency, is panel specific and shouldn't be adjusted during operation
	display_writeByte(0x31);
	
	display_writeCommand(SETBGP); //set's LCD voltages, is panel specific and shouldn't be adjusted during operation
	display_writeByte(0x0B);
	display_writeByte(0x0B);
	display_writeByte(0x07);
	
	display_writeCommand(SETPOWER);	 //set's LCD voltages, is panel specific and shouldn't be adjusted during operation
	display_writeByte(0x00);
	display_writeByte(0x00);
	
	display_writeCommand(SETDISPLAY);
	display_writeByte(0x00);
	
	display_writeCommand(SETCOM);
	display_writeByte(0x84);
	display_writeByte(0x6C);
	display_writeByte(0x74);


	display_writeCommand(COLMOD);
	display_writeByte(0x06);

	display_set_state(1);		//Display ON
}


/*! \brief sets the LCD bus in read mode
*
*	set's the IO's that interface with the LCD as input's and changes the control signals to specify the bus direction
*
*/
static inline void display_readMode(){
	LCD_DATA_PORT->PIO_ODR = LCD_BUS; //set IO's to input
	WR_HI(); //tell the display the bus is an input
	RD_LO();
}


/*! \brief sets the lcd bus in write mode
*
*	set's the IO's that interface with the LCD as output's and changes the control signals to specify the bus direction
*
*/
static inline void display_writeMode(){
	RD_HI(); //tel the display that the bus is an output
	WR_LO();
	LCD_DATA_PORT->PIO_OER = LCD_BUS; //set IO's to output
}


/*! \brief refreshes the screen buffer to the display
*
*	writes <b>all</b> the data of the screen buffer to the display to make the screen buffer viable to the outside world
*
*/
void display_screenRefresh(){
	display_ramWrite(); //enter ramwrite mode
	for(int x = WIDTH-1; x >= 0; x--){
		for(int y = 0; y < HEIGHT; y++){ //and proceed to write the content of the frame buffer to the display
			display_quickWriteByte(screenBuffer[x][y].red);
			display_quickWriteByte(screenBuffer[x][y].green);
			display_quickWriteByte(screenBuffer[x][y].blue);
		}
	}
}