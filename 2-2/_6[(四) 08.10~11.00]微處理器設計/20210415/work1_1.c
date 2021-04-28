#include "AT89X52.H" 	//既竟の舱篈砞﹚	
void test1() {  //ㄧ计Α1
	// sfr P0=0x80;
	static char i=10; 
	i=i+1; 
	P0=i; 
} 
void test2() { //ㄧ计Α2
	// sfr P1=0x90; 
	char j=10; 
	j=j+1; 
	P1=j; 
} 
void test1(void); 
void test2(void); 
void main() { //祘Α
	loop: 
		test1();//秈ㄧ计Α1 
		test2();//秈ㄧ计Α2 
	goto loop; 
} 
