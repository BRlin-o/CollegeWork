/*********** 3_7.c *************************
*笆盢璸计糶皚跑计ず
*********************************************/ 
char  TABLE[8]=0;//睲埃TABLEじ皚丁ず甧
main()
{
  char i=1;    //8-bit璸计跑计
 loop:
  TABLE[0]=i; //璸计糶TABLE[0]
  TABLE[1]=i; //璸计糶TABLE[1]
  TABLE[2]=i; //璸计糶TABLE[2]
  TABLE[3]=i; //璸计糶TABLE[3]
  TABLE[4]=i; //璸计糶TABLE[4]
  TABLE[5]=i; //璸计糶TABLE[5]
  TABLE[6]=i; //璸计糶TABLE[6]
  TABLE[7]=i; //璸计糶TABLE[7] 
  i=i+1;     //璸计1
 goto loop;
}



