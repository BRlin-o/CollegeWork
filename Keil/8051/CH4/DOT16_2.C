/***** DOT16_2.C ***16*16彩色點矩陣字型範例******
*動作：顯示四個不同彩色的16*16字型
*接線：由Data(P0)輸出低電位字型資料，P10~3掃描輸出，
*      P14選擇上半部紅色，P15選擇上半部綠色，
*      P16選擇下半部紅色，P17選擇下半部綠色，
*      P20第一字，P21第二字，P22第三字，P23第四字LED發亮
************************************************/
#include "..\AT89X52.H"  //暫存器及組態定義
#include "font16_4.h"	 //16*16中文字型
sfr  Data=0x80;   //P0資料BUS輸出
sfr  LED_CTR=0xa0;//LED_CTR=P2選擇矩陣LED字型
sbit LED_R_U=P1^4;//LED_R_U=0->1資料送到上半部矩陣紅色LED
sbit LED_G_U=P1^5;//LED_G_U=0->1資料送到上半部矩陣綠色LED
sbit LED_R_D=P1^6;//LED_R_D=0->1資料送到下半部矩陣紅色LED
sbit LED_G_D=P1^7;//LED_G_D=0->1資料送到下半部矩陣綠色LED

main()
{
  unsigned char repeat;  //定義重覆掃描次數
  unsigned char color=0; //定義彩色，0=紅色、1=綠色、2=黃色
  unsigned char i;       //定義資料計數  
 while(1)		  
 {
   for(repeat=0;repeat<20;repeat++)   //重覆掃瞄次數
    {   
      for(i=0;i<127;i=i+2) //讀取四個字型資料分偶數及奇數
       {
	     LED_CTR=0xff ;     //關閉所有矩陣LED
         if(color==0)       //若color=0(紅色)
	      {    
            Data=font16_4[i];     //取得中文字型的偶數資料輸出
            LED_R_U=0; LED_R_U=1; //送到上半部的矩陣紅色LED
          
            Data=font16_4[i+1];   //取得中文字型的奇數資料輸出
            LED_R_D=0; LED_R_D=1; //送到下半部的矩陣紅色LED
          
		    Data=0xff ;          //綠色暗             
			LED_G_U=0; LED_G_U=1;//令上半部的矩陣綠色LED暗
            LED_G_D=0; LED_G_D=1;//令下半部的矩陣綠色LED暗
	      }
	     if(color==1)  //若color=1(綠色)
	      {    
            Data=font16_4[i];     //取得中文字型的偶數資料輸出
            LED_G_U=0; LED_G_U=1; //令上半部的矩陣綠色LED亮
          
            Data=font16_4[i+1];   //取得中文字型的奇數資料輸出
            LED_G_D=0; LED_G_D=1; //令下半部的矩陣綠色LED亮
          
		    Data=0xff ;          //紅色暗
            LED_R_D=0; LED_R_D=1;//令下半部的矩陣紅色LED暗
            LED_R_U=0; LED_R_U=1;//令上半部的矩陣紅色LED暗
	      }
	     if(color==2) //若color=2(黃色)
	      {    
            Data=font16_4[i];    //取得中文字型的偶數資料輸出
            LED_R_U=0;LED_R_U=1; //令下半部的矩陣紅色LED亮
            LED_G_U=0;LED_G_U=1; //令下半部的矩陣綠色LED亮  
		  
		    Data=font16_4[i+1];  //取得中文字型的奇數資料輸出
		    LED_R_D=0;LED_R_D=1; //令上半部的矩陣紅色LED亮
            LED_G_D=0;LED_G_D=1; //令上半部的矩陣綠色LED亮
 	      }
       P1=i/2+0xf0;      //資料計數/2，由P10~3掃描輸出
	   if (i<=31)         LED_CTR=0xfe;//若第一字型，P20=0  
	   if (i>=32 & i<=63) LED_CTR=0xfd;//若第二字型，P21=0
	   if (i>=64 & i<=95) LED_CTR=0xfb;//若第三字型，P22=0
	   if (i>=96)         LED_CTR=0xf7;//若第四字型，P23=0 
   	  }
   }
  color++;	//換下一種彩色
  if(color > 2) color=0;//限制3種彩色    
 }
}