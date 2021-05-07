#include "AT89X52.H"


sfr LED = 0x80;


void main(){
	char i=0, sum=0;
	
	while(++i){
		if(i%2)continue;
		if(i==6)break;
		sum+=i;
	}
	LED = sum;
	for(;;);
}