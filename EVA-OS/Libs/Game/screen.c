/*
 * screen.c
 *
 * Created: 12/14/2013 1:51:45 AM
 *  Author: Elmar
 */ 


#include <libs/Game/screen.h>

static void create(Screen * screen);
static void update(Screen * screen, GameDetails * gameDetails);
static void draw(Screen * screen, GameDetails * gameDetails);
static void dispose(Screen * screen);

Screen * newScreen()
{
	Screen * screen = malloc(sizeof(Screen));
	screen->create = create;
	screen->dispose = dispose;
	screen->draw = draw;
	screen->update = update;
	return screen;
}

static void create(Screen * screen)
{
	
}

static void update(Screen * screen, GameDetails * gameDetails)
{

}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	
}

static void dispose(Screen * screen)
{
	
}