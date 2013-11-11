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

enum graphical_objectType{ RECTANGLE, CIRCLE, LINE};

struct graphical_linkedList {
	struct graphical_object *first;
	struct graphical_object *last;
};

struct graphical_object {
	struct graphical_object *previous;
	enum graphical_objectType objectType;
	uint8_t arguments[5];
	struct RGBAcolour *colour;
	struct graphical_object *next;
};

struct RGBcolour screenBuffer[WIDTH][HEIGHT];//the main on-chip buffer that contains realtime screen data

struct RGBcolour* graphical_createRGBColour(uint8_t red, uint8_t green, uint8_t blue);
struct RGBAcolour* graphical_createRGBAColour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

 static const struct RGBcolour const *BLACK __attribute__((unused)) = &(struct RGBcolour){.red = 0, .green = 0, .blue = 0};
 static const struct RGBcolour const *WHITE __attribute__((unused)) = &(struct RGBcolour){.red = 255, .green = 255, .blue = 255};
 static const struct RGBcolour const *RED __attribute__((unused)) = &(struct RGBcolour){.red = 255, .green = 0, .blue = 0};
 static const struct RGBcolour const *GREEN __attribute__((unused)) = &(struct RGBcolour){.red = 0, .green = 255, .blue = 0};
 static const struct RGBcolour const *BLUE __attribute__((unused)) = &(struct RGBcolour){.red = 0, .green = 0, .blue = 255};
 static const struct RGBcolour const *YELLOW __attribute__((unused)) = &(struct RGBcolour){.red = 255, .green = 255, .blue = 0};
 static const struct RGBcolour const *MAGNETA __attribute__((unused)) = &(struct RGBcolour){.red = 255, .green = 0, .blue = 255};
 static const struct RGBcolour const *CYAN __attribute__((unused)) = &(struct RGBcolour){.red = 0, .green = 255, .blue = 255};
	
void graphical_writePixel(uint8_t x, uint8_t y, struct RGBcolour *newColour);
void graphical_copyPixel(uint8_t firstX, uint8_t firstY, uint8_t secondX, uint8_t secondY);
void graphical_init(struct RGBcolour *colour);
void graphical_drawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t filled, struct RGBcolour *colour);
void graphical_drawCircle(uint8_t centerX, uint8_t centerY, uint8_t radius, uint8_t filled, struct RGBcolour *colour);
void graphical_drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, struct RGBcolour *colour);
struct RGBcolour* graphical_createRGBColour(uint8_t red, uint8_t green, uint8_t blue);
struct RGBAcolour* graphical_createRGBAColour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);


#endif /* GRAPHICAL_H_ */