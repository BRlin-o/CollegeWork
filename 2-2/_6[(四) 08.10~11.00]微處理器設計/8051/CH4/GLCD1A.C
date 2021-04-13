/*****GLCD1.C****繪圖型LCD(橫排)實習板範例******
*動作：在繪圖型LCD最低下顯示橫線，往上移動 
*************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
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

  GLCD_Cmd(0xb8+7); //10111xxx+0~7，X頁位址=7最下頁
  GLCD_Cmd(0x40+0); //01xxxxxx+0~63，Y軸位址=0最左邊
  for(i=0; i< 64 ;i++) //寫入64筆 
    GLCD_Data(0x80);//寫入資料10000000,最低下一橫線 
  while(1)
  {
    for(i=0; i<64 ;i++) //計數=0~63
	{
	  //GLCD_Cmd(0xC0+i); //11xxxxxx+0~63，開始行數=0~63往上移
  	  Delay_ms(100);
	}
  }
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