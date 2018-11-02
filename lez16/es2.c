/*
	Scrivere un programma che calcola il numero di confronti fatti
	dall’algoritmo per il calcolo del MCD tramite la differenza.
*/
#include <stdio.h>

int main()
{
	// Prende in input due numeri interi.
	unsigned int a, b;
	printf("Inserisci due numeri interi: ");
	scanf("%u%u", &a, &b);

	// Calcola il massimo comun divisore utilizzando il metodo della differenza.
	unsigned int contatore = 0;
	while(a != b)
	{
		if(a > b)
			a = a - b;
		else
			b = b - a;

		contatore += 2; // Ad ogni ciclo il numero di confronti aumenta di 2.
	}

	// Stampa il risultato calcolato e il numero di confronti eseguiti.
	printf("Il massimo comun divisore è %u.\n", a);
	printf("Il numero di confronti eseguiti è %u.\n", contatore);

	return 0;
}
