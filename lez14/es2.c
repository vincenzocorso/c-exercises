/*
	Esercizio 2
	Dati due interi positivi r e q, con r<q scrivere un programma che
	calcola: sommatoria da i=r a q di (1/i)
*/
#include <stdio.h>

// Viene definito lo XOR come funzione macro.
#define XOR(a, b) (a & ~b) | (b & ~a)

int main()
{
	// Prende in input due numeri interi positivi.
	unsigned int r, q;
	printf("Inserisci due numeri interi positivi: ");
	scanf("%u%u", &r, &q);
	
	// Se r è maggiore di q, allora scambia i due numeri.
	if(r > q)
	{
		r = XOR(r, q);
		q = XOR(q, r);
		r = XOR(r, q);
	}
	
	// Calcola la sommatoria.
	double somma = 0.0;
	for(unsigned int i = r; i <= q; i++)
		somma += 1.0 / i;
	
	// Stampa il risultato.
	printf("Il risultato della sommatoria è %f.\n", somma);

	return 0;
}