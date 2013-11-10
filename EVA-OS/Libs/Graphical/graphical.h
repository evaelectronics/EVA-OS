/*
 * graphical.h
 *
 * Created: 8-11-2013 17:33:55
 *  Author: P
 */ 


#ifndef GRAPHICAL_H_
#define GRAPHICAL_H_

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

struct RGBcolour screenBuffer[WIDTH][HEIGHT];//the main on-chip buffer that contains realtime screen data

struct RGBcolour* display_createRGBColour(uint8_t red, uint8_t green, uint8_t blue);
struct RGBAcolour* display_createRGBAColour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

static struct RGBcolour *BLACK = &(struct RGBcolour){.red = 0, .green = 0, .blue = 0};	__attribute__((unused))
static struct RGBcolour *WHITE = &(struct RGBcolour){.red = 255, .green = 255, .blue = 255};__attribute__((unused))
static struct RGBcolour *RED = &(struct RGBcolour){.red = 255, .green = 0, .blue = 0};__attribute__((unused))
static struct RGBcolour *GREEN = &(struct RGBcolour){.red = 0, .green = 255, .blue = 0};__attribute__((unused))
static struct RGBcolour *BLUE = &(struct RGBcolour){.red = 0, .green = 0, .blue = 255};__attribute__((unused))
static struct RGBcolour *YELLOW = &(struct RGBcolour){.red = 255, .green = 255, .blue = 0};__attribute__((unused))
static struct RGBcolour *MAGNETA = &(struct RGBcolour){.red = 255, .green = 0, .blue = 255};__attribute__((unused))
static struct RGBcolour *CYAN = &(struct RGBcolour){.red = 0, .green = 255, .blue = 255};__attribute__((unused))
	
void graphical_writePixel(uint8_t x, uint8_t y, struct RGBcolour *newColour);
void graphical_copyPixel(uint8_t firstX, uint8_t firstY, uint8_t secondX, uint8_t secondY);
void graphical_init(struct RGBcolour *colour);
void graphical_drawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t filled, struct RGBcolour *colour);
void graphical_drawCircle(uint8_t centerX, uint8_t centerY, uint8_t radius, uint8_t filled, struct RGBcolour *colour);
void graphical_drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, struct RGBcolour *colour);
struct RGBcolour* display_createRGBColour(uint8_t red, uint8_t green, uint8_t blue);
struct RGBAcolour* display_createRGBAColour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);


#endif /* GRAPHICAL_H_ */