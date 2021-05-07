#include <stdlib.h>
#include <stdio.h>
#include "../_8051/AT89X52.H"

void main() {
	unsigned char i;
	i = rand();
	i = i%6+1;
	while(1);
	// while(++i);
}