#include <stdio.h>
#include "polynomial.h"

void tartaglia(int pow)
{
	polynomial a = plm_init(0, (double[]) {1});
	polynomial b = plm_init(1, (double[]) {1,1});

	printf("%*s", pow*2, " ");
	plm_print_coefficients(a);
	puts("");
	for(int i = 1; i <= pow; i++)
	{
		polynomial c = plm_mul(a, b);
		plm_free(a);
		a = c;
		printf("%*s", (pow-i)*2, " ");
		plm_print_coefficients(c);
		puts("");
	}
	
	plm_free(a);
	plm_free(b);
}

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

	printf("a = ");
	plm_print(a);
	puts("");
	printf("a(2) = %.3f\n", plm_eval(a, 2));
	
	tartaglia(5);
	
	plm_free(a);
	plm_free(b);
	plm_free(c);
	plm_free(d);

	return 0;
}
