/********** PWM3.C ***************************
*動作：使用Timer0令P00腳輸出PWM波形
*      若INT0=0控制PWM脈波加寬，若INT1=0控制PWM脈波縮減
***********************************************/
#include "..\AT89X52.H"
unsigned char PWM_VAR=0x80;  //定義PWM脈波初值
sbit PWM=0x80;  //PWM=P00
main()
{
  TMOD=0x02;    //設定Timer0為mode2內部計時
  TH0=TL0=0;    //Timer0由0開始計時   
  TR0=1;	    //啟動Timer0開始計時

  EA=1;         //致能整體中斷
  EX0=1; EX1=1; //致能外部INT0中斷及INT1中斷
  IT0=1; IT1=1; //設定INT0腳及INT1腳負緣觸發中斷
  while(1)      //週而覆始
   {
     PWM=1;	    //PWM的開始準位=1
     while(TL0 < PWM_VAR); //若計時值 < PWM值，等待之
     PWM= 0;	    //當計時值 >= PWMP時輸出0
     while(TF0==0);	//等待計時溢位
     TF0=0;	//清除計時溢位旗標，重新週而覆始
   }
}
/*********************************************/
void EX0_int(void) interrupt 0  //INT1中斷函數0
{
  PWM_VAR++;  //脈波加寬
  if(PWM_VAR>250) PWM_VAR=250;  //脈波加寬限制
}
/**********************************************/
void EX1_int(void) interrupt 2   //INT1中斷函數2
{
  PWM_VAR--; //脈波縮減
  if(PWM_VAR<30) PWM_VAR=30;  //脈波縮減限制
}
