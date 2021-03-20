/******** KEY1.C******4*5鍵盤實習範例***************
*動作：ROW0~4掃描輸出,COL0~3按鍵輸入,P0=按鍵資料輸出
*接腳：列ROW0=P10,ROW1=P11,ROW2=P12,ROW3=P13,ROW4=P14  
*      行COL0=P20,COL1=P21,COL2=P22,COL3=P23 
***********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
void dataout(char keyout);//按鍵資料輸出
sfr  LED=0x80;  //P0為LED輸出
sbit ROW0=P1^0;	//P1為掃描輸出接腳
sbit ROW1=P1^1;
sbit ROW2=P1^2;
sbit ROW3=P1^3;
sbit ROW4=P1^4;
sbit COL0=P2^0;	//P2為按鍵輸入接腳
sbit COL1=P2^1;
sbit COL2=P2^2;
sbit COL3=P2^3;

void main()
{
  LED=0;      //設定按鍵資料=00
  while(1)   //重覆執行
  {
   ROW0=ROW1=ROW2=ROW3=ROW4=1;ROW0=0; //僅掃描輸出ROW0=0
   if(COL0==0) dataout(0);//若檢查COL0=0，按鍵資料輸出=0
   if(COL1==0) dataout(1);//若檢查COL1=0，按鍵資料輸出=1
   if(COL2==0) dataout(2);//若檢查COL2=0，按鍵資料輸出=2
   if(COL3==0) dataout(3);//若檢查COL3=0，按鍵資料輸出=3
       
   ROW0=ROW1=ROW2=ROW3=ROW4=1;ROW1=0; //僅掃描輸出ROW1=0
   if(COL0==0) dataout(4);//若檢查COL0=0，按鍵資料輸出=4
   if(COL1==0) dataout(5);//若檢查COL1=0，按鍵資料輸出=5
   if(COL2==0) dataout(6);//若檢查COL2=0，按鍵資料輸出=6
   if(COL3==0) dataout(7);//若檢查COL3=0，按鍵資料輸出=7
       
   ROW0=ROW1=ROW2=ROW3=ROW4=1;ROW2=0;   //僅掃描輸出ROW2=0
   if(COL0==0) dataout(8);  //若檢查COL0=0，按鍵資料輸出=8
   if(COL1==0) dataout(9);  //若檢查COL1=0，按鍵資料輸出=9
   if(COL2==0) dataout(0xA);//若檢查COL2=0，按鍵資料輸出=A
   if(COL3==0) dataout(0xB);//若檢查COL3=0，按鍵資料輸出=B
      
   ROW0=ROW1=ROW2=ROW3=ROW4=1;ROW3=0;  //僅掃描輸出ROW3=0
   if(COL0==0) dataout(0xC);//若檢查COL0=0，按鍵資料輸出=C
   if(COL1==0) dataout(0xD);//若檢查COL1=0，按鍵資料輸出=D
   if(COL2==0) dataout(0xE);//若檢查COL2=0，按鍵資料輸出=E
   if(COL3==0) dataout(0xF);//若檢查COL3=0，按鍵資料輸出=F

   ROW0=ROW1=ROW2=ROW3=ROW4=1;ROW4=0;  //僅掃描輸出ROW4=0
   if(COL0==0) dataout(0x10);//若檢查COL0=0，按鍵資料輸出=G
   if(COL1==0) dataout(0x11);//若檢查COL1=0，按鍵資料輸出=H
   if(COL2==0) dataout(0x12);//若檢查COL2=0，按鍵資料輸出=I
   if(COL3==0) dataout(0x13);//若檢查COL3=0，按鍵資料輸出=J
  }
}
/***********************************************************
*函數名稱: dataout
*功能描述: 按鍵輸出資料送到LED顯示數字，檢查是否放開按鍵
*輸入參數：keyout
************************************************************/
void dataout(char keyout)
{
  LED=keyout;	  //按鍵資料由LED輸出
  Delay_ms(1);    //延時
  while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
  Delay_ms(1);    //延時
}