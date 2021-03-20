/********* 3_24.c*******指標及if-goto應用範例*****************
*動作：以指標方式讀取256筆陣列資料，由LED輸出
**********************************************************/
#include "..\AT89X52.H"  //暫存器及組態設定
sfr    LED=0x80; //P0為LED輸出
#include "TABLE8.H" 
 main()
{
   unsigned char  *point;  //宣告指標變數  
  start:        //重新開始
   point=TABLE; //將陣列資料開始位址(0x0800)存入指標變數
  loop:
   LED=*point++;       //由LED輸出一筆資料，再位址遞加
   if(point > (TABLE+255)) goto start; //若指標超過255筆，重新開始
   Delay_ms(100);	        //延時
   goto loop;
}