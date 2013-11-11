/*
 * graphical.c
 *
 * Created: 8-11-2013 17:33:39
 *  Author: P
 */ 

#include <Display/display.h>
#include <Graphical/graphical.h>
#include <stdlib.h>



void graphical_drawObject(struct graphical_object *object){
	switch(object->objectType){
		case RECTANGLE:
			graphical_drawRectangle(object->arguments[0],object->arguments[1],object->arguments[2],object->arguments[3],object->arguments[4],object->colour);
		break;
		case CIRCLE:
			graphical_drawCircle(object->arguments[0],object->arguments[1],object->arguments[2],object->arguments[3],object->colour);
		break;
		case LINE:
			graphical_drawLine(object->arguments[0],object->arguments[1],object->arguments[2],object->arguments[3],object->colour);
		break;		
	}
}

struct graphical_object* graphical_createNewObject(enum graphical_objectType newObjectType, uint8_t argument0, uint8_t argument1,uint8_t argument2, uint8_t argument3, uint8_t argument4, struct RGBAcolour *newColour){
	struct graphical_object *ptr = malloc(sizeof(struct graphical_object));
	ptr->objectType = newObjectType;
	ptr->arguments[0] = argument0;	
	ptr->arguments[1] = argument1;	
	ptr->arguments[2] = argument2;	
	ptr->arguments[3] = argument3;	
	ptr->arguments[4] = argument4;
	ptr->colour = newColour;	
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
	for(uint8_t x = 0; x < WIDTH; x++){ //for the height
		for(uint8_t y = 0; y < HEIGHT; y++){ //and width of the screen
			graphical_writePixel(x,y,colour); //write the background colour
		}
	}
}

void graphical_drawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t filled, struct RGBcolour *colour){
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

void graphical_drawAlphaCircle(uint8_t centerX, uint8_t centerY, uint8_t radius, uint8_t filled, struct RGBAcolour *colour){
	int16_t decision = 3 - (radius<<1);
	uint8_t pixelX = 0;
	uint8_t pixelY = radius;
	
	while(pixelX<=pixelY){
		graphical_writeAlphaPixel(centerX + pixelX, centerY + pixelY, colour);
		graphical_writeAlphaPixel(centerX + pixelX, centerY - pixelY, colour);
		graphical_writeAlphaPixel(centerX - pixelX, centerY + pixelY, colour);
		graphical_writeAlphaPixel(centerX - pixelX, centerY - pixelY, colour);
		graphical_writeAlphaPixel(centerX + pixelY, centerY + pixelX, colour);
		graphical_writeAlphaPixel(centerX + pixelY, centerY - pixelX, colour);
		graphical_writeAlphaPixel(centerX - pixelY, centerY + pixelX, colour);
		graphical_writeAlphaPixel(centerX - pixelY, centerY - pixelX, colour);
		if(decision<0){
			decision += ((pixelX<<2) + 6);
			}else{
			decision += ((pixelX - pixelY)<<2) + 10;
			pixelY--;
			if(filled){
				for(uint8_t i = pixelX; i > 0; i--){
					graphical_writeAlphaPixel(centerX + i, centerY + pixelY, colour);
					graphical_writeAlphaPixel(centerX + i, centerY - pixelY, colour);
					graphical_writeAlphaPixel(centerX - i, centerY + pixelY, colour);
					graphical_writeAlphaPixel(centerX - i, centerY - pixelY, colour);
					graphical_writeAlphaPixel(centerX + pixelY, centerY + i, colour);
					graphical_writeAlphaPixel(centerX + pixelY, centerY - i, colour);
					graphical_writeAlphaPixel(centerX - pixelY, centerY + i, colour);
					graphical_writeAlphaPixel(centerX - pixelY, centerY - i, colour);
				}
				graphical_writeAlphaPixel(centerX, centerY + pixelY, colour);
				graphical_writeAlphaPixel(centerX, centerY - pixelY, colour);
				graphical_writeAlphaPixel(centerX, centerY + pixelY, colour);
				graphical_writeAlphaPixel(centerX, centerY - pixelY, colour);
				graphical_writeAlphaPixel(centerX + pixelY, centerY, colour);
				graphical_writeAlphaPixel(centerX + pixelY, centerY, colour);
				graphical_writeAlphaPixel(centerX - pixelY, centerY, colour);
				graphical_writeAlphaPixel(centerX - pixelY, centerY, colour);
			}
		}
		pixelX++;
	}
	graphical_writeAlphaPixel(centerX + pixelX, centerY + pixelY, colour);
	graphical_writeAlphaPixel(centerX + pixelX, centerY - pixelY, colour);
	graphical_writeAlphaPixel(centerX - pixelX, centerY + pixelY, colour);
	graphical_writeAlphaPixel(centerX - pixelX, centerY - pixelY, colour);
	if(filled){
		for(int8_t x = -(pixelX-2); x < pixelX-1; x++){
			for(int8_t	y = -(pixelX-2); y < pixelX-1; y++){
				graphical_writeAlphaPixel(centerX + x, centerY + y, colour);
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

