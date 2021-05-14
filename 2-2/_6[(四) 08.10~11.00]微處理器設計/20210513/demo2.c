#include "../_8051/AT89X52.H"
#include "../_8051/CH4/font4.h"

sfr Data = 0x80;
sfr Scan = 0x90;
bit inver=0;
void main(){
	unsigned char i, repeat, start;
	
	Scan = 0x7F;
	while(1){
		for(start=0;start<32;++start){
			for(repeat=0;repeat<10;++repeat){
				for(i=0;i<8;++i){
					Data = font4[start+i];
					Delay_ms(1);
					Data = 0xff;
					Scan = RR8(Scan)
				}
			}
		}
	}
}
