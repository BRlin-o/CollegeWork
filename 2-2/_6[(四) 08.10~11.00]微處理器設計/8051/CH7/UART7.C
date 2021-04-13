/********** UART7.c *********串列埠函數發射****************
*動作：用printf()函數將資料以UART串列格式送到電腦
***********************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
#include <stdio.h>   //加入基本輸出入函數

main()
{  
  int i=42,j=3;       //定義整數變數
  char  ch='a';       //定義字元變數
   
  UART_init(9600);     //設定串列環境及鮑率
  TI=1;
  printf("i=%d \n",i);      //顯示i=42
  printf("j= %d \n",j); 	//顯示j=3
  printf("i=%d,j=%d,i+j=%d \n",i,j,i+j); //顯示i=42,j=3,i+j=45
   
  printf("%d convert %%d-->/%d/\n",i,i);     //42 convert %d-->/42/
  printf("%d convert %%6d-->/%6d/\n",i,i);   //42 convert %6d-->/    42/
  printf("%d convert %%06d-->/%06d/\n",i,i); //42 convert %06d-->/000042/
  printf("%d convert %%-6d-->/%-6d/\n",i,i); //42 convert %-6d -->/42    /
  
  printf("i(8)= %o\n",i);	    //顯示i(8)=54
  printf("i(16)= %x\n",i);      //顯示i(16)=2a
     
  printf("%c convert %%c-->/%c/\n",ch,ch);    //a convert %c-->/a/
  printf("%c convert %%6c -->/%6c/\n",ch,ch); //a convert %c-->/     a/
  printf("%c convert %%-6c-->/%-6c/\n",ch,ch);//a convert %c-->/a     / 
  
while(1);   //自我空轉
} 
/***********************************************************
*函數名稱: UART_init
*功能描述: UART啟始程式
*輸入參數：bps
************************************************************/
void UART_init(unsigned int bps)  //UART啟始程式
{
   SCON = 0x50;     //設定UART串列傳輸為MODE1及致能接收
   TMOD = 0x20;     //設定TIMER1為MODE2
   TH1 = 256-(28800/bps);  //設計時器決定串列傳輸鮑率
   TR1 = 1;          //開始計時
}