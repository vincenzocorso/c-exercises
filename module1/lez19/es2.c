/*
	Si scriva una funzione in linguaggio C per calcolare il
	massimo comun divisore (MCD) tra due numeri interi positivi
	a e b che non faccia uso ne dell’algoritmo di euclide ne della
	soluzione con le differenze.
*/
#include <stdio.h>
#include <math.h>

unsigned int mcd(unsigned int a, unsigned int b);

int main()
{
	// Prendo in input due numeri interi positivi.
	unsigned int a, b;
	printf("Inserisci due numeri interi positivi: ");
	scanf("%u%u", &a, &b);

	// Stampo il risultato.
	printf("Il massimo comun divisore è %u\n", mcd(a, b));

	return 0;
}

unsigned int mcd(unsigned int a, unsigned int b)
{
	// Trovo il minimo tra a e b.
	unsigned int min = a;
	if(b < a)
		min = b;

	/*
		Inizializzo il divisore al minimo tra a e b.
		Questo è il più grande numero che potrebbe dividere a e b.
		Decremento finchè non viene trovato un valore per cui:
			(a % M == 0) && (b % M == 0)
	*/
	unsigned int divisore;
	for(divisore = min; a % divisore || b % divisore; divisore--);

	return divisore;
}
