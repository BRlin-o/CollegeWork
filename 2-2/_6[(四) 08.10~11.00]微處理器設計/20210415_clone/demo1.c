#include "AT89X52.H" 	
void main(){
  char  a=-3,b=0,c=5; 
  unsigned char  d=0x0f;
  static char  i; 
 loop:  
   i=-a;       
   i=-c;       
   P1_0=!P1_0; 
   i=!b;       
   i=!c;       
   P1=~d;      
 goto loop;
}