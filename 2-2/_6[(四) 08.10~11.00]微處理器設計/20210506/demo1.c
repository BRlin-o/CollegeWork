#include "../_8051/AT89X52.H"
void beep(unsigned char i);
sbit SPK=0xA6;
sbit DO_BUTTON = 0xB2;

unsigned char toBeep;

void main(void) {
	while(1) {
		beep(1);
		Delay_ms(500);
		beep(2);
		Delay_ms(500);
		beep(3);
		Delay_ms(500);
	}
}

void beep(unsigned char j){
	unsigned int i;
	while(j--){
		for(i=0;i<=400;++i) {
			if(DO_BUTTON == 0){SPK = !SPK;}
			Delay_ms(1);
		}
		Delay_ms(200);
	}
	
}