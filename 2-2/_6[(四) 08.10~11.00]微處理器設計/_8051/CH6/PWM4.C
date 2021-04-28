 /********** PWM4.c ****************************
*動作：應用Timer0的計時，來控制馬達速度
*      每隔一段時間正反轉一次
*      P00=PWM波形輸出，P01=正/反轉控制(DIR)
***********************************************/
#include "..\AT89X52.H"
unsigned char PWM_VAR;  //定義變數
sbit PWM=0x80;            //PWM=P00
sbit DIR=0x81;            //DIR=P01
main()
{
  unsigned char count; //PWM波形重覆次數
  TMOD=0x02;   //設定Timer0為mode2內部計時
  TH0=TL0=0;
  TR0=1;        //啟動Timer0開始計時
  DIR=1;     //馬達正轉
  while(1)
  {	    
    for(PWM_VAR=10;PWM_VAR<250;PWM_VAR++)///PWM脈波寬度遞增
     {
   	  count=10;	 //PWM波形重覆次數 
	  while(count--)
	  {
	    PWM=1; //PWM輸出1開始
		while(TF0==0)
		  if(TL0 > PWM_VAR) PWM=0;//若計時值 >PWM1值，PWM1=0
 	    TF0=0;
	  }
    }
    for(PWM_VAR=256;PWM_VAR<10;PWM_VAR--)///PWM脈波寬度遞減
     {
   	  count=10;	 //PWM波形重覆次數 
	  while(count--)
	  {
	    PWM=1; //PWM輸出1開始
		while(TF0==0)
		  if(TL0 > PWM_VAR) PWM=0;//若計時值 >PWM1值，PWM1=0
 	    TF0=0;
	  }
    }
    DIR=!DIR; //切換馬達正/反轉  
  }
}
