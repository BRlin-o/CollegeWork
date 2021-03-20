/************ SEG2.C ***************************
*動作：四位數掃描計數器，以十六進制顯示0000~ffff
*接線：Data=七段顯示器低電位輸出=Pgfedcba
*      低電位掃描：SSLED3~0=千、百、十、個位數
***********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80;//P0資料BUS輸出
sbit SSLED0=0x90; //P10七段顯示器個位數選擇輸出
sbit SSLED1=0x91; //P11七段顯示器十位數選擇輸出
sbit SSLED2=0x92; //P12七段顯示器百位數選擇輸出
sbit SSLED3=0x93; //P13七段顯示器千位數選擇輸出

 unsigned char code Table[] //0~F數碼資料
  ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
 
main() 
{
  unsigned char scan;  //掃描次數  
  unsigned int count=0x1234; //計數初值 
  unsigned char i;    //擷取計數的個、十、百、千位數 

   while(1)     //重覆執行
    {
     for(scan=0;scan<10;scan++) //重覆掃描次數 
      {
       SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒
	   i=count & 0x000f;  //取出個位數 
       Data=~Table[i];//讀取個位數碼資料輸出
       SSLED0=0;       //選擇個位數顯示器
       Delay_ms(10);   //掃描延時  
       
	   SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒          
       i=(count & 0x00f0)>>4; //取出十位數 
       Data=~Table[i];//讀取十位數碼資料輸出
       SSLED1=0;       //選擇十位數顯示器
       Delay_ms(10);   //掃描延時
       
	   SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒                     
       i=(count & 0x0f00)>>8; //取出百位數 
       Data=~Table[i];//讀取百位數碼資料輸出
       SSLED2=0;       //選擇百位數顯示器
       Delay_ms(10);   //掃描延時
       
	   SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒
       i=(count & 0xf000)>>12;//取出千位數 
       Data=~Table[i];//讀取千位數碼資料輸出
       SSLED3=0;       //選擇千位數顯示器
       Delay_ms(10);   //掃描延時
     }	   
     count++;  //計數+1 
   } 
}