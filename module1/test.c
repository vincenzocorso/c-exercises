#include <stdio.h>
#include "vincenzo.h"

int main()
{
	// swap() test
	int a = 2, b = 3;
	puts("\nswap()");
	printf("a=%d b%d\n", a, b);
	swap(&a, &b);
	printf("a=%d b%d\n", a, b);

	// mcd_euclide() test
	puts("\nmcd_euclide()");
	printf("%u\n", mcd_euclide(1, 2));
	printf("%u\n", mcd_euclide(5, 35));
	printf("%u\n", mcd_euclide(35, 5));
	printf("%u\n", mcd_euclide(54, 123));

	// mcd_differenza() test
	puts("\nmcd_differenza()");
	printf("%u\n", mcd_differenza(1, 2));
	printf("%u\n", mcd_differenza(5, 35));
	printf("%u\n", mcd_differenza(35, 5));
	printf("%u\n", mcd_differenza(54, 123));

	// my_mcd() test
	puts("\nmy_mcd()");
	printf("%u\n", my_mcd(1, 2));
	printf("%u\n", my_mcd(5, 35));
	printf("%u\n", my_mcd(35, 5));
	printf("%u\n", my_mcd(54, 123));

	// my_mcm() test
	puts("\nmy_mcm()");
	printf("%u\n", my_mcm(1, 2));
	printf("%u\n", my_mcm(5, 35));
	printf("%u\n", my_mcm(35, 5));
	printf("%u\n", my_mcm(54, 123));

	// primo() test
	puts("\nprimo()");
	printf("%d\n", primo(7));
	printf("%d\n", primo(12));
	printf("%d\n", primo(31));
	printf("%d\n", primo(66));

	// fattoriale() test
	puts("\nfattoriale()");
	printf("%llu\n", fattoriale(5));
	printf("%llu\n", fattoriale(2));
	printf("%llu\n", fattoriale(4));
	printf("%llu\n", fattoriale(12));
	printf("%llu\n", fattoriale(15));
	printf("%llu\n", fattoriale(18));

	// stampa_fibonacci() test
	puts("\nstampa_fibonacci()");
	stampa_fibonacci(0);
	stampa_fibonacci(1);
	stampa_fibonacci(2);
	stampa_fibonacci(5);
	stampa_fibonacci(10);

	return 0;
}
