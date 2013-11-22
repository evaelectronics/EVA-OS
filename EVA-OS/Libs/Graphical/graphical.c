/*
* graphical.c
*
* Created: 8-11-2013 17:33:39
*  Author: P
*/

#include <Display/display.h>
#include <Graphical/graphical.h>
#include <stdlib.h>
#include <Led/led.h>
#include <PinNames.h>
#include <stdarg.h>

struct graphical_object mainObjList = {.previous = NULL, .first = NULL, .currentID = 0, .last = NULL, .next = NULL};
struct RGBcolour *graphical_backgroundColour; //default background colour, gets defined when initialized


struct graphical_shape* graphical_addNewShape(enum graphical_shapeType newObjectType, struct RGBcolour *newColour, uint8_t z, ...){
	
	struct graphical_shape *ptr = malloc(sizeof(struct graphical_shape));
	if(ptr == NULL){
		//out of memory
	}
	struct graphical_shape *currentListIndex;
	
	va_list arguments;
	ptr->objectType = newObjectType;
	ptr->numberOfArguments = graphical_getNumberOfArguments(newObjectType);
	ptr->colour = newColour;
	ptr->id = mainObjList.currentID;
	mainObjList.currentID++;
	ptr->z = z;
	ptr->arguments = (uint8_t *) malloc(sizeof(uint8_t) * ptr->numberOfArguments);
	if(ptr->arguments == NULL){
		//out of memory
	}
	va_start(arguments, newColour);
	for(uint8_t i = 0; i < ptr->numberOfArguments; i++){
		ptr->arguments[i] = (uint8_t) va_arg(arguments, int);
	}
	
	if(mainObjList.first == NULL){
		mainObjList.first = ptr;
		mainObjList.last = ptr;
		ptr->next = NULL;
		ptr->previous = NULL;
		return ptr;
	}
	
	currentListIndex = mainObjList.first;
	
	if(currentListIndex->z < z){
		ptr->previous = currentListIndex->previous; //place ptr in front of CLI
		ptr->next = currentListIndex;
		currentListIndex->previous = ptr;
		mainObjList.first = ptr;
		return ptr;
	}
	
	while((currentListIndex->next)->z >= z){
		if(currentListIndex->next == NULL){
			break;
			}else{
			currentListIndex = currentListIndex->next;
		}
	}

	if(currentListIndex == mainObjList.last){
		mainObjList.last = ptr;
	}
	(currentListIndex->next)->previous = ptr;//place ptr after of CLI
	ptr->next = currentListIndex->next;
	ptr->previous = currentListIndex;
	currentListIndex->next = ptr;
	
	return ptr;
}

struct graphical_object* graphical_createNewObject(){
	return NULL;
}


void graphical_drawList(/*struct graphical_linkedList *list*/){
	struct graphical_shape* currentListIndex = mainObjList.first;
	
	while(currentListIndex != NULL){
		graphical_drawShape(currentListIndex);
		currentListIndex = currentListIndex->next;
	}
}

void graphical_undrawList(/*struct graphical_linkedList *list*/){
	struct graphical_shape* currentListIndex = mainObjList.first;
	
	while(currentListIndex != NULL){
		graphical_drawShapeColour(currentListIndex,graphical_backgroundColour);
		currentListIndex = currentListIndex->next;
	}
}

/**
* \brief
*
* \param deltaX
* \param deltaY
*
* \return void
*/
void graphical_moveList(int16_t deltaX, int16_t deltaY){
	struct graphical_shape* currentListIndex = mainObjList.first;
	
	while(currentListIndex != NULL){
		graphical_moveShape(currentListIndex, deltaX, deltaY);
		currentListIndex = currentListIndex->next;
	}
}

/**
* \brief
*
* \param listPosition
* \param deltaX
* \param deltaY
*
* \return void
*/
int8_t graphical_moveShapeByListPosition(uint16_t listPosition, int16_t deltaX, int16_t deltaY){
	struct graphical_shape* currentListIndex = mainObjList.first;
	
	for(uint16_t i = 0; i < listPosition; i++){
		if(currentListIndex == NULL){
			//list smaller then listPosition
			return -1;
		}
		currentListIndex = currentListIndex->next;
	}
	graphical_moveShape(currentListIndex, deltaX, deltaY);
	return(0);
}

