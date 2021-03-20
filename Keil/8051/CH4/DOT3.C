/***** DOT3.c ****點矩陣顯示器反白閃爍字型**************
*動作：顯示字型反白閃爍字型
*接線：Scan低電位掃描輸出，由Data低電位輸出資料
**********************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80; //P0資料BUS輸出
sfr  Scan=0x90; //P1顯示器8*8點矩陣LED掃描輸出
#include "font.h"  //字型資料檔
main() 
{ 
  char i;       //定義陣列資料計數
  unsigned char repeat;  //定義重覆掃描次數	 
  bit invert=0;          //定義反白顯示旗標  

  Scan=0x7F; //由com1開始掃瞄 
 while(1)
 {
   for(repeat=0;repeat<50;repeat++) //重覆掃瞄次數
    {
      for(i=0;i<8;i++)   //讀取8筆資料掃瞄8次
       {
         if(invert==0) Data=font[i];//若旗標=0，讀取陣列資料輸出
		    else Data=~font[i]; //若旗標=1，讀取陣列資料反相輸出
          Delay_ms(1);    //延時
	      Data=0xFF;      //全暗
          Scan=RR8(Scan); //換掃瞄下一行
       }
     } 
   invert=!invert;     //反白旗標反相   
  } 
}