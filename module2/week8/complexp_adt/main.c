#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

#define PI 3.14159265358979323846

int main(int argc, char *argv[])
{
	int radix = atoi(argv[1]);

	for(int k = 0; k < radix; k++)
	{
		complex a = cplx_init(1, (2 * k * PI) / radix);
		complex e = cplx_pow(a, radix);
		
		printf("radix n°%d | angle: %f | (", k+1, cplx_angle(a));
		cplx_show(a);
		printf(")^%d = %f", radix, cplx_re(e));
		puts("");
		
		cplx_free(a);
	}

	return 0;
}
