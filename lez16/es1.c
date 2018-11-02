/*
	Scrivere un programma che calcola il numero di confronti fatti
	dall’algoritmo di euclide per il calcolo del MCD.
*/
#include <stdio.h>

int main()
{
	// Prende in input due numeri interi positivi.
	unsigned int a, b;
	printf("Inserisci due numeri interi positivi: ");
	scanf("%u%u", &a, &b);

	// Calcola il massimo comun divisore utilizzando l'algoritmo di Euclide.
	unsigned int r, contatore = 0;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
		contatore++; // Ad ogni ciclo il numero di confronti aumenta di 1.
	}

	// Stampa il risultato calcolato e il numero di confronti eseguiti.
	printf("Il massimo comun divisore è %u.\n", a);
	printf("Il numero di confronti eseguiti è %u.\n", contatore);

	return 0;
}
