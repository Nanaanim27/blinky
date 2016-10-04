#define _FOSC 16000000
#define _BAUD 9600
#define _UBRR0 (_FOSC / 16 / _BAUD) - 1;  

/*
 * initializes the uart communication
 */
void usart_init(void); 

/*
 * transmits an entire string and flushes
 */ 
void usart_transmit_flush(unsigned char*); 
