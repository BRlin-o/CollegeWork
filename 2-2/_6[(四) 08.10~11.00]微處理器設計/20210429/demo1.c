#include "AT89X52.H"

sfr LED=0x80;

void main(){
	char i;
	loop:
		LED=((i/10)<<4)+(i%10);
		++i;
		if(i<100)goto loop;
		i=0;
		goto loop;
}