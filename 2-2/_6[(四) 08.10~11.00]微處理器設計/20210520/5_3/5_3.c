#include "../_8051/AT89X52.H"

void main(void){
	unsigned char j=0;
	EA = 1;
	EX0 = EX1 = 1;
	// IT0 = IT1 = 1;
	PX1 = 1;
	while(1){
		P0 = j;
		Delay_ms(100);
		++j;
	}
}

void EX0_int(void) interrupt 0 {
	char i;
	int dly;
	for(i=0;i<50;++i){
		P0 = 0x00;
		for(dly=0;dly<20000;++dly);
		
		P0 = 0xff;
		for(dly=0;dly<20000;++dly);
	}	
}

void EX1_int(void) interrupt 2 {
	char i;
	unsigned int dly = 0;
	for(i=0;i<50;++i){
		P0 = i;
		for(dly=0;dly<20000;++dly);
	}
}