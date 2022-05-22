/*
 * GccApplication19.c
 *
 * Created: 22/08/2021 10:30:20 ص
 * Author : El-Wattaneya
 */ 

#include <avr/io.h>
#include <util/delay.h>
unsigned char bcd_to_7seg(unsigned char);



void main(void)
{
	unsigned char counter =0;
	DDRC=0b01111111;
	while(1)
	{
		PORTC=bcd_to_7seg(counter);
		counter++;
		_delay_ms(250);
		if(counter>9)counter=0;
		
	}
}
unsigned char bcd_to_7seg(unsigned char num)
{
	switch(num)
	{
		case 0:
		return 0b00111111;
		case 1:
		return 0b00000110;
		case 2:
		return 0b01011011;
		case 3:
		return 0b01001111;
		case 4:
		return 0b01100110;
		case 5:
		return 0b01101101;
		case 6:
		return 0b11111101;
		case 7:
		return 0b00000111;
		case 8:
		 return 0b01111111;
		 case 9:
		 return 0b01101111;
	}
}
		
	