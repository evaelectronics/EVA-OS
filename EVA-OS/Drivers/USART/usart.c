/*
 * uart.c
 *
 * Created: 8/18/2013 5:02:10 PM
 *  Author: Elmar
 */ 
static void (*receiveEvent) (char);
static Usart * usart;
static uint8_t id;

void initUsart(Usart * _usart, uint8_t _id)
{
	id = _id;
	usart = _usart;
	usart->US_MR = US_MR_USART_MODE_HW_HANDSHAKING | US_MR_USCLKS_MCK |US_MR_CHRL_8_BIT;
	usart->US_BRGR = 195; // for 38,4 at 200 mHz
	usart->US_CR = US_CR_RXEN | US_CR_TXEN | US_CR_RSTSTA;
	PMC->PMC_PCER0 = 1 << id; // TODO check if its the right pmc
	initInterupt();
}

extern void initInterupt()
{
		NVIC_EnableIRQ(id);
		usart->US_IER = US_IER_RXRDY;
}

void USART0_Handler()
{
	uint32_t interruptStatus = usart->UART_SR;
	if(interruptStatus & US_IMR_RXRDY){
		char data = usart->UART_RHR;
		//process data
	}
	if(interruptStatus & US_IMR_TXRDY){// && usart->UART_IMR & UART_IMR_TXRDY){
		static char data;
		int8_t dataLeft = circularBuffer_readByte(&uart_outBuffer, & data);
		if(dataLeft == 1){
			usart->UART_THR = data;
			} else{
			usart->UART_IDR = US_IMR_TXRDY;// UART_IDR_TXRDY;
		}
	}	
}

void USART1_Handler()
{
	uint32_t interruptStatus = usart->UART_SR;
	if(interruptStatus & UART_SR_RXRDY){
		char data = usart->UART_RHR;
	}
	if(interruptStatus & UART_SR_TXRDY && usart->UART_IMR & UART_IMR_TXRDY){
		static char data;
		int8_t dataLeft = circularBuffer_readByte(&uart_outBuffer, & data);
		if(dataLeft == 1){
			usart->UART_THR = data;
		} else{
			usart->US_IDR = US_IER_TXRDY;
		}
	}
}

void uart_sendBytesBlocking(char * data, uint8_t length)
{
	uint8_t index = 0;
	while(index<length){
		uart_sendByteBlocking(data[index);
		index++;
	}	
}

void uart_sendByteBlocking(char byte)
{
	uart->UART_THR = byte;
	while((usart->US_CSR & US_IMR_TXRDY) == 0);	
}

void uart_readBytesBlocking(char * data, uint8_t length)
{
	uint8_t index = 0;
	while (index<length){
		while((usart->US_CSR & US_IMR_RXRDY) == 0);
		data[index] = uart->UART_RHR;
		index++;
	}	
}

void uart_sendByte(char start)
{
	circularBuffer_writeByte(&uart_outBuffer,start);
	usart->US_IER = US_IER_TXRDY;
}

void uart_sendBytes(char *start, uint8_t size)
{
	int index = 0;
	while(index<size){
		circularBuffer_writeByte(&uart_outBuffer,start[index]);
		index++;
	}
	usart->US_IER = US_IER_TXRDY;
}

uint8_t uart_receiveByte(char * data)
{
	return circularBuffer_readByte(&uart_inBuffer, &data);
}

uint8_t uart_receiveBytes(char * startAdress, uint8_t size)
{
	return circularBuffer_read(&uart_inBuffer,&startAdress, size);
}

void uart_setReceiveEvent(void (*_receiveEvent) (char))
{
	receiveEvent = _receiveEvent;
}

