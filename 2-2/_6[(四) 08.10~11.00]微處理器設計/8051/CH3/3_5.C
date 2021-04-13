/*********** 3_5.c ******************************************
*動作：由RAM讀取陣列資料由LED輸出
*************************************************************/
#include "..\AT89X52.H"  //暫存器及組態設定
char TABLE[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 
sfr    LED=0x80; //P0為LED輸出
main()
{
  loop:
    LED=TABLE[0]; //LED=0x01
    LED=TABLE[1]; //LED=0x02
    LED=TABLE[2]; //LED=0x04
    LED=TABLE[3]; //LED=0x08
    LED=TABLE[4]; //LED=0x10
    LED=TABLE[5]; //LED=0x20
    LED=TABLE[6]; //LED=0x40
    LED=TABLE[7]; //LED=0x80
   goto loop;  
}