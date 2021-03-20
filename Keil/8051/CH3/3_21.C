/*******3_21.c*********************** 
*動作：強制轉換運算式型態範例
**********************************/
   char   a=12;      //宣告有符號8-bit變數，為1-byte
   int    b=-7;      //宣告有符號16-bit變數，為2-byte
   float  c=123.222; //宣告32-bit浮點數，為4-byte
main()
{
   static char i;  //宣告輸出8-bit變數
  loop: 
   i=sizeof(a+b);  //8-bit與16-bit運算，結果i=2byte
   i=sizeof(a/b);  //8-bit與16-bit運算，結果i=2byte
   i=sizeof(c-b);  //16-bit整數與32-bit浮點數運算，結果i=4byte
   goto loop;  
}
