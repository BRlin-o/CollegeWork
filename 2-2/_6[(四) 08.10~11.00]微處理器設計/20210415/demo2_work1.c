sfr P0 =0x80;

main() {
	unsigned char a=0x2f; //0010 1111
	static unsigned char i;
	
	loop:
		i = a | 0x40 ;// (0010 1111) | (0100 0000) = (0110 1111)
		i = i & 0xfe; // (0110 1111) & (1111 1110) = (0110 1110)
		P0=i;
	goto loop;
}