//*********** 3_4A.c ***** ***************************
//*笆办跑计の跋办跑计
//****************************************************
char count;      //办跑计
void Delay(void) 
{
   char dly;         //跋办跑计
   count=count +1;  //办跑计┮Τㄧ计А磅︽
   dly=dly+1;       //跋办跑计度セㄧ计ず磅︽
   // b=b-1;        //獶セ跋办跑计ぃ猭
}

main()
{
    char b;        //跋办跑计
  loop:
    count=count+1; //办跑计┮Τㄧ计А磅︽
    b=b+1;         //跋办跑计度セㄧ计ず磅︽
    //dly=dly-1;   //獶セ跋办跑计ぃ猭
    Delay();       //ㄧ计Α
    goto loop;
}
