/******* DOT8.C ****8*8彩色點矩陣顯示器字型範例*******
*動作：輸出陣列字型資料，顯示不同彩色的字型
*接線：Scan低電位掃描輸出，由Data低電位輸出紅色資料
      ，由Data_G低電位輸出綠色資料
************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80;   //P0紅色資料輸出
sfr  Scan=0x90;   //P1點矩陣LED掃描輸出
sfr  Data_G=0xa0; //P2綠色資料輸出
#include "font.h"  //字型A資料檔
main() 
{
 unsigned char  i;      //定義陣列資料計數
 unsigned char repeat;  //定義重覆掃描次數
 unsigned char color=0; //定義彩色，0=紅色、1=綠色、2=黃色
 unsigned char scan=0x7F;  //定義掃描變數  
 while(1)		  
 {
   for(repeat=0;repeat<20;repeat++)   //重覆掃瞄次數
    {   
      for(i=0;i<8;i++)  //讀取8筆資料掃瞄8次
       {
       	 Scan=0xFF;  //全暗
		 if(color==0){Data=font[i];Data_G=0xFF;}//輸出紅色字型資料
		 if(color==1){Data_G=font[i];Data=0xFF;}//輸出綠色字型資料        
	     if(color==2){Data=Data_G=font[i];}     //輸出黃色字型資料 
		 Scan=scan;	     //掃描輸出
		 Delay_ms(1);    //延時
	     scan=RR8(scan); //換掃瞄下一行		 
       }	 
    }
   color++;	//換下一種彩色
   if(color > 2) color=0;	//限制3種彩色  
 } 
} 