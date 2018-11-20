/*
	Sia data una griglia di dimensione nxn con n fornito in input, e
	si consideri di numerare in ordine crescente da sinistra verso
	destra e per riga la griglia
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo."
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);

	for(unsigned int i = 1; i <= n * n; i++)
	{
		printf("%4u ", i);

		if(!(i % n))
			printf("\n");
	}	

	return 0;
}