int8_t graphical_moveShapeByID(uint16_t id, int16_t deltaX, int16_t deltaY){
	struct graphical_shape* currentListIndex = mainObjList.first;
	
	while(currentListIndex->id !=id){
		if(currentListIndex == NULL){
			//id is not present in list
			return -1;
		}
		currentListIndex = currentListIndex->next;
	}
	graphical_moveShape(currentListIndex, deltaX, deltaY);
	return 0;
}

void graphical_moveShape(struct graphical_shape *shape, int16_t deltaX, int16_t deltaY){
	
	switch(shape->objectType){
		case RECTANGLE:
		shape ->arguments[RECTANGLE_X1] += deltaX;
		shape ->arguments[RECTANGLE_Y1] += deltaY;
		shape ->arguments[RECTANGLE_X2] += deltaX;
		shape ->arguments[RECTANGLE_Y2] += deltaY;
		break;
		case CIRCLE:
		shape->arguments[CIRCLE_X] += deltaX;
		shape->arguments[CIRCLE_Y] += deltaY;
		break;
		case LINE:
		shape->arguments[LINE_X1] += deltaX;
		shape->arguments[LINE_Y1] += deltaY;
		shape->arguments[LINE_X2] += deltaX;
		shape->arguments[LINE_Y2] += deltaY;
		break;
		case PIXEL:
		shape->arguments[PIXEL_X] += deltaX;
		shape->arguments[PIXEL_Y] += deltaY;
		break;
		case SPRITE:
		shape->arguments[SPRITE_X] += deltaX;
		shape->arguments[SPRITE_Y] += deltaY;
		break;
		
	}
	
}

void graphical_drawShape(struct graphical_shape *shape){
	switch(shape->objectType){
		case RECTANGLE:
		graphical_drawRectangle(shape->arguments[0],shape->arguments[1],shape->arguments[2],shape->arguments[3],shape->arguments[4],shape->colour);
		break;
		case CIRCLE:
		graphical_drawCircle(shape->arguments[0],shape->arguments[1],shape->arguments[2],shape->arguments[3],shape->colour);
		break;
		case LINE:
		graphical_drawLine(shape->arguments[0],shape->arguments[1],shape->arguments[2],shape->arguments[3],shape->colour);
		break;
		case SPRITE:
		
		break;
		case PIXEL:
		
		break;
	}
}

void graphical_drawShapeColour(struct graphical_shape *shape, struct RGBcolour *newColour){
	switch(shape->objectType){
		case RECTANGLE:
		graphical_drawRectangle(shape->arguments[0],shape->arguments[1],shape->arguments[2],shape->arguments[3],shape->arguments[4],newColour);
		break;
		case CIRCLE:
		graphical_drawCircle(shape->arguments[0],shape->arguments[1],shape->arguments[2],shape->arguments[3],newColour);
		break;
		case LINE:
		graphical_drawLine(shape->arguments[0],shape->arguments[1],shape->arguments[2],shape->arguments[3],newColour);
		break;
		case SPRITE:
		
		break;
		case PIXEL:
		
		break;
	}
}

uint8_t graphical_getNumberOfArguments(enum graphical_shapeType shapeType){
	switch(shapeType){
		case RECTANGLE:
		return RECTANGLE_ARGUMENTS;
		case CIRCLE:
		return CIRCLE_ARGUMENTS;
		case LINE:
		return LINE_ARGUMENTS;
		case SPRITE:
		return SPRITE_ARGUMENTS;
		case PIXEL:
		return PIXEL_ARGUMENTS;
	}
}

/*! \brief Writes a single pixel to the screen buffer
*
*	writes the red green and blue values of a specified pixel in the screen buffer which can then be send to the display
*
*	\param 	x,y The X and Y positions of the pixel to be written
*	\param	red,green,blue The RGB colour that the pixel will appear in
*
*/
void graphical_writePixel(uint8_t x, uint8_t y, struct RGBcolour *newColour){
	screenBuffer[x][y].red = newColour->red; //writes the red value
	screenBuffer[x][y].green = newColour->green; //writes the green value
	screenBuffer[x][y].blue = newColour->blue; //writes the blue value
}

