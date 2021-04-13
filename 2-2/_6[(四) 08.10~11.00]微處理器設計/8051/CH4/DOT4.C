/******* DOT4.C *****點矩陣顯示器切換字型字型************
*動作：顯示切換字型
*接線：Scan低電位掃描輸出，由Data低電位輸出資料
************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80; //P0資料BUS輸出
sfr  Scan=0x90; //P1點矩陣LED掃描輸出
#include "font4.h"  //字型ABCD資料檔
main() 
{ 
  unsigned char i;      //定義陣列資料計數
  unsigned char repeat; //定義重覆掃描次數	
  unsigned char j=0;    //定義陣列啟始計數	
  Scan=0x7F;            //由com1開始掃瞄輸出  
  while(1)
   {
    j=0;
    while(j<8*4)        //設定顯示4個字
     {
       for(repeat=0;repeat<50;repeat++) //重覆掃瞄次數
        {
          for(i=j;i<j+8;i++) //讀取8筆資料掃瞄8次
           {
             Data=font4[i]; //讀取陣列資料
             Delay_ms(1);    //延時
		     Data=0xFF;     //全暗    
             Scan=RR8(Scan); //換掃瞄下一行
           }        
        } 
       j=j+8; //換下一個字  
     }  
   }
}