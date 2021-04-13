extern unsigned char k;
sfr P0=0x80;
sfr P1=0x90;

void test(void) {
	static char i = 10;
	// i = i + 1;
	// P0 = i;
	P0 = (++i);
	k=k+1;
}

void test1(void) {
	char j=10;
	j = j + 1;
	P1 = j;
}