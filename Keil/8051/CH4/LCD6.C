/****************** LCD顯示自創圖形範例***********
*檔名：LCD6.C
*動作：自創4個圖形，並令LCD顯示小綠人動畫 
********************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80;//P0資料BUS輸出
sbit RS=0x96;  //P16 LCD指令/資料控制,RS=0指令，RS=1資料
               //LCD讀取/寫入控制,R/W=GND寫入
sbit EN=0x97;  //P17 LCD致能輸出,EN=0禁能LCD，EN=1致能LCD

unsigned char  code Table[]= {   //自創5個小綠人圖形
         0x00,0x0c,0x1e,0x0c,0x06,0x07,0x07,0x0b, //圖0左上(向左行步1)
         0x00,0x00,0x00,0x00,0x00,0x18,0x04,0x02, //圖0右上
         0x11,0x01,0x01,0x01,0x06,0x1e,0x10,0x00, //圖0左下
         0x10,0x10,0x08,0x06,0x03,0x01,0x01,0x00, //圖0右下
         
         0x00,0x0c,0x1e,0x0c,0x06,0x07,0x06,0x03, //圖1左上(向左行步2)
         0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x08, //圖1右上
         0x03,0x05,0x03,0x04,0x04,0x03,0x0f,0x00, //圖1左下
         0x08,0x10,0x10,0x10,0x08,0x06,0x0c,0x00, //圖1右下
         
         0x00,0x00,0x00,0x00,0x00,0x03,0x04,0x08, //圖3左上(向右行步1)
         0x00,0x06,0x0f,0x06,0x0c,0x1c,0x1c,0x1a, //圖3右上
         0x01,0x01,0x02,0x0c,0x18,0x10,0x10,0x00, //圖3左下
         0x11,0x10,0x10,0x10,0x0c,0x0f,0x01,0x00, //圖3右下

         0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02, //圖4左上(向行步右2)
         0x00,0x06,0x0f,0x06,0x0c,0x1c,0x0c,0x18, //圖4右上
         0x02,0x01,0x01,0x01,0x02,0x0c,0x06,0x00, //圖4左下
         0x18,0x14,0x18,0x04,0x04,0x18,0x1e,0x00, //圖4右下
       };
 
 void DISPLAY(unsigned char i);  //在指定i位置  
 void write(unsigned char word);   //寫入指定字型資料到CGRAM
 //*************************************************
void main(void)
{
   unsigned char shift;
   LCD_init();     	// 重置及清除LCD  
   while(1)
   {     
     for(shift=14;shift>0;shift=shift-2)  // 由右向左移位
     {
     write(32*0);  DISPLAY(shift);        // 寫入圖0，移位顯示
     write(32*1);  DISPLAY(shift-1);      // 寫入圖1，移位顯示
     }
      for(shift=0;shift<14;shift=shift+2) // 由左向右移位
     {
     write(32*2);  DISPLAY(shift);        // 寫入圖2，移位顯示
     write(32*3);  DISPLAY(shift+1);      // 寫入圖3，移位顯示
     }
   }
}
//*************************************************
void write(unsigned char word)   	// 寫入指定圖形資料到CGRAM 
{
  unsigned char addr;
  for (addr=0x0;addr<=0x1f;addr++)  // 寫入位址
   {
     LCD_Cmd(0x40+addr);        // 指定CGRAM位址  
     LCD_Data(Table[addr+word]);// 寫入指定圖形資料到CGRAM
   } 
}
//*************************************************
void DISPLAY(unsigned char i) // 指定移位的位置，顯示自造圖形 
{
  unsigned char count;
  LCD_Cmd(0x80+i);	// 指定第一行i位置顯示
  for(count=0;count<2;count++)  
     LCD_Data(count);	// 讀取CGROM位址0-1(圖上)顯示
    
  LCD_Cmd(0xc0+i);	// 指定第二行i位置顯示
  for(count=2;count<4;count++)
     LCD_Data(count);	// 讀取CGROM位址2-3(圖下)顯示
 
  Delay_ms(10);    // 延時，圖形停滯時間
  LCD_Cmd(0x01);LCD_Cmd(0x02);//清除顯示幕 
}
/***********************************************************
*函數名稱: LCD_Data
*功能描述: 傳送資料到文字型LCD
*輸入參數：dat
************************************************************/
void LCD_Data(char dat)  //傳送資料到LCD
{
    Data=dat; //資料送到BUS
    RS=1;EN=1;//資料寫入到LCD內
    Delay_ms(1);   //LCD等待寫入完成
    EN=0;          //禁能LCD    
}
/***************************************************************
*函數名稱: LCD_Cmd
*功能描述: 傳送命令到文字型LCD
*輸入參數：Cmd
************************************************************/
void LCD_Cmd(unsigned char Cmd) //傳送命令到LCD
{
    Data=Cmd;  //命令送到BUS
    RS=0;EN=1; //命令寫入到LCD內
    Delay_ms(1);    //LCD等待寫入完成     
    EN=0;           //禁能LCD
}
/***************************************************************
*函數名稱: LCD_init
*功能描述: 啟始化文字型LCD
*****************************************************************/
void LCD_init(void)    //LCD的啟始程式  
{
    LCD_Cmd(0x38);/*0011 1000,8bit傳輸,顯示2行,5*7字型
                    bit4:DL=1,8bit傳輸,
                    bit3:N=1,顯示2行
                    bit2:F=0,5*7字型*/    
    LCD_Cmd(0x0c);/*0000 1100,顯示幕ON,不顯示游標,游標不閃爍
                    bit2:D=1,顯示幕ON
                    bit1:C=0,不顯示游標
	                bit0:B=0,游標不閃爍*/
    LCD_Cmd(0x06);/*0000 0110,//顯示完游標右移,游標移位禁能 
                    bit1:I/D=1,顯示完游標右移,
                    bit0:S=0,游標移位禁能*/  
    LCD_Cmd(0x01); //清除顯示幕  
    LCD_Cmd(0x02); //游標回原位  
}
