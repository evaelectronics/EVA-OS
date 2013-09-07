/*
 * circularbuffer.c
 *
 * Created: 9/6/2013 1:11:19 AM
 *  Author: Elmar
 */ 
#include "CircularBuffer.h"

uint8_t circularBuffer_dataLeft(CircularBuffer * buffer) {
	return (buffer->head - buffer->tail) - 1;
}

void circularBuffer_init(CircularBuffer * buffer){
	buffer->size = bufferSize;						// from 0 til buffersize
	buffer->head = 1;								// Head always has to be 1 ahead of the tail
	buffer->tail = 0;								// Read from the tail
	for(uint8_t i = 0; i<buffer->size; i++){		// Resetting
		buffer->data[i] = 'x';						// Resetting. Using an x for easier viewing while debugging
	}
}

int8_t circularBuffer_writeByte(CircularBuffer * buffer, char data){
	if(canWrite(buffer) == 0)
	return -1;
	buffer->data[buffer->head-1] = data;
	if (buffer->head == buffer->size) {
		buffer->head = 1;
		} else {
		buffer->head++;
	}
	return 1;
}

int8_t circularBuffer_readByte(CircularBuffer * buffer, char * data){
	if(canRead(buffer) == 0)
	return -1;
	*data = buffer->data[buffer->tail];
	
	if (buffer->tail >= buffer->size-1) {
		buffer->tail = 0;
		} else {
		buffer->tail++;
	}
	return 1;
}

uint8_t canRead(CircularBuffer * buffer){
	if( ((buffer->head - buffer->tail) == 1) || ((buffer->tail - buffer->size) == buffer->head) )
	return 0;
	return 1;
}

uint8_t canWrite(CircularBuffer * buffer){
	if( ((buffer->tail - buffer->head) == 1) || ((buffer->head - buffer->size) == buffer->tail) )
	return 0;
	return 1;
}

int8_t circularBuffer_read(CircularBuffer * buffer, char * data, uint8_t size){
	uint8_t amount = 0;
	while(canRead(buffer) && (size - amount > 0)){
		if(circularBuffer_readByte(buffer,(char *) data[amount]) == -1)
		return amount;
		amount++;
	}
	return amount;
}

uint8_t circularBuffer_write(CircularBuffer * buffer, char * data, uint8_t size){
	uint8_t amount = 0;
	while (size-amount>0 && canWrite(buffer)){
		if(circularBuffer_writeByte(buffer, data[amount]) == -1)
		return amount;
		amount++;
	}
	return amount;
}