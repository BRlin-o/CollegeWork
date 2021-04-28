#include "AT89X52.H"
void test1() {  //函數式1
	sfr P0=0x80; 
	static char i=10; 
	i=i+1; 
	P0=i; 
} 
void test2() { //函數式2
	sfr P1=0x90; 
	char j=10; 
	j=j+1; 
	P1=j; 
} 
void test1(void); 
void test2(void); 
main() { //主程式
	loop: 
		test1();//進入函數式1 
		test2();//進入函數式2 
	goto loop; 
} 
