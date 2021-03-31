#include "AT89X52.h"

void main() {
	uint8 i = 250;
	int8 j= -120;
	uint16 k = 65530;
	uint32 l = 0x12345678;
	fp32 m = 1.02;
	loop:
		i++;
		++j;
		++k;
		l++;
		m+=0.01;
	goto loop;
}