void graphical_writeAlphaPixel(uint8_t x, uint8_t y, struct RGBAcolour *newColour){
	if(newColour->alpha == 0){
		return;
	}
	if(newColour->alpha == 255){
		screenBuffer[x][y].red = newColour->red; //writes the red value
		screenBuffer[x][y].green = newColour->green; //writes the green value
		screenBuffer[x][y].blue = newColour->blue; //writes the blue value
	}
	
}


/*! \brief copies the second pixel and overwrites the first with the seconds data
*
*	\param 	firstX,firstY The coordinates of the pixel to be replaced
*	\param	secondX, secondY The coordinated of the pixel that should be copied
*
*/
void graphical_copyPixel(uint8_t firstX, uint8_t firstY, uint8_t secondX, uint8_t secondY){
	screenBuffer[firstX][firstY].red = screenBuffer[secondX][secondY].red; //copies the red pixel value
	screenBuffer[firstX][firstY].green = screenBuffer[secondX][secondY].green;//copies the green pixel value
	screenBuffer[firstX][firstY].blue = screenBuffer[secondX][secondY].blue;//copies the blue pixel value
}

void graphical_init(struct RGBcolour *colour){
	graphical_backgroundColour = colour;
	for(uint8_t x = 0; x < WIDTH; x++){ //for the height
		for(uint8_t y = 0; y < HEIGHT; y++){ //and width of the screen
			graphical_writePixel(x,y,graphical_backgroundColour); //write the background colour
		}
	}
}

void graphical_drawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t filled, struct RGBcolour *colour){
	uint8_t buffer;
	if(x2 < x1){
		buffer = x2;
		x2 = x1;
		x1 = buffer;
	}
	if(y2 < y1){
		buffer = y2;
		y2 = y1;
		y1 = buffer;
	}
	if(filled){
		for(uint8_t x = x1; x<=x2; x++){
			for(uint8_t i = y1; i <= y2; i++){
				graphical_writePixel(x,i, colour);
			}
		}
		}else{
		for(uint8_t x = x1; x<=x2; x++){
			graphical_writePixel(x,y1, colour);
			graphical_writePixel(x,y2, colour);
		}
		for(uint8_t y = y1; y<=y2; y++){
			graphical_writePixel(x1,y, colour);
			graphical_writePixel(x2,y, colour);
		}
	}
}

void graphical_drawCircle(uint8_t centerX, uint8_t centerY, uint8_t radius, uint8_t filled, struct RGBcolour *colour){
	int16_t decision = 3 - (radius<<1);
	uint8_t pixelX = 0;
	uint8_t pixelY = radius;
	
	while(pixelX<=pixelY){
		graphical_writePixel(centerX + pixelX, centerY + pixelY, colour);
		graphical_writePixel(centerX + pixelX, centerY - pixelY, colour);
		graphical_writePixel(centerX - pixelX, centerY + pixelY, colour);
		graphical_writePixel(centerX - pixelX, centerY - pixelY, colour);
		graphical_writePixel(centerX + pixelY, centerY + pixelX, colour);
		graphical_writePixel(centerX + pixelY, centerY - pixelX, colour);
		graphical_writePixel(centerX - pixelY, centerY + pixelX, colour);
		graphical_writePixel(centerX - pixelY, centerY - pixelX, colour);
		if(decision<0){
			decision += ((pixelX<<2) + 6);
			}else{
			decision += ((pixelX - pixelY)<<2) + 10;
			pixelY--;
			if(filled){
				for(uint8_t i = pixelX; i > 0; i--){
					graphical_writePixel(centerX + i, centerY + pixelY, colour);
					graphical_writePixel(centerX + i, centerY - pixelY, colour);
					graphical_writePixel(centerX - i, centerY + pixelY, colour);
					graphical_writePixel(centerX - i, centerY - pixelY, colour);
					graphical_writePixel(centerX + pixelY, centerY + i, colour);
					graphical_writePixel(centerX + pixelY, centerY - i, colour);
					graphical_writePixel(centerX - pixelY, centerY + i, colour);
					graphical_writePixel(centerX - pixelY, centerY - i, colour);
				}
				graphical_writePixel(centerX, centerY + pixelY, colour);
				graphical_writePixel(centerX, centerY - pixelY, colour);
				graphical_writePixel(centerX, centerY + pixelY, colour);
				graphical_writePixel(centerX, centerY - pixelY, colour);
				graphical_writePixel(centerX + pixelY, centerY, colour);
				graphical_writePixel(centerX + pixelY, centerY, colour);
				graphical_writePixel(centerX - pixelY, centerY, colour);
				graphical_writePixel(centerX - pixelY, centerY, colour);
			}
		}
		pixelX++;
	}
	graphical_writePixel(centerX + pixelX, centerY + pixelY, colour);
	graphical_writePixel(centerX + pixelX, centerY - pixelY, colour);
	graphical_writePixel(centerX - pixelX, centerY + pixelY, colour);
	graphical_writePixel(centerX - pixelX, centerY - pixelY, colour);
	if(filled){
		for(int8_t x = -(pixelX-2); x < pixelX-1; x++){
			for(int8_t	y = -(pixelX-2); y < pixelX-1; y++){
				graphical_writePixel(centerX + x, centerY + y, colour);
			}
		}
	}
}

