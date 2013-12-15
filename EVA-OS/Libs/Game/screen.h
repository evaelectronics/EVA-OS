/*
 * screen.h
 *
 * Created: 12/14/2013 1:51:35 AM
 *  Author: Elmar
 */ 


#ifndef SCREEN_H_
#define SCREEN_H_

#include <Libs/Game/game.h>

typedef struct Screen Screen;

struct Screen{
	void (* update)(struct Screen * , GameDetails *);
	void (* draw)(struct Screen * , GameDetails *);
	void (* dispose)(struct Screen * );
	void (* create)(void);	
};

Screen * newScreen();

#endif /* SCREEN_H_ */