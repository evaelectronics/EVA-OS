/*
 * circularbuffer.h
 *
 * Created: 9/6/2013 1:11:27 AM
 *  Author: Elmar
 */ 


#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_


#include <sam4s.h>
#define bufferSize 1024

typedef struct {
	uint8_t	size;
	uint8_t	head;
	uint8_t tail;
	char data[bufferSize];
} CircularBuffer;

void circularBuffer_init(CircularBuffer * buffer);
int8_t circularBuffer_writeByte(CircularBuffer * buffer, char data);
int8_t circularBuffer_readByte(CircularBuffer * buffer, char * data);
uint8_t canRead(CircularBuffer * buffer);
uint8_t canWrite(CircularBuffer * buffer);
uint8_t circularBuffer_dataLeft(CircularBuffer * buffer);
int8_t circularBuffer_read(CircularBuffer * buffer, char * data, uint8_t size);
uint8_t circularBuffer_write(CircularBuffer * buffer, char * data, uint8_t size);




#endif /* CIRCULARBUFFER_H_ */