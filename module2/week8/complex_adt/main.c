#include <stdio.h>
#include "complex.h"

int main()
{
	complex a = cplx_init(2, 3);
	complex b = cplx_init(3, 2);
	complex c = cplx_sum(a, b);
	complex d = cplx_mul(a, b);
	
	cplx_print(a);
	printf(" + ");
	cplx_print(b);
	printf(" = ");
	cplx_print(c);
	puts("");
	
	cplx_print(a);
	printf(" + ");
	cplx_print(b);
	printf(" = ");
	cplx_print(c);
	puts("");
	
	printf("module of ");
	cplx_print(a);
	printf(" = %.2f\n", cplx_mod(a));
	
	printf("module of ");
	cplx_print(a);
	printf(" = %.2f\n", cplx_mod(b));
	
	printf("module of ");
	cplx_print(a);
	printf(" = %.2f\n", cplx_mod(c));
	
	printf("module of ");
	cplx_print(a);
	printf(" = %.2f\n", cplx_mod(d));
	
	cplx_free(a);
	cplx_free(b);
	cplx_free(c);
	cplx_free(d);

	return 0;
}
