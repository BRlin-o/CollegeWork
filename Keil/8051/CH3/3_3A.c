//******** 3_3A.c *************************
//*笆繰篈跑计
//****************************************
void test1(void)	//ㄧ计Α1
{
   static char i=8; //繰篈跑计度材Ω穦磅︽     
   i=i+1;  //笆篈跑计1 
}

void test2(void)	//ㄧ计Α2
{
   static char j=5; //繰篈跑计度材Ω穦磅︽     
   j=j+1;  //笆篈跑计1 
}

main()	//祘Α
{
  loop:     
   test1();//秈ㄧ计Α1
   test2();//秈ㄧ计Α2
 goto loop;	   
}