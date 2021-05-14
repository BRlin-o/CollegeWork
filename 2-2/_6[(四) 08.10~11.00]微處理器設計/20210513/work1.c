#include "../_8051/AT89X52.H"

void beepGround(unsigned char);
void show7(unsigned int);

sfr Data = 0x80;
sbit SSLED0 = 0x90;
sbit SSLED1 = 0x91;
sbit SSLED2 = 0x92;
sbit SSLED3 = 0x93;
sbit SPK=0xA6;
sbit KEY = P3^2;

unsigned char delay_t = 1;
unsigned char scan_t = 1;

unsigned char code Table[] = {
	0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};
unsigned char code Table_Length = 10;

void main(){
	unsigned int i = 9995;
	SPK = 0;
	
	while(1){
		if(i<9995){
			++i;
			show7(i);
		}else{
			if(i>=10000){
				i = 0;
				beepGround(5);
				continue;
			}
			do{
				while(KEY==1)show7(i);
				Delay_ms(20);
			}while(KEY==1);
			++i;
			do{
				while(KEY==0)show7(i);
				Delay_ms(20);
			}while(KEY==0);
		}
	}
}

void show7(unsigned int i){
	unsigned char scan;
	unsigned char num;
	for(scan=0;scan<10;++scan){
		SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
		num=i%10;
		Data = ~Table[num];
		SSLED0 = 0;
		Delay_ms(scan_t);
		
		SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
		num=(i%100)/10;
		Data = ~Table[num];
		SSLED1 = 0;
		Delay_ms(scan_t);
		
		SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
		num=(i%1000)/100;
		Data = ~Table[num];
		SSLED2 = 0;
		Delay_ms(scan_t);
		
		SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
		num=i/1000;
		Data = ~Table[num];
		SSLED3 = 0;
		Delay_ms(scan_t);
	}
	SSLED0 = SSLED1 = SSLED2 = SSLED3 = 1;
}

void beepGround(unsigned char j){
	unsigned int i;
	while(j--){
		for(i=0;i<=400;++i) {
			SPK = !SPK;
			Delay_ms(1);
		}
		Delay_ms(200);
	}
	SPK = 0;
}
