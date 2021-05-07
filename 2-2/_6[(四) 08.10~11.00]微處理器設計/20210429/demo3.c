#include "AT89X52.H"

sfr LED = 0x90;

void main(){
	unsigned char i=0;
	while(1){
		while(i<8){
			LED = i++;
		}
		i=0;
	}
}