/*************** KEY2.C*************************
*動作：ROW0~4掃描輸出,COL0~3按鍵輸入,Data(P0)=七段顯示輸出
*接腳：列ROW0=P10,ROW1=P11,ROW2=P12,ROW3=P13,ROW4=P14 
*      行COL0=P20,COL1=P21,COL2=P22,COL3=P23 
***********************************************/
#include "..\AT89X52.H"   //暫存器及組態定義
void dataout(char keyout); //按鍵資料輸出
sfr  Data=0x80; //P0為資料輸出
sfr  ROW=0x90;  //P1為按鍵掃描輸出接腳
sbit COL0=P2^0;	//P2按鍵輸入接腳
sbit COL1=P2^1;
sbit COL2=P2^2;
sbit COL3=P2^3;

unsigned char code Table[] //七段顯示器0~9，A~J的資料
 ={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,
    0x77,0x7c,0x39,0x5e,0x79,0x71,0x3d,0x76,0x30,0x1e};

void dataout(char keyout); //按鍵資料輸出
void main()
{
 char count=0;   //按鍵計數=0
 unsigned char scan=0xfe;  //按鍵掃描令ROW0=0，其餘為1
 Data=~Table[0];  //七段顯示器，顯示0
 while(1)   //重覆執行
  {
    if(count>19){scan=0xfe;count=0;}//若計數>19，從頭開始
    ROW=scan;		  //掃描輸出
    if(COL0==0) dataout(count);//檢查COL0列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL1==0) dataout(count);//檢查COL1列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL2==0) dataout(count);//檢查COL2列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL3==0) dataout(count);//檢查COL3列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    scan=RL8(scan); //左旋轉，換掃下一列,令ROW0~4輪流為0
  }
}
/***********************************************************
*函數名稱: dataout
*功能描述: 按鍵輸出資料送到七段顯示器顯示數字，檢查是否放開按鍵
*輸入參數：keyout
************************************************************/
void dataout(char keyout) 
{
  Data=~Table[keyout];  //送到七段顯示器輸出
  Delay_ms(1);       	//處理按鍵跳動之延遲   
  while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
  Delay_ms(1);       	//處理按鍵跳動之延遲
} 