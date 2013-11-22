/*
 * graphical.h
 *
 * Created: 8-11-2013 17:33:55
 *  Author: P
 */ 


#ifndef GRAPHICAL_H_
#define GRAPHICAL_H_

#include <Display/display.h>

struct RGBcolour{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct RGBAcolour{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};

struct graphical_object {
	struct graphical_object *previous;
	struct graphical_shape *first;
	uint32_t currentID;
	struct graphical_shape *last;
	struct graphical_object *next;
};

typedef enum graphical_shapeType{ RECTANGLE = 1, CIRCLE, LINE, SPRITE, PIXEL};
	
#define RECTANGLE_ARGUMENTS 5
#define RECTANGLE_X1 0
#define RECTANGLE_Y1 1
#define RECTANGLE_X2 2
#define RECTANGLE_Y2 3
#define RECTANGLE_FILLED 4

#define CIRCLE_ARGUMENTS 4
#define CIRCLE_X 0
#define CIRCLE_Y 1
#define CIRCLE_RADIUS 2
#define CIRCLE_FILLED 3

#define LINE_ARGUMENTS 4
#define LINE_X1 0
#define LINE_Y1 1
#define LINE_X2 2
#define LINE_Y2 3

#define SPRITE_ARGUMENTS 5
#define SPRITE_X 0
#define SPRITE_Y 1
#define SPRITE_WIDTH 2
#define SPRITE_HEIGHT 3
#define SPRITE_DATA 4

#define PIXEL_ARGUMENTS 3
#define PIXEL_X 0
#define PIXEL_Y 1


struct graphical_shape {
	struct graphical_shape *previous;
	enum graphical_shapeType objectType;
	uint32_t id;
	uint8_t z;
	uint8_t *arguments;
	uint8_t numberOfArguments;
	struct RGBcolour *colour;
	struct graphical_shape *next;
};

struct RGBcolour screenBuffer[WIDTH][HEIGHT];//the main on-chip buffer that contains realtime screen data

struct RGBcolour* graphical_createRGBColour(uint8_t red, uint8_t green, uint8_t blue);
struct RGBAcolour* graphical_createRGBAColour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

 static struct RGBcolour *BLACK __attribute__((unused)) = &(struct RGBcolour){.red = 0, .green = 0, .blue = 0};
 static struct RGBcolour *WHITE __attribute__((unused)) = &(struct RGBcolour){.red = 255, .green = 255, .blue = 255};
 static struct RGBcolour *RED __attribute__((unused)) = &(struct RGBcolour){.red = 255, .green = 0, .blue = 0};
 static struct RGBcolour *GREEN __attribute__((unused)) = &(struct RGBcolour){.red = 0, .green = 255, .blue = 0};
 static struct RGBcolour *BLUE __attribute__((unused)) = &(struct RGBcolour){.red = 0, .green = 0, .blue = 255};
 static struct RGBcolour *YELLOW __attribute__((unused)) = &(struct RGBcolour){.red = 255, .green = 255, .blue = 0};
 static struct RGBcolour *MAGNETA __attribute__((unused)) = &(struct RGBcolour){.red = 255, .green = 0, .blue = 255};
 static struct RGBcolour *CYAN __attribute__((unused)) = &(struct RGBcolour){.red = 0, .green = 255, .blue = 255};
	
void graphical_writePixel(uint8_t x, uint8_t y, struct RGBcolour *newColour);
uint8_t graphical_getNumberOfArguments(enum graphical_shapeType newObjectType);
struct graphical_shape* graphical_addNewShape(enum graphical_shapeType newObjectType, struct RGBcolour *newColour, uint8_t z, ...);
void graphical_copyPixel(uint8_t firstX, uint8_t firstY, uint8_t secondX, uint8_t secondY);
void graphical_init(struct RGBcolour *colour);
void graphical_drawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t filled, struct RGBcolour *colour);
void graphical_drawCircle(uint8_t centerX, uint8_t centerY, uint8_t radius, uint8_t filled, struct RGBcolour *colour);
void graphical_drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, struct RGBcolour *colour);
struct RGBcolour* graphical_createRGBColour(uint8_t red, uint8_t green, uint8_t blue);
struct RGBAcolour* graphical_createRGBAColour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
void graphical_moveList(int16_t deltaX, int16_t deltaY);
void graphical_undrawList(/*struct graphical_linkedList *list*/);
void graphical_drawShapeColour(struct graphical_shape *object, struct RGBcolour *newColour);
void graphical_moveObjectByPosition(uint16_t listPosition, int16_t deltaX, int16_t deltaY);
#endif /* GRAPHICAL_H_ */