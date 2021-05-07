#include "../_8051/AT89X52.H"
sfr Data = 0x80;
sbit SSLED0 = 0x90;
sbit SSLED1 = 0x91;
sbit SSLED2 = 0x92;
sbit SSLED3 = 0x93;

unsigned char delay_t = 1;

unsigned char code Table[] = {
	0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};
unsigned char code Table_Length = 10;

void main(){
	unsigned char scan;
	unsigned int count = 0x1234;
	unsigned char i;
	while(1){
		for(scan=0;scan<10;++scan){
			SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
			i=count & 0x000f;
			Data = ~Table[i];
			SSLED0 = 0;
			Delay_ms(delay_t);
			
			SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
			i=(count & 0x00f0)>>4;
			Data = ~Table[i];
			SSLED1 = 0;
			Delay_ms(delay_t);
			
			SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
			i=(count & 0x0f00)>>8;
			Data = ~Table[i];
			SSLED2 = 0;
			Delay_ms(delay_t);
			
			SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
			i=(count & 0xf000)>>12;
			Data = ~Table[i];
			SSLED3 = 0;
			Delay_ms(delay_t);
		}
		count++;
	}
}