void graphical_drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, struct RGBcolour *colour){

	if(x2 < x1){
		uint8_t buffer = x1;
		x1 = x2;
		x2 = buffer;
		buffer = y1;
		y1 = y2;
		y2 = buffer;
	}
	
	int16_t deltaX = x2-x1;
	int16_t deltaY = y2-y1;
	int8_t slopeY;
	
	if(deltaY < 0){
		slopeY = -1;
		deltaY = -deltaY;
		}else{
		slopeY = 1;
	}
	
	if(deltaX >= deltaY){
		int16_t decision = ((deltaY)<<1)-deltaX;
		if(x1 <= x2){
			while(x1 <= x2){
				graphical_writePixel(x1,y1, colour);
				graphical_writePixel(x2,y2, colour);
				if(decision < 0){
					decision += (deltaY<<1);
					}else{
					decision += ((deltaY - deltaX)<<1);
					y1 += slopeY;
					y2 -= slopeY;
				}
				x1+= 1;
				x2-= 1;
			}
			}else{
			while(x1 >= x2){
				graphical_writePixel(x1,y1, colour);
				graphical_writePixel(x2,y2, colour);
				if(decision < 0){
					decision += (deltaY<<1);
					}else{
					decision += ((deltaY - deltaX)<<1);
					y1 += slopeY;
					y2 -= slopeY;
				}
				x1+= 1;
				x2-= 1;
			}
		}
		graphical_writePixel(x1,y1, colour);
		}else{
		int16_t decision = ((deltaX)<<1)-deltaY;
		if(y1 <= y2){
			while(y1 <= y2){
				graphical_writePixel(x2,y2, colour);
				graphical_writePixel(x1,y1, colour);
				if(decision < 0){
					decision += (deltaX<<1);
					}else{
					decision += ((deltaX - deltaY)<<1);
					x1 += 1;
					x2 -= 1;
				}
				y1 += slopeY;
				y2 -= slopeY;
			}
			}else{
			while(y1 >= y2){
				graphical_writePixel(x2,y2, colour);
				graphical_writePixel(x1,y1, colour);
				if(decision < 0){
					decision += (deltaX<<1);
					}else{
					decision += ((deltaX - deltaY)<<1);
					x1 += 1;
					x2 -= 1;
				}
				y1 += slopeY;
				y2 -= slopeY;
			}
		}
		graphical_writePixel(x1,y1, colour);
	}
}

struct RGBcolour* graphical_createRGBColour(uint8_t red, uint8_t green, uint8_t blue){
	struct RGBcolour *ptr = malloc(sizeof(struct RGBcolour) );
	ptr->red = red;
	ptr->green = green;
	ptr->blue = blue;
	return ptr;
}

struct RGBAcolour* graphical_createRGBAColour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){
	struct RGBAcolour *ptr = malloc(sizeof(struct RGBAcolour) );
	ptr->red = red;
	ptr->green = green;
	ptr->blue = blue;
	ptr->alpha = alpha;
	return ptr;
}

