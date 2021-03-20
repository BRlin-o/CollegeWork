/********** 6_4.c ******************************
*笆砞﹚Timer1mode1の场璸计パ场T1(P35)
*      竲10块猧P0患
************************************************/
#include "..\AT89X52.H"   //既竟の舱篈﹚竡
void count(void); //﹚ㄧ计
main()
{
  TMOD=0x50;  /*0101 0000,砞﹚Timer1mode1场璸计
                bit7:GATE=0,ぃㄏノINT1竲币笆璸
			    bit6:C/T=1,场璸计
			    bit5-4:MODE=01mode1 */		
  while (1)     //ぃ耞碻吏磅︽
   {
      P0++;      //P0患块
      count();   //秈场璸计﹚ㄧ计
   }
}
/**********************************/
void count(void)  //场璸计﹚ㄧ计
{
  TL1=65536-10; //盢8じ璸计TL1砞﹚块10猧
  TH1=(65536-10)>>8; //盢蔼8じ璸计TH1
  TR1=1;             //币笆Timer1
  while(TF1==0);     //单璸计犯璝TF1=0и碻吏
  TR1=0;             //氨ゎTimer1
  TF1=0;      //璝璸计犯TF1=1睲埃TF1=0 
}