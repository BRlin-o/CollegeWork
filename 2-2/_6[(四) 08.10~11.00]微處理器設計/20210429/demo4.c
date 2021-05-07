#include "AT89X52.H"

sfr LED = 0x80;

void main() {
	char i = -1, sum = 0;
	
	while(i<(10-1)){
		sum+=(i+=2);
	}
	LED = sum;
	for(;;);
}