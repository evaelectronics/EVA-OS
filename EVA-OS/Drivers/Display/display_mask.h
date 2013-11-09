/*
 * display_mask.h
 *
 * Created: 25-10-2013 0:56:21
 *  Author: Aran Dokoupil
 */ 


#ifndef DISPLAY_MASK_H_
#define DISPLAY_MASK_H_

#define MADCTL_DISPLAY_LATCH_ORDER (1<<2)		/**< \brief LCD Refresh Right to Left*/
#define MADCTL_RGB_BGR_ORDER	(1<<3)			/**< \brief Color selector switch control (0=RGB, 1=BGR)*/
#define MADCTL_VERTICAL_ORDER	(1<<4)			/**< \brief LCD vertical refresh direction control*/
#define MADCTL_PAGE_COLUMN_SELECTION (1<<5)		/**< \brief Physical display pointer control, See datasheet*/
#define MADCTL_COLUMN_ADDRESS_ORDER	(1<<6)		/**< \brief Physical display pointer control, See datasheet*/
#define MADCTL_PAGE_ADDRESS_ORDER (1<<7)		/**< \brief Physical display pointer control, See datasheet*/

		
#define SETEXTC_PARAM1 0xFF		/**< \brief first byte that NEEDS to be written for command extension after SETEXTC is written*/
#define SETEXTC_PARAM2 0x83		/**< \brief second byte that NEEDS to be written for command extension after SETEXTC is written*/
#define SETEXTC_PARAM3 0x53		/**< \brief third byte that NEEDS to be written for command extension after SETEXTC is written*/

#endif /* DISPLAY_MASK_H_ */