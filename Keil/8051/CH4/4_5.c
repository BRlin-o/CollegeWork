/********** 4_5.C ****************************
*動作：每按一次KEY按鍵，控制LED遞加輸出或停止
***********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr    LED=0x80; //P0為LED輸出
sbit   KEY=P3^2; //按鍵開關由P32輸入
bit flag=1;    //設定bit變數 
 
main() 
{
  LED=0;   //LED輸出 
  while(1)       //重覆執行 
   {		     //若flag=0，直接跳到此處
     if(KEY==0)      //若有按鍵，flag反相
	  {
	   flag=!flag;    //flag反相
	   while(KEY==0); //若未放開鍵，空轉 
	  }
	 if(flag==0) continue;//若flag=0，直接跳到迴圈最前面
 	 LED++;		    //若flag=1,LED遞加輸出
	 Delay_ms(100); //延時             
   }
}