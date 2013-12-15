/*
 * screen.c
 *
 * Created: 12/14/2013 1:51:45 AM
 *  Author: Elmar
 */ 


#include <libs/Game/screen.h>

Screen * newScreen()
{
	Screen * screen = malloc(sizeof(Screen));
	screen->create = NULL;
	screen->dispose = NULL;
	screen->draw = NULL;
	screen->update = NULL;
	return screen;
}