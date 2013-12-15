/*
 * guiButton.c
 *
 * Created: 12/14/2013 2:54:33 AM
 *  Author: Elmar
 */ 

#include <Libs/Game/guiButton.h>

static void draw(GuiButton * guiButton);
static void action(GuiButton * guiButton);


GuiButton * newGuiButton(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
	GuiButton * guiButton = malloc(sizeof(GuiButton));
	guiButton->x = x;
	guiButton->y = y;
	guiButton->width = width;
	guiButton->height = height;
	guiButton->draw = draw;
	guiButton->action = action;
	guiButton->selected = 0;
	return guiButton;
}

static void draw(GuiButton * guiButton)
{
	graphical_drawRectangle(guiButton->x,guiButton->y,guiButton->x+guiButton->width-3,guiButton->y+guiButton->height-3,1,RED);
	if(guiButton->selected){
		graphical_drawRectangle(guiButton->x,guiButton->y,guiButton->x+guiButton->width,guiButton->y+guiButton->height,0,GREEN);
	} else {
		graphical_drawRectangle(guiButton->x,guiButton->y,guiButton->x+guiButton->width,guiButton->y+guiButton->height,0,BLACK);
	}
}

static void action(GuiButton * guiButton)
{
	//Intentionally left empty
}