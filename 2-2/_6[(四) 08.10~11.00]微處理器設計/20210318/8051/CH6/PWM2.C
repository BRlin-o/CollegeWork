/********** PWM2.C ***********************
*動作：使用Timer0輸出4個的PWM波形 
*****************************************/
#include "..\AT89X52.H"
unsigned char PWM1_VAR=0x30;  //定義PWM1腳輸出脈波
unsigned char PWM2_VAR=0x30;  //定義PWM2腳輸出脈波
unsigned char PWM3_VAR=0x30;  //定義PWM3腳輸出脈波
unsigned char PWM4_VAR=0x30;  //定義PWM4腳輸出脈波

sbit PWM1=0x80;  //PWM1=P00
sbit PWM2=0x81;  //PWM2=P01
sbit PWM3=0x82;  //PWM3=P02
sbit PWM4=0x83;  //PWM4=P03

main()
{
  TMOD=0x02;    //設定Timer0為mode2內部計時
  TH0=TL0=0;    //Timer0由0開始計時   
  TR0=1;	    //啟動Timer0開始計時
  while(1)      //週而覆始
   {
     PWM1=PWM2=PWM3=PWM4=1;	 //PWM的開始準位=1
     while(TF0==0)	//若計時未溢位PWM輸出
	 {
	  if(TL0 > PWM1_VAR) PWM1=0;//若計時值 >PWM1值，PWM1=0
	  if(TL0 > PWM2_VAR) PWM2=0;//若計時值 >PWM2值，PWM2=0
	  if(TL0 > PWM3_VAR) PWM3=0;//若計時值 >PWM3值，PWM3=0
	  if(TL0 > PWM4_VAR) PWM4=0;//若計時值 >PWM4值，PWM4=0
     }
	 TF0=0;	//若計時溢位，清除計時溢位旗標,重頭開始
   }
}