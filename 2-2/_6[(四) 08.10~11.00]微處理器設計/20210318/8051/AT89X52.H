/*-----------------------------------------------
AT89X52.H
-----------------------------------------------*/
//重新定義變數的型態名稱
typedef unsigned char   uint8;  // 無符號8-bit整數變數       
typedef signed   char  	int8;   // 有符號8-bit整數變數       
typedef unsigned int 	uint16; // 無符號16-bit整數變數      
typedef signed   int 	int16;  // 有符號16-bit整數變數      
typedef unsigned long  	uint32; // 無符號32-bit整數變數      
typedef signed   long  	int32;  // 有符號32-bit整數變數      
typedef float          	fp32;   // 單精度浮點數(32bit)

//重新定義Keil內部<intrins.h>函數
#include  <intrins.h>  //包括邏輯運算函數庫設定
#define RR8(x)  _cror_(x,1); //定義8-bit變數x右旋轉1-bit
#define RR16(x) _iror_(x,1); //定義16-bit變數x右旋轉1-bit
#define RR32(x) _lror_(x,1); //定義32-bit變數x右旋轉1-bit

#define RL8(x)  _crol_(x,1); //定義8-bit變數x左旋轉1-bit
#define RL16(x) _irol_(x,1); //定義16-bit變數x左旋轉1-bit
#define RL32(x) _lrol_(x,1); //定義32-bit變數x左旋轉1-bit

#define NOP _nop_;  //定義空指令，延時一個機械週期時間

/*******************************************
*函數名稱: Delay_ms
*功能描述: 延時以1mS為單位，石英晶體為11.0592MHz
*********************************************/
void Delay_ms(unsigned int dly) 
{  
  unsigned  char dly1; //內循環變數
  while(dly--)         // 外循環，遞減至0
    for(dly1=0;dly1<113;dly1++); //內循環，延時1ms
} 
//********宣告函數********************************** 
void UART_init(unsigned int BPS);  //UART啟始程式

void LCD_wait(void);	//LCD等待忙碌旗標BF
void LCD_init(void);   		//LCD的啟始程式 
void LCD_Data(char Data);  	//傳送資料到LCD
void LCD_Cmd(unsigned char Cmd); 	//傳送命令到LCD
void LCD_Disp(unsigned int count);

void GLCD_Data(char dat);  	//傳送資料到繪圖型LCD
void GLCD_Cmd(unsigned char Cmd);//傳送命令到繪圖型LCD
void waitLCD(void);//LCD等待忙碌旗標BF

 //宣告EEPROM 93C46及93C66函數
void Clock(void);           //送入串列EEPROM時脈信號
void SEND(bit flag);       //送入EEPROM串列1-bit位址或資料
void SEND8(unsigned char Addr);      //送入8-bit位址或資料
unsigned int  READ_16(unsigned char Addr); //讀取16-bit資料
unsigned char READ_8(unsigned char Addr);  //讀取8-bit資料
void WRITE_16(unsigned char Addr,unsigned int ch);//寫入16-bit資料
void WRITE_8(unsigned char Addr,unsigned char ch);//寫入8-bit資料
void EWEN(void);            //EEPROM寫入及清除致能
void EWDS(void);            //EEPROM寫入及清除禁能
void ERAL(void);           //EEPROM清除全部記憶體
					
