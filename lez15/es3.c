/*
	Dato un numero positivo N calcolare e visualizzare tutte le coppie di
	numeri positivi che danno per somma il numero stesso.
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);

	/* Stampa le coppie di numeri la cui somma è uguale a n.
	   Queste coppie sono del tipo (i ; n - i) incrementando
	   ogni volta i di 1. Per evitare di stampare coppie
	   doppioni bisogna usare la seguente relazione:
	   i <= n - i  da cui segue  n >= 2 * i
	   Dato che devo moltiplicare i per 2, per aumentare
	   l'efficienza, anzichè utilizzare la moltiplicazione
	   si può usare lo shift --> n >= i << 1
	*/
	for(unsigned int i = 1; n >= i << 1; i++)
		printf("(%u, %u)\n", i, n - i);

	return 0;
}
