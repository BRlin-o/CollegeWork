/*****GLCD5.C****繪圖型LCD(橫排)實習板範例******
*動作：在繪圖型LCD上顯示16個中文字
*步驟：用MatrixFont 20個16x16字型.exe，輸入兩組8個中文字
*      不進行設定，再匯出檔案test1及test2。
****************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
#include "test1.h"  //第一組8個中文字型
#include "test2.h"  //第二組8個中文字型
sfr    Data=0x80;//P0資料BUS輸出
sbit   DI=0x96;  //P16 LCD指令/資料控制,DI=0指令，DI=1資料
                 //LCD讀取/寫入控制,R/W=GND寫入
sbit   EN=0x97;  //P17 LCD致能輸出,EN=0禁能LCD，EN=1致能LCD
sbit   CS1=0x94; //CS1=1，繪圖型LCD左半部選擇
sbit   CS2=0x95; //CS2=1，繪圖型LCD右半部選擇
/********************************************
*函數名稱:FillHWAN
*功能描述:寫入資料到繪圖型LCD的上或下半部，顯示4個中文字
*輸入參數：*pp
**********************************************/
void FillHWAN(unsigned char code *pp,char xp_start)
{
  char y_addr; //定義LCD顯示Y軸位址
  for(y_addr=0; y_addr < 64; y_addr++) //X軸位址0,32
  {
     GLCD_Cmd(0xb8+xp_start+0); //Y軸位址0,間隔32，分開上下
     GLCD_Cmd(0x40+y_addr); //X頁位址0~7
     GLCD_Data(*pp++);  //以指標方式讀取資料，寫入由左而右2個字
     GLCD_Cmd(0xb8+xp_start+1); //Y軸位址0,間隔32，分開上下
     GLCD_Cmd(0x40+y_addr); //X頁位址0~7
     GLCD_Data(*pp++);  //以指標方式讀取資料，寫入由左而右2個字   
  }
}
/**********************************************/
main()
{
  char i,x_page;  //定義資料計數  
  CS1=CS2=1;	  //開啟繪圖型LCD上下半部控制
  Delay_ms(5);      //等待GLCD開機時間
  GLCD_Cmd(0x3f);   //0011111D，D=1開啟螢幕
  for(x_page=0;x_page<8;x_page++)//選擇X頁位址=0~7，清除所有畫面
  {
    GLCD_Cmd(0xb8+x_page); //10111xxx+0~7，設定X頁位址
  	GLCD_Cmd(0x40+0);      //01xxxxxx+0~63，Y軸開始位址=0最左邊
    for(i=0; i< 64 ;i++) //寫入64筆 
      GLCD_Data(0);//寫入資料00000000,清除畫面 
   }

  CS1=1; CS2=0;     //開啟繪圖型LCD左半部顯示
  FillHWAN(&test1[0],0);//以指標方式讀取資料，寫入前4個字型
  
  CS1=0; CS2=1;	  //開啟繪圖型LCD右半部顯示
  FillHWAN(&test1[128],0);//以指標方式讀取資料，寫入後4個字型
  
  CS1=1; CS2=0;     //開啟繪圖型LCD左半部顯示
  FillHWAN(&test2[0],2);//以指標方式讀取資料，寫入前4個字型
  
  CS1=0; CS2=1;	  //開啟繪圖型LCD右半部顯示
  FillHWAN(&test2[128],2);//以指標方式讀取資料，寫入後4個字型

   while(1);   //停止
 
}
/*******************************************
*函數名稱: GLCD_Cmd
*功能描述: 寫入命令到繪圖型LCD
*輸入參數：cmd
*********************************************/
void GLCD_Cmd(unsigned char cmd)
{
	Data=cmd;	//輸出命令	
	DI=0;EN=1;	//寫入命令
    Delay_ms(10);EN=0; 	//等待寫入完成	
}
/********************************************
*函數名稱: GLCD_Data
*功能描述: 寫入資料到繪圖型LCD
*輸入參數：dat
*********************************************/
void GLCD_Data(char dat)
{
	Data=dat;  	 //輸出資料
	DI=1;EN=1;	//寫入資料
    Delay_ms(10);EN=0; 	//等待寫入完成	
}