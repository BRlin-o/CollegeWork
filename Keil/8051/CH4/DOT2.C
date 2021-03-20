/***** DOT2.c ******8*8點矩陣固定字型範例*****
*動作：輸出陣列字型資料，顯示字型
*接線：Scan低電位掃描輸出，由Data低電位輸出資料
************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80; //P0資料BUS輸出
sfr  Scan=0x90; //P1點矩陣LED掃描輸出
#include "font.h"  //字型資料檔
main() 
{ 
  char i; //定義陣列資料計數
  Scan=0x7F;       //由com1開始掃瞄輸出  
  while(1)		  
  {
    for(i=0;i<8;i++)   //讀取8筆資料掃瞄8次
     {
       Data=font[i];   //讀取陣列資料輸出
       Delay_ms(1);    //延時
       Data=0xFF;      //全暗	       
	   Scan=RR8(Scan); //換掃瞄下一行
     } 
  } 
} 