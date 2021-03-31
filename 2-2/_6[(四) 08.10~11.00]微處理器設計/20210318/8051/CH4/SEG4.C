/*********** SEG4.C ***************************
*動作：由四位數七段顯示器顯示電子鐘的分及秒時間值                             
*接線：七段顯示器：P0=Data=七段顯示器低電位輸出=Pgfedcba
*      低電位掃描：P13-0=SSLED3~0=千、百、十、個位數
***********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80;//P0資料BUS輸出
sbit SSLED0=0x90; //P10七段顯示器個位數選擇輸出
sbit SSLED1=0x91; //P11七段顯示器十位數選擇輸出
sbit SSLED2=0x92; //P12七段顯示器百位數選擇輸出
sbit SSLED3=0x93; //P13七段顯示器千位數選擇輸出

code unsigned char Table[] //七段顯示器0~9數碼資料
={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

char hor=23,min=58,sec=52; //設定時、分、秒時間
void Display(char scan); //七段顯示器顯示時間值

main()
{   
  char scan=10;  //七段顯示器掃描次數，決時延時時間
  while(1)
   {
    Display(scan); //七段顯示器顯示時間
	sec++;               //秒加一
    if (sec < 60) continue; //若秒小於60到loop處   
    sec=0; min++;        //秒等於60則令秒=0，分加一
    if (min < 60) continue; //若分小於60到loop處   
    min=0; hor++;        //若分等於60則令分=0，時加一
    if (hor <24) continue; //若時小於24到loop處
    hor=0;min=0; sec=0; //若時等於24則令時、分、秒=0
   }
}
//***************************************************	 
void Display(char scan) //四位數七段顯示器顯示步數	 
{  
  while(scan--) //重覆掃描次數 
   {
     SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒
	 Data=~Table[sec%10];//讀取秒個位數數碼資料輸出
     SSLED0=0;      //選擇個位數顯示器
     Delay_ms(1);   //掃描延時  
       
	 SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒          
     Data=~Table[sec/10];//讀取秒十位數數碼資料輸出
     SSLED1=0;      //選擇十位數顯示器
     Delay_ms(1);   //掃描延時
       
	 SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒                     
     Data=~Table[min%10];//讀取分個數數碼資料輸出
     SSLED2=0;      //選擇百位數顯示器
     Delay_ms(1);   //掃描延時
       
	 SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒
     Data=~Table[min/10];//讀取分十位數數碼資料輸出
     SSLED3=0;      //選擇千位數顯示器
     Delay_ms(1);   //掃描延時
   }	   
}