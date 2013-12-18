/*
 * screen.h
 *
 * Created: 12/14/2013 1:51:35 AM
 *  Author: Elmar
 */ 


#ifndef SCREEN_H_
#define SCREEN_H_

#include <Libs/Game/game.h>
/************************************************************************/
/*				    	  Intentionally Left Empty                      */
/************************************************************************/
typedef struct Screen Screen;

/*! 
 * The screen struct. All the different screen states are a struct. Example, a menu is a screen. In the update
 * method the menu will check all the gui buttons and for actions on the mechanical buttons. Wheras the draw function
 * will be used to draw text and the gui buttons.
 */
struct Screen{
	/* @{ */
	void (* update)(struct Screen * , GameDetails *);	/*!< update method, this will be called every update loop */
	void (* draw)(struct Screen * , GameDetails *);		/*!< draw method, this too will be called every update loop */
	void (* dispose)(struct Screen * );					/*!< dispose function, this will be called upon switching screen */
	void (* create)(struct Screen *);					/*!< this function will be called as soon as the screen gets active */
};

/*! \brief this Function is used to obtain a new screen struct pointer and initialize the functions   
 *  \retval a pointer to the new screen location	
 */
Screen * newScreen();

#endif /* SCREEN_H_ */