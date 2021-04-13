#include "AT89X52.H"
// 這裡都要宣告成全域變數
// sfr P0=0x80;
// sfr P1=0x90;
// sfr P2=0xA0;
// sfr P3=0xB0;
sfr16 Timer2=0xCC;
// sbit P0_0 = 0x80; 
// sbit P0_1 = 0x81; //0x80的第二個位元(P0_1=0x80'1);
// sbit P0_2 = 0x80;
//////////////////////////

/*
void test(void) {
	static char i = 10;
	i = i + 1;
	P0 = i;
}

void test1(void){
	char j = 10;
	j = j + 1;
	P1 = j;
}
*/

extern void test(void);
extern void test1(void);
unsigned char k;

main () {
	bit flag = 0;
	register unsigned char k = 0;
	loop:
		//flag=1;
		//P0=0x38;
		//P0_0=1;
		//P0_1=1;
		//Timer2=0xAABB;
		//flag=0;
		k=1;
		test();
		test1();
	goto loop;
}