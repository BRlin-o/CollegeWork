/***** DOT6.c ****點矩陣顯示器左移位字型********
*動作：顯示左移位四個字
*接線：Scan低電位掃描輸出，由Data低電位輸出資料
//**********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80; //P0資料BUS輸出
sfr  Scan=0x90; //P1點矩陣LED掃描輸出
#include "font4.h"  //字型ABCD資料檔
main() 
{ 
  unsigned char i;     //定義陣列資料計數
  unsigned char repeat;//定義重覆掃描次數	
  unsigned char start; //定義左移位字型開始讀取計數 
  
  Scan=0x7F; //由com1開始掃瞄  
 while(1)
 {
   for(start=0;start<24;start++) //開始計數限定4個字型
   {
   	for(repeat=0;repeat<10;repeat++)  //重覆掃瞄次數
     {
       for(i=0;i<8;i++)   //讀取8筆資料掃瞄8次
       {
         Data=font4[start+i];//讀取開始計數之後的陣列資料輸出
		 Delay_ms(1);       //延時
		 Data=0xff;       //全暗
         Scan=RR8(Scan); //換掃瞄下一行
       }
     } 
   }
 } 
}