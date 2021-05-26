#include "AT89X52.H"

sfr LED = 0x80;

void main(void) {
	EA = 1;
	EX1 = 1;
	IT1 = 1;
	while(1);
}

void EX1_int(void) interrupt 2 {
	++LED;
}