#include "AT89X52.H" 	//暫存器及組態設定	
void main(){
  char  a=-3,b=0,c=5; //宣告輸入變數的初值
  unsigned char  d=0x0f;
  static char  i;  //宣告輸出變數
 loop:  
   i=-a;        //負負得正，i=3
   i=-c;        //i=-5
   P1_0=!P1_0; //令P10反相
   i=!b;        //b=0，反相後為i=1
   i=!c;        //c=5不為0，故反相後i=0
   P1=~d;       //d=0x，由P1反相輸出為0xf0
 goto loop;
}