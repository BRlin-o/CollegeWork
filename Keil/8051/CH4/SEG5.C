/*********** SEG5.C ***************************
*動作：手動控制步進馬達運轉，同時在七段顯示器顯示步數                             
*     P20=控制正反轉，1=正轉，0=反轉。
*     P21=控制運轉/停止，1=運轉，0=停止
*     P22=控制加速，0=加速
*     P23=控制減速，0=減速
*接線：步進馬達輸出：P34=A,P35=B,P36=/A,P37=/B  
*      七段顯示器：P0=七段顯示器低電位輸出=Pgfedcba
*      低電位掃描：P13-0=SSLED3~0=千、百、十、個位數
***********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr  Data=0x80;//P0資料BUS輸出
sbit SSLED0=0x90; //P10七段顯示器個位數選擇輸出
sbit SSLED1=0x91; //P11七段顯示器十位數選擇輸出
sbit SSLED2=0x92; //P12七段顯示器百位數選擇輸出
sbit SSLED3=0x93; //P13七段顯示器千位數選擇輸出
code char run_Table[] = {0x01,0x02,0x04,0x08}; //步進馬達驅動數碼 
code unsigned char Table[] //七段顯示器0~9數碼資料
={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int step=0;  //步進馬達行進步數=0
void Display(char scan); //七段顯示器顯示步數
void main()
{
  char scan=10; //四位數七段顯示器掃描次數
  char  i=0;  //步進馬達驅動數碼計數=0
  P3=0x0f;    //步進馬達輸出=0  
  while(1) 
   {
    Display(scan);     //七段顯示器顯示步數
    while(P2_1==0) Display(scan); //若P21=0停止運轉，掃描顯示器
	if(P2_0==1)          //若P21=1，P20=1，馬達正轉
     {
      if(i>3) i=0;     //若資料計數>3，從0開始
      P3=run_Table[i]<<4; //讀取驅動數碼由P3輸出 
      i++; step++;     //資料計數+1及步數+1
	  if(step > 9999) step=0;
     }
    else               //若P21=1，P20=0，馬達反轉
    {
      if(i<0) i=3;     //若資料計數<0，從3開始   
      P3=run_Table[i]<<4; //讀取驅動數碼由P3輸出  
      i--; step--;     //資料計數-1及步數-1 
	  if(step < 0) step=9999;
    }

	if(P2_2==0) scan--;//P22=0,加速
	if(P2_3==0) scan++;//P23=0,減速
	if(scan > 99) scan=99;
	if(scan <  1) scan=1;
  }
}
//***************************************************	 
void Display(char scan) //四位數七段顯示器顯示步數	 
{  
  unsigned char i; //七段顯示器數碼資料計數
  while(scan--) //重覆掃描次數 
   {
     SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒
     i=step % 10;   //取出個位數
     Data=~Table[i]; //讀取個位數碼資料輸出
     SSLED0=0;        //選擇個位數顯示器
     Delay_ms(1);    //掃描延時  
       
	 SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒           
     i=(step % 100)/10; //取出十位數 
     Data=~Table[i];//讀取十位數碼資料輸出
     SSLED1=0;       //選擇十位數顯示器
     Delay_ms(1);   //掃描延時
                            
     SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒
	 i=(step % 1000)/100; //取出百位數
     Data=~Table[i]; //讀取百位數碼資料輸出
     SSLED2=0;       //選擇百位數顯示器
     Delay_ms(1);    //掃描延時
       
	 SSLED0=SSLED1=SSLED2=SSLED3=1; //遮沒
     i=step/1000;  //取出千位數
     Data=~Table[i]; //讀取千位數碼資料輸出
     SSLED3=0;        //選擇千位數顯示器
     Delay_ms(1);    //掃描延時
   } 
}
