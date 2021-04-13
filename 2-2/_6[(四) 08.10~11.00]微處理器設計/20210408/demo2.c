#include "AT89X52.H"

// char TABLE[8]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

#include "TABLE8.H"

sfr LED = 0x80;

main() {
	unsigned char i=0;
	loop:
		LED=TABLE[i++];
		Delay_ms(500);
	goto loop;
}