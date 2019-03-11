/*
	Scrivere un programma che dato un numero n>1 determini tutti i
	primi minori di n.
*/
#include <stdio.h>
#include <math.h>

int main()
{
	// Prendo in input un numero intero positivo:
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);

	unsigned int d;
	for(unsigned int primo = 1; primo < n; primo++)
	{
		for(d = 2; (primo % d) != 0 && d < primo; d++);

		if(primo == d)
			printf("%u\n", primo);
	}
	
	return 0;
}
