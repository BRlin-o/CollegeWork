main()
{
  unsigned char  a=0x0f;   //a=0000 1111
  unsigned char  b=0x33;   //b=0011 0011
  static unsigned char  i; //輸出變數
  loop:
    i=~a;        //a=0000 1111取補數,      i=1111 000=0xf0;
    i=a << 3;   //a=0000 1111左移3-bit,  i=0111 1000=0x78
    i=b >> 1;   //b=0011 0011右移1-bit,  i=0001 1001=0x19
    i=a & 0xfe; //a=0000 1111令bit0=0，  i=0000 1110=0x0e 
    i=b ^ 0x01; //b=0011 0011令bit0=反相,i=0011 0010=0x32 
    i=a | 0x80; //a=0000 1111令bit7=1，  i=1000 1111=0x8f
  goto loop;
}