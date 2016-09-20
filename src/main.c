#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// set port B as output
	DDRB = 0b11111111;

	while(1 == 1)
	{
		// turn LED on
		PORTB = PORTB | 1;
		// wait for 500 ms
		_delay_ms(500);
		// turn LED off
		PORTB = PORTB & (0xFF << 1);
		// wait 500 ms again
		_delay_ms(500);
	}
}
