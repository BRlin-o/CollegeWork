/**************** ADC2.C ****ADC0804實習板*************
*動作：輸入類比電壓，中斷方式讀取數位資料，在LED顯示數位資料
*接線：INTR=P32，RD=P10，WR=P11，CS接地                 
****************************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr   Data=0xA0;  //P2資料BUS輸出
sfr   LED=0x80;   //P0為LED輸出
sbit  AD_RD=P1^0 ; //P10為讀取控制，RD=0讀取數位資料
sbit  AD_WR=P1^1 ; //P11為寫入轉換控制，WR=0->1開始轉換
main()
{
	EA=1; EX0=1;    //致能外部INT0中斷
	IT0=1;          //設定INT0腳負緣觸發中斷
	AD_WR=0; AD_WR=1;//ADC開始轉換
	while(1);		 //等待轉換完畢
}
void EX0_SUB(void) interrupt 0
{
	AD_RD=0;	 //轉換完畢，讀取數位資料
	LED=Data;    //數位資料由LED輸出
	AD_RD=1;	 //ADC停止讀取
	AD_WR=0; AD_WR=1;//ADC重新開始轉換
}