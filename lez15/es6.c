/*
	Scrivere un programma che dato in ingresso un certo numero
	produca la radice quadrata intera di i.
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int i;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &i);

	/* Stampa la radice intera di i. Se i = 6
	   n = 0 --> 0 * 0 = 0
	   n = 1 --> 1 * 1 = 1
	   n = 2 --> 2 * 2 = 4
	   n = 3 --> 3 * 3 = 9 (mi fermo perché 9 > i)
	   la soluzione è n = 2. */ 
	unsigned int n;
	for(n = 0; n * n <= i; n++);
	
	// Stampa il risultato ottenuto.
	printf("Il risultato è %u\n", --n);

	return 0;
}
