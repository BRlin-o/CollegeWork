//Page 3-14
//PPT CH03 - 43

#include "AT89X52.H"
#include "TABLE8.H"

// sfr P0 =0x80;
// sfr P1 =0x90;


main() {
	unsigned char i;
	
	loop:
		P0 = TABLE[i];
		P1 = TABLE[i]>>4;
		Delay_ms(100);
		i++;
	goto loop;
}
