/*********** STEP3.C *********************************
*動作：將各種動作存在陣列資料內，以自動方式控制步進馬達運轉 
*      第一個為功能資料：0=從頭開始，1=正轉CW,2=反轉CCW，3=停止
*      第二個為步數資料：指定步進馬達行進步數
*      第三個為延時資料：指定步進馬達每步的時間，或停止的時間
*接線：步進馬達輸出：P34=A,P35=B,P36=/A,P37=/B 
***********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
sfr   LED=0x80;  //LED由P0輸出
sfr   STEP=0xB0; //步進馬達由P3輸出
unsigned char run_Table[]={0x1,0x2,0x4,0x8};//驅動數碼

unsigned char code func_Table[] //步進馬達動作 
    = {1,30,1, //正轉,step=30,delay=0.1sec 
       3,10,   //停止,delay=10sec
       2,20,1, //反轉,step=20,delay=0.1sec 
       3,20,   //停止,delay=20sec 
       0};      //從頭開始  

void main()
{
  char  i=0;  //動作計數
  char  j=0;  //驅動數碼資料計數
  char  func; //功能  
  unsigned char  step; //步數

  STEP=0x0F;   //步進馬達初值：P34~P37=0000
  while(1) 
   {
    func=func_Table[i]; //讀取功能資料 
    switch(func)        //執行功能
     {
       case 0:        //若功能=0，從頭開始讀取 
         i=0;         //動作計數=0，從頭開始讀取 
        break;        //退出 
       
       case 1:               //若功能=1,正轉 
         i++;                //動作計數+1
         step=func_Table[i]; //讀取步數資料
         i++;                //動作計數+1
         while(step--)		 //步數-1,若大於0則繼續運轉
          {
           j++;              //驅動數碼資料+1  
           if (j>3) j=0;     //正轉資料計數>3,j=0           
           LED=run_Table[j];     //讀取驅動數碼由LED輸出 
	       STEP=run_Table[j]<<4; //讀取驅動數碼由步進馬達輸出
           Delay_ms(func_Table[i]);//延時時間，實際電路須加長
          } 
        i++;                 //動作計數+1
        break;               //退出
       
       case 2:               //若功能=2,反轉
        i++;                 //動作計數+1
        step=func_Table[i];  //讀取步數資料
        i++;                 //動作計數+1
        while(step--)		 //步數-1,若大於0則繼續運轉
         {
          j--;               //驅動數碼資料-1
          if (j<0) j=3;      //反轉資料計數<0,j=3
          LED=run_Table[j];     //讀取驅動數碼由LED輸出 
	      STEP=run_Table[j]<<4; //讀取驅動數碼由步進馬達輸出
          Delay_ms(func_Table[i]);//延時時間，實際電路須加長
         }
        i++;             //動作計數+1
        break;           //退出
        
       case 3:           //若功能=3,停止
        i++;             //動作計數+1
        Delay_ms(func_Table[i]); //停止時間，實際電路須加長
        i++;             //動作計數+1
        break;           //退出
     }
   }
}