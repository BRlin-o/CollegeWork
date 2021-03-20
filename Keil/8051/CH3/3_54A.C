/************* 3_54A.c ***********************
*動作：LED遞加輸出，含延時函數
********************************************/
#include "..\AT89X52.H"  //暫存器及組態設定
sfr    LED=0x80; //P0為LED輸出
void delay(int count);  //宣告自訂函數

main()
{
     unsigned char i=0;  //計數值
   int dly=10000;      //空轉次數  
 loop:
    LED=i;  
    delay(dly); //呼叫自訂延時函數，將整數變數送入函數內
    i++;
    goto loop;
}
//***************************************************
void  delay(int count) //有傳入引數count，不回傳資料
 {
    while (count>0)   //空轉count(dly)次
     count--;
 }