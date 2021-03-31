/************* 3_49.c **************************
*動作：由SW輸入設定累加計數最大值，累加值由LED輸出
***********************************************/
#include "..\AT89X52.H"  //暫存器及組態設定
sfr    LED=0x80; //P0為LED輸出
sfr    SW=0x90;  //P1為SW輸入		
main()
{
  unsigned char n;     //宣告最小輸入計數值
  unsigned char i=1;   //宣告計數值
  unsigned char sum=0; //宣告累加值
  while(1)   //重覆執行
  {
     do
       n=SW;        //由SW輸入設定累加計數最大值
      while (n<=4); //若n<=4時重新輸入

     do             //若n>4往下執行
       { 
        sum=sum+i;  //累加
        i++;
       }
     while(i<=n);  //當i<=n時，執行累加的動作
     LED=sum;         //當i>n時，累加值由LED輸出
   }
}