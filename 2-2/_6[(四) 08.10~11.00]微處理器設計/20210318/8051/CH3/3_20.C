/********3_20.c*************************** 
*動作：sizeof運算子範例
******************************************/
main()
{
   char   a;        //宣告8-bit整數變數，為1-byte
   int    b;        //宣告16-bit整數變數，為2-byte 
   float  c;        //宣告浮點變數，為4-byte

   char data *pd;	//指定使用內部RAM的指標變數，為1-byte
   char code *pe;	//指定使用ROM的指標變數，為2-byte
   char *pf; 		//不指定記憶體的指標變數，為3-byte
   static char  i;  //宣告輸出變數
  loop: 
   i=sizeof(a);  //結果i=1-byte
   i=sizeof(b);  //結果i=2-byte
   i=sizeof(c);  //結果i=4-byte

   i=sizeof(pd); //結果i=1-byte
   i=sizeof(pe); //結果i=2-byte
   i=sizeof(pf); //結果i=3-byte
   goto loop;  
}