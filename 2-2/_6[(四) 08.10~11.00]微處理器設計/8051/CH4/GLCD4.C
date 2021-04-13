/*****GLCD4.C****繪圖型LCD(橫排)實習板範例******
*動作：在繪圖型LCD上顯示"應用電子"
*步驟：用MatrixFont 20個16x16字型.exe，輸入四個中文字
*      不進行設定，再匯出檔案test。
*************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
#include "test.H"
sfr    Data=0x80;//P0資料BUS輸出
sbit   DI=0x96;  //P16 LCD指令/資料控制,DI=0指令，DI=1資料
                 //LCD讀取/寫入控制,R/W=GND寫入
sbit   EN=0x97;  //P17 LCD致能輸出,EN=0禁能LCD，EN=1致能LCD
sbit   CS1=0x94; //CS1=1，繪圖型LCD左半部選擇
sbit   CS2=0x95; //CS2=1，繪圖型LCD右半部選擇
main()
{
  unsigned char i,x_page;  //定義計數變數
  CS1=1;CS2=1;	    //開啟繪圖型LCD左右半部
  Delay_ms(5);      //等待LCD開機時間
  GLCD_Cmd(0x3f);   //0011111D，D=1開啟螢幕
  for (x_page=0;x_page<8;x_page++)	//選擇X頁位址=0~7，清除所有畫面
  {
    GLCD_Cmd(0xb8+x_page); //10111xxx+0~7，設定X頁位址
  	GLCD_Cmd(0x40+0); //01xxxxxx+0~63，Y軸開始位址=0最左邊
    for(i=0; i< 64 ;i++) //寫入64筆 
      GLCD_Data(0);//寫入資料00000000,清除畫面 
   }

  CS1=1;CS2=0;	    //開啟繪圖型LCD左半部
  GLCD_Cmd(0xb8+0); //10111xxx+0~7，X頁位址=0(字的上半部)
  GLCD_Cmd(0x40+0); //01xxxxxx+0~63，Y軸位址=0最左邊
  for(i=0; i< 16*4 ;i++) //寫入64筆 
   {
    GLCD_Data(test[i*2]);//寫入偶數資料(字的上半部) 
	Delay_ms(10);
   }
  GLCD_Cmd(0xb8+1); //10111xxx+0~7，X頁位址=1(字的下半部)
  GLCD_Cmd(0x40+0); //01xxxxxx+0~63，Y軸位址=0最左邊
  for(i=0; i< 16*4 ;i++) //寫入64筆 
   {
	 GLCD_Data(test[i*2+1]);//寫入奇數資料(字的下半部)
     Delay_ms(10);
    }
  while(1);	//停止 
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