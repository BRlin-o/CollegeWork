/*************** KEY3.C************************
*動作：ROW0~4掃描輸出,COL0~3按鍵輸入
*     ，有按鍵產生INT0中斷，LED=按鍵資料輸出
*接腳：列ROW0=P10,ROW1=P11,ROW2=P12,ROW3=P13,ROW4=P14  
*      行COL0=P20,COL1=P21,COL2=P22,COL3=P23 
************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
char count=0;   //按鍵計數=0
sfr  LED=0x80;  //LED為LED輸出
sfr  ROW=0x90;  //P1為按鍵掃描輸出接腳
sbit COL0=P2^0;	//按鍵輸入接腳
sbit COL1=P2^1;
sbit COL2=P2^2;
sbit COL3=P2^3;
void main()
{
  unsigned char scan=0xfe;  //按鍵掃描令ROW0=0，其餘為1
  EA=1;EX0=1; //致能外部INT0斷 
  IT0=1;      //設INT0腳負緣觸發
  LED=0;       //設定按鍵資料=00
  ROW=0xfe;
  while(1)    //重覆執行
  {
   if(count>19){scan=0xfe;count=0;}//若計數>19,從頭掃描
   ROW=scan;		  //掃描輸出
   Delay_ms(1);   
   count=count+4;	//計數+4
   scan=RL8(scan);//8-bit左旋轉，換掃下一列,令ROW0~ROW4輪流為0
  }
}
/*******************************************/
void EX0_int(void) interrupt 0//INT0中斷函數0有按鍵中斷
 {
   if(COL0==0) LED=count;//檢查COL0列，若有按鍵計數輸出
   count++;              //若不是計數遞加  
   if(COL1==0) LED=count;//檢查COL1列，若有按鍵計數輸出
   count++;              //若不是計數遞加
   if(COL2==0) LED=count;//檢查COL2列，若有按鍵計數輸出
   count++;              //若不是計數遞加
   if(COL3==0) LED=count;//檢查COL3列，若有按鍵計數輸出
   Delay_ms(1);          //延時
   while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
}