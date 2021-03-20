/************* 3_27.c *******************
*動作：P2及P3輸入相比較. 
*若P2<P3，較大送到P0，較小送到P1 
*若P2=P3，則P1=00，P0=00
*若P2>P3，則P1=ff，P0=ff
****************************************/
#include "..\AT89X52.H" //暫存器及組態設定	
main()
{
   unsigned char i,j,k; //定義8-bit變數
 loop:
   i=P2; j=P3; //P2及P3輸入   
   if(i<=j)  
     {
       if(i<j) {k=i; i=j; j=k;}//若i<j,i和j交換
         else  {i=0; j=0; } //若i=j,i=0和j=0
     }
     else{i=0xff; j=0xff;}//若i>j,i=ff和j=ff
   P0=i; P1=j; //P0,P1 輸出 
 goto loop;
}