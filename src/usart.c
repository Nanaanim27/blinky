#include "usart.h"
#include "avr/io.h"

void usart_init(void)
{
	// load the baud rate register value
	unsigned int ubrr0 = _UBRR0;

	// set the baud rate register for port 0
	UBRR0L = (unsigned char) ubrr0;
	UBRR0H = (unsigned char) (ubrr0 >> 8);

	// enable transmit and receive
	UCSR0B = 0x03 << 2;

	// set async USART, no parity, 1 stop bit, 8 data bits
	UCSR0C = 0x06;
}


void usart_transmit_flush(unsigned char* msg)
{
	unsigned char c;
	while ((c = *(msg++)) != 0x00)
	{
		// wait for the transmit buffer to empty
		while (!(UCSR0A & 0x20));
		// send the current character
		UDR0 = c; 	
	}
}
