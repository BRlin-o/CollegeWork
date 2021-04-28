/************* 3_58A.c ************************
*笆ㄢ计睹计パP0块00~99
*********************************************/
#include "..\AT89X52.H"
#include <stdlib.h>  //盢夹非I/Oㄧ计畐珹秈ㄓ
#include <stdio.h>   //盢夹非I/Oㄧ计珹秈ㄓ
main()
{
   unsigned char i=0;
  loop:
    i=rand();  //睹计
    i=i % 100; //0~99睹计
	P0=(i/10 <<4) + i%10;//パP0块秈00~99
  goto loop;
}