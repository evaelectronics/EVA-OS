/*
 * guiButton.h
 *
 * Created: 12/14/2013 2:54:24 AM
 *  Author: Elmar
 */ 


#ifndef GUIBUTTON_H_
#define GUIBUTTON_H_

#include <Libs/Game/game.h>

typedef struct GuiButton GuiButton;

struct GuiButton{
	uint8_t width;
	uint8_t height;
	uint8_t x;
	uint8_t y;
	uint8_t selected;
	void (*action)(struct GuiButton *);
	void (*draw)(struct GuiButton *);
};

GuiButton * newGuiButton(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void guiButton_setAction(GuiButton * guiButton, void (* action)(GuiButton *));


#endif /* GUIBUTTON_H_ */