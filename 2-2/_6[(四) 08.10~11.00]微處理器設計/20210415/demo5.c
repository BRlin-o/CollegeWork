#include "AT89X52.H"

main() {
	unsigned char *point;
	point = 0x10;
	loop:
		*point++ = 0xFF;
	goto loop;
}