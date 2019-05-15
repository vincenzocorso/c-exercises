#include <stdio.h>
#include "polynomial.h"

int main()
{
	polynomial a = plm_init(3, (double[]) {7, 9, 0, 3});
	polynomial b = plm_init(2, (double[]) {6, 0, 3});
	polynomial c = plm_sum(a, b);
	polynomial d = plm_mul(a, b);

	plm_print(a);
	printf(" + ");
	plm_print(b);
	printf(" = ");
	plm_print(c);
	puts("");
	
	plm_print(a);
	printf(" * ");
	plm_print(b);
	printf(" = ");
	plm_print(d);
	puts("");
	
	plm_free(a);
	plm_free(b);
	plm_free(c);
	plm_free(d);

	return 0;
}
