/************** ADC1.C *******ADC0804實習板**********
*動作：輸入類比電壓，讀取數位資料，在LED顯示數位資料
*接線：INTR=P32，RD=P10，WR=P11，CS接地                 
****************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr   Data=0xA0;  //P2資料BUS輸出
sfr   LED=0x80;   //P0為LED輸出
sbit  INTR=0xB2;  //P32為轉換完畢旗標，1=未完，0=完畢 
sbit  AD_RD=P1^0; //P10為讀取控制，RD=0讀取數位資料
sbit  AD_WR=P1^1; //P11為寫入轉換控制，WR=0->1開始轉換
main()
{
	while(1)
	{
	    AD_WR=0; AD_WR=1; //ADC開始轉換
	    while(INTR);  //等待INTR=0轉換完畢
	    AD_RD=0;      //轉換完畢，讀取數位資料
	    LED=Data;     //數位資料由LED輸出
	    AD_RD=1;	  //ADC停止讀取
	}
}
