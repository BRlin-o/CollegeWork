/*******KEY4.C**********************
*動作：在LCD顯示"KEY="，按鍵由LCD顯示4位數
*接腳：列ROW0=P10,ROW1=P11,ROW2=P12,ROW3=P13,ROW4=P14 
*      行COL0=P20,COL1=P21,COL2=P22,COL3=P23 
*      P0=LCD的Data，P16=RS，RW=GND，P17=EN
*****************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80;//P0資料BUS輸出
sbit RS=0x96;  //P16 LCD指令/資料控制,RS=0指令，RS=1資料
               //LCD讀取/寫入控制,R/W=GND寫入
sbit EN=0x97;  //P17 LCD致能輸出,EN=0禁能LCD，EN=1致能LCD

sfr  ROW=0x90;  //P1為按鍵掃描輸出接腳
sbit COL0=P2^0;	//P2按鍵輸入接腳
sbit COL1=P2^1;
sbit COL2=P2^2;
sbit COL3=P2^3;
char code  Table[]="KEY="; //第一行陣列字元

void dataout(uint8 keyout); //按鍵資料輸出
char i=0;  //LCD顯示位置
void main()
{
 char count=0;   //按鍵計數=0
 unsigned char scan=0xfe;  //按鍵掃描令ROW0=0，其餘為1
 LCD_init();     	// 重置及清除LCD
 LCD_Cmd(0x80);     //游標由第一行開始顯示  
 for(i=0; i<4; i++) //讀取陣列"KEY= "字元到LCD顯示出來 
   LCD_Data(Table[i]);   
 while(1)   //重覆執行
  {
    if(count>19){scan=0xfe;count=0;}//若計數>19，從頭開始
    ROW=scan;		  //掃描輸出
	if(COL0==0) dataout(count);//檢查COL0列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL1==0) dataout(count);//檢查COL1列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL2==0) dataout(count);//檢查COL2列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL3==0) dataout(count);//檢查COL3列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    scan=RL8(scan); //左旋轉，換掃下一列,令ROW0~4輪流為0
   }
}
/***********************************************************
*函數名稱: dataout
*功能描述: 按鍵輸出資料送到LCD顯示數字，檢查是否放開按鍵
*輸入參數：keyout
************************************************************/
void dataout(char keyout) 
{
  if(keyout>9) keyout=keyout+7; //數字超過9修正顯示A~F
  LCD_Data(keyout+'0');  //送到七段顯示器輸出
  Delay_ms(1);       	//處理按鍵跳動之延遲
  while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
  Delay_ms(1);       //處理按鍵跳動之延遲
  i++;
  if(i>=4){i=0;LCD_Cmd(0x84);} //LCD顯示4個數字
}
/***********************************************************
*函數名稱: LCD_Data
*功能描述: 傳送資料到文字型LCD
*輸入參數：dat
************************************************************/
void LCD_Data(char dat)  //傳送資料到LCD
{
    Data=dat; //資料送到BUS
    RS=1;  EN=1;//資料寫入到LCD內
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
    RS=0;   EN=1; //命令寫入到LCD內
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
