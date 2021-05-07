#include "../_8051/AT89X52.H"
sfr Data = 0x80;
unsigned char code Table[] = {
	0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};

int myPow(int n, int m){
	if(m==0)
		return 1;
	if(m==1)
		return n;
	return n*myPow(n, m-1);
}

void main(void) {
	char i, j;
	while(1){
		for(i=0;i<4;++i){
			unsigned char index = myPow(2, i);
			P1 = 0xff & (~index);
			for(j=0;j<16;++j){
				Data = ~ Table[j];
				Delay_ms(200);
			}
			Data = ~ Table[i];
		}
	}
}