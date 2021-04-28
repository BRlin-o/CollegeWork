/********** 4_2.c *****************************
*動作：喇叭(SPEAK)輸出嗶嗶聲
***********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sbit   SPEAK=P2^6; //P26喇叭輸出
void beep(unsigned char i); 
main() 
{
  while(1)
  {
    beep(1);        //嗶一聲
    Delay_ms(1000); //間隔時間
    beep(2);        //嗶二聲
    Delay_ms(1000); //間隔時間
    beep(3);        //嗶三聲
    Delay_ms(1000); //間隔時間
  }
}
/********************************************/
void beep(unsigned char i)
{
  unsigned int  j;//SPEAK反相次數
  while(i--)   //嗶聲次數
   {
     for(j=0;j<400;j++) //令輸出反相400次
      {
        SPEAK=!SPEAK; //SPEAK反相,令喇叭發出聲音
        Delay_ms(1);  //嗶聲音頻
      }
     Delay_ms(200);  //嗶聲的間隔時間
  }
}