//----------------------------------------------
sfr  P0   = 0x80;  //P0輸出入埠暫存器
sbit P0_0 = 0x80;
sbit P0_1 = 0x81;
sbit P0_2 = 0x82;
sbit P0_3 = 0x83;
sbit P0_4 = 0x84;
sbit P0_5 = 0x85;
sbit P0_6 = 0x86;
sbit P0_7 = 0x87;
//----------------------------------------------
sfr SP      = 0x81; //堆疊指標暫存器
sfr DPL     = 0x82; //資料指標低位元組暫存器
sfr DPH     = 0x83; //資料指標高位元組暫存器
//------------------------------------------------
sfr PCON    = 0x87;	 //功率控制暫存器
#define IDL    0x01  //1=進入idle省電模式
#define STOP   0x02  //1=進入stop省電模式
#define PD     0x02  //1=進入power down省電模式  
#define GF0    0x04  //通用存取位元
#define GF1    0x08  //通用存取位元
#define SMOD   0x80  //1=UART鮑率加倍
//------------------------------------------------
sfr TCON  = 0x88;	//Timer0-1控制暫存器
sbit IT0  = 0x88;  	//INT0中斷信號選擇,1=負緣觸發輸入,0=低準位輸入 
sbit IE0  = 0x89;	//INT0顯示旗標,1=INT0中斷成立
sbit IT1  = 0x8A;	//INT1中斷信號選擇,1=負緣觸發輸入,0=低準位輸入
sbit IE1  = 0x8B;	//INT1顯示旗標,1=INT1中斷成立
sbit TR0  = 0x8C;	//T0啟動位元,TR0=1令Timer0開始工作
sbit TF0  = 0x8D;	//T0溢位旗標,Timer0溢位時，令TF0=1
sbit TR1  = 0x8E;	//T1啟動位元,1=令Timer1開始工作
sbit TF1  = 0x8F;	//T1溢位旗標,Timer1溢位時，令TF1=1
//------------------------------------------------
sfr TMOD    = 0x89;	 //Timer0-1模式暫存器
#define T0_M0   0x01 //Timer0模式位元0
#define T0_M1   0x02 //Timer0模式位元1
#define T0_CT   0x04 //0=Timer0為內部計時，1=外部計數
#define T0_GATE 0x08 //1=Timer0由INT0腳(P32)啟動
#define T1_M0   0x10 //Timer1模式位元0
#define T1_M1   0x20 //Timer1模式位元1
#define T1_CT   0x40 //0=Timer1為內部計時，1=外部計數
#define T1_GATE 0x80 //1=Timer1由INT1腳(P33)啟動
//------------------------------------------------
sfr TL0 = 0x8A;	 //Timer0計時/計數低位元組暫存器
sfr TL1 = 0x8B;	 //Timer1計時/計數低位元組暫存器
sfr TH0 = 0x8C;	 //Timer0計時/計數高位元組暫存器
sfr TH1 = 0x8D;	 //Timer1計時/計數高位元組暫存器
//------------------------------------------------
sfr P1    = 0x90;  //P1輸出入埠暫存器
sbit P1_0 = 0x90;
sbit P1_1 = 0x91;
sbit P1_2 = 0x92;
sbit P1_3 = 0x93;
sbit P1_4 = 0x94;
sbit P1_5 = 0x95;
sbit P1_6 = 0x96;
sbit P1_7 = 0x97;

sbit T2   = 0x90;  //Timer2外部計數輸入腳(P10)
sbit T2EX = 0x91;  //Timer2外部重新載入/捕捉觸發輸入腳(P11)
//------------------------------------------------
sfr SCON  = 0x98; //UART串列埠控制暫存器
sbit RI   = 0x98; //UART接收旗標，接收完成時，RI=1
sbit TI   = 0x99; //UART發射旗標，發射完成時，TI=1
sbit RB8  = 0x9A; //UART模式2、3中，存放接收到的第8bit 
sbit TB8  = 0x9B; //UART模式2、3中，發射資料的第8bit
sbit REN  = 0x9C; //UART接收致能，REN=1允許接收串列資料
sbit SM2  = 0x9D; //UART工作模式設定
sbit SM1  = 0x9E;
sbit SM0  = 0x9F;
//------------------------------------------------
sfr SBUF    = 0x99; //UART串列緩衝暫存器
//------------------------------------------------
sfr P2    = 0xA0;  //P2輸出入埠暫存器
sbit P2_0 = 0xA0;
sbit P2_1 = 0xA1;
sbit P2_2 = 0xA2;
sbit P2_3 = 0xA3;
sbit P2_4 = 0xA4;
sbit P2_5 = 0xA5;
sbit P2_6 = 0xA6;
sbit P2_7 = 0xA7;
//------------------------------------------------
sfr IE    = 0xA8;  //中斷致能暫存器
sbit EX0  = 0xA8;  //1=致能INT0中斷
sbit ET0  = 0xA9;  //1=致能Timer0中斷
sbit EX1  = 0xAA;  //1=致能INT1中斷
sbit ET1  = 0xAB;  //1=致能Timer1中斷
sbit ES   = 0xAC;  //1=致能UART中斷
sbit ET2  = 0xAD;  //1=致能Timer2中斷
sbit EA   = 0xAF;  //0=禁能所有中斷
//------------------------------------------------
sfr P3    = 0xB0;  //P3輸出入埠暫存器
sbit P3_0 = 0xB0;
sbit P3_1 = 0xB1;
sbit P3_2 = 0xB2;
sbit P3_3 = 0xB3;
sbit P3_4 = 0xB4;
sbit P3_5 = 0xB5;
sbit P3_6 = 0xB6;
sbit P3_7 = 0xB7;

sbit RXD0 = 0xB0;   //UART串列接收輸入腳(P30)
sbit TXD0 = 0xB1;   //UART串列發射輸出腳(P31)
sbit INT0 = 0xB2;   //外部中斷INT0輸入腳(P32)
sbit INT1 = 0xB3;   //外部中斷INT1輸入腳(P33)
sbit T0   = 0xB4;   //Timer0外部計數輸入腳(P34)
sbit T1   = 0xB5;   //Timer1外部計數輸入腳(P35)
sbit WR   = 0xB6;   //外部資料記憶體寫入控制腳(P36)
sbit RD   = 0xB7;   //外部資料記憶體讀取控制腳(P37)
//------------------------------------------------
sfr  IP   = 0xB8; //中斷優先暫存器
sbit PX0  = 0xB8; //1=INT0中斷優先
sbit PT0  = 0xB9; //1=Timer0中斷優先
sbit PX1  = 0xBA; //1=INT1中斷優先
sbit PT1  = 0xBB; //1=Timer1中斷優先
sbit PS   = 0xBC; //1=UART中斷優先
sbit PT2  = 0xBD; //1=Timer2中斷優先
//------------------------------------------------
sfr T2CON = 0xC8;   //Timer2控制暫存器
sbit CP_RL2= 0xC8;  //0=重新載入(Reload),1=捕捉(Capture )
sbit C_T2 = 0xC9;   //0=計時(Timer),1=計數(Counter)
sbit TR2  = 0xCA;   //1=開始計時
sbit EXEN2= 0xCB;  	//1=致能T2EX腳輸入負緣觸發
sbit TCLK = 0xCC;   //0=串列埠發射時脈使用Timer1，1=使用Timer2
sbit RCLK = 0xCD;   //0=串列埠接收時脈使用Timer1，1=使用Timer2 
sbit EXF2 = 0xCE;   //T2EX腳輸入旗標
sbit TF2  = 0xCF;   //Timer2溢位旗標
//------------------------------------------------
sfr16  RCAP2  = 0xCA; //Timer2重新載入/捕捉暫存器
sfr RCAP2L  = 0xCA;  //Timer2重新載入/捕捉暫存器低位元組
sfr RCAP2H  = 0xCB;  //Timer2重新載入/捕捉暫存器高位元組

sfr16 T2R   = 0xCC;  //Timer2計時/計數暫存器
sfr TL2     = 0xCC;  //Timer2計時/計數暫存器低位元組
sfr TH2     = 0xCD;  //Timer2計時/計數暫存器高位元組
//------------------------------------------------
sfr PSW   = 0xD0;  	//程式狀態字元暫存器
sbit P    = 0xD0;	//同位元旗標，0=偶同位元，1=奇同位元
sbit OV   = 0xD2;	//溢位旗標，1=有溢位
sbit RS0  = 0xD3;	//暫存器庫選擇
sbit RS1  = 0xD4;	//暫存器庫選擇
sbit F0   = 0xD5;	//一般的讀寫位元
sbit AC   = 0xD6;      //半進位旗標，1=有半進位或有半借位
sbit CY   = 0xD7;  	//進位旗標，1=有進位或有借位
//----------------------------------------------
sfr ACC   = 0xE0;	//累積器
sfr B     = 0xF0;	//累積器
/*------------------------------------------------
中斷向量位址 = (中斷向量編號 * 8) + 3
------------------------------------------------*/
#define IE0_VECTOR	0  //INT0外部中斷，中斷向量位址0x03
#define TF0_VECTOR	1  //Timer0溢位中斷，中斷向量位址0x0B
#define IE1_VECTOR	2  //INT1外部中斷，中斷向量位址0x13
#define TF1_VECTOR	3  //Timer1溢位中斷，中斷向量位址0x1B
#define SIO_VECTOR	4  //UART傳輸中斷，中斷向量位址0x23
#define TF2_VECTOR	5  //Timer2溢位中斷，中斷向量位址0x2B
#define EX2_VECTOR	5  //Timer2外部中斷，中斷向量位址0x2B
//*******AT89C51/2特殊暫功能存器****************************
sfr WDTRST = 0xA6;   //看門狗計時重置暫存器
sfr AUXR = 0x8E;     //輔助暫存器
#define WDIDLE 0x10 //1=進入省電閒置模式時WDT停止上數
#define DISRTO 0x08 //1=WDT溢位時重置腳不輸出
