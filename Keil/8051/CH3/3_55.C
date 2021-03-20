/************* 3_55.c *************************
*動作：LED遞加輸出，含延時函數
**********************************************/
#include "..\AT89X52.H"  //暫存器及組態設定
sfr    LED=0x80; //P0為LED輸出
int Delay(int count);  //宣告自訂函數

main()
{
   int i=0;
 loop:
   LED=i;
   i=Delay(i);   //將變數i送入函數內，有回傳變數i   
  goto loop;
}
//********************************************************
int Delay(int count) //有傳入引數到count，有回傳變數count到i
{
  count=count+5;
  return count;     //將變數count的內容回傳到主程式
}
