#include "../_8051/AT89X52.H"

sfr LED = 0x80;
sbit KEY = P3^2;

void main(void) {
	LED=0;
	while(1){
		do{
			while(KEY==1);
			Delay_ms(20);
		}while(KEY==1);
		LED++;
		do{
			while(KEY==0);
			Delay_ms(20);
		}while(KEY==0);
	}
}