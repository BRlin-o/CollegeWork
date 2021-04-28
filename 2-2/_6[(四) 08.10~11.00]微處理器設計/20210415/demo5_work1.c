#include "AT89X52.H"
#include "TABLE8.H"

main() {
	unsigned char *point;
	
	point = TABLE;
	
	loop:
		P0=*point++;
	goto loop;
}