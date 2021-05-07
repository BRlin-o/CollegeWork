#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include "AT89X52.H"

void main(void) {
	unsigned char TableA[] = {34,65,12,34,67,89,7,6,83,89}, TableB[] = {30,61,13,38,65,80,10,7,82,81};
	unsigned char n = 10, i=0;
	double RMSE = 0, sum_catch = 0;
	for(i=0;i<n;++i) {
		sum_catch += (TableA[i] - TableB[i])*(TableA[i] - TableB[i]);
	}
	RMSE = sqrt(sum_catch/n);
	
}