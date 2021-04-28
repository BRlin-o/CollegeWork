/********** music2.c ****************************
*動作：設定以Timer0計時中斷，令喇叭輸出各種音頻
************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sbit   SPEAK=0xA6; //P26喇叭輸出
#include "music.h"  //音頻定義
unsigned int  code Table[]  //定義音頻陣列資料,0為休止符  
   ={DO3,0,RE3,0,MI3,0,FA3,0,SO3,0,LA3,0,SI3,0,DO4,0};
char i;   //資料計數
main()
{   
 TMOD=0x01;   //設定Timer0為mode1內部計時 
 EA=1;ET0=1;  //致能Timer0中斷
 while (1)    //不斷循環執行
  {
   for(i=0; i<16; i++)   //陣列計數由0~15遞加  
    {
     if(Table[i]==0) TR0=0; //若資料=0為停止Timer0計時
	  else
	  {	
	   TL0=Table[i];TH0=Table[i] >>8; //設定計時值     
       TR0=1;            //啟動Timer0開始計時
	  }
     Delay_ms(1000);     //音長 
     TR0=0;              //停止Timer0計時 
    }
  }
}
/***************************************/
void T0_int(void) interrupt 1  //Timer0中斷函數
{
  TL0=Table[i] ; TH0=Table[i] >>8; //重新設定計時值
  SPEAK=!SPEAK;     //喇叭反相輸出
} 