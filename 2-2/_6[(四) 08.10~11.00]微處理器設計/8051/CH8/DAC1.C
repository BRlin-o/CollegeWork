/**************** DAC1.C *************************
*動作：送出數位資料到DAC0800輸出三角波                   
*************************************************/
#include "..\AT89X52.H"  //暫存器及組態定義
sfr  Data=0x80;//P0資料BUS輸出
main()  
{
  unsigned char i=0; //輸出數位資料
  unsigned char dly; //延時
  while(1)    // 重覆執行 
  {   
	while(++i) //數位資料遞加到0
	{
	  Data=i;	//資料輸出
	  for(dly=0;dly<10;dly++); //延時
	}
	while(--i)  //數位資料遞減到0	
	{
	  Data=i;	//資料輸出
	  for(dly=0;dly<10;dly++); //延時
	}
  }
}