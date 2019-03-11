/*
	Dato N un numero intero positivo, generare e visualizzare in
	ordine crescente i numeri pari minori o uguali a N.
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);

	/* Stampa i numeri pari minori o uguali a n.
	   I numeri pari si discostano di 2. */
	for(unsigned int i = 0; i <= n; i += 2)
		printf("%u\n", i);

	return 0;
}
