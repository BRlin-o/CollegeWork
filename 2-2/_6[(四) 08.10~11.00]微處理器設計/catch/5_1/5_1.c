#include "AT89X52.H"

void main(void) {
	unsigned char i=0;
	
	EA=1;
	EX0=1;
	while(1){
		P0=i;
		Delay_ms(50);
		i++;
	}
}

void EX0_int(void) interrupt 0{
	char i=0;
	unsigned int dly;
	for(i=0;i<5;++i){
		P0 = 0x00;
		for(dly=0;dly<20000;++dly);
		
		P0 = 0xff;
		for(dly=0;dly<20000;++dly);
	}	
}