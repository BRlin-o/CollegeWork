#include "AT89X52.H"

char count _at_ 0x10;

main() {
	char *point, i;
	point = $count;
	loop:
		*point = i;
		P0 = count;
		i++;
	goto loop;
}