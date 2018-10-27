/*
	Esercizio 8
	Dato un intero b a 32 bit, implementare in C un programma che
	calcola quoziente e resto della divisione di b per 2^i.
	Risolvere il problema SENZA fare uso del prodotto e della divisione.
*/
#include <stdio.h>

int main()
{
	// Prende in input due numeri interi.
	int b, i;
	printf("Inserisci due numeri interi: ");
	scanf("%d%d", &b, &i);
	
	/* Calcola il quoziente shiftando a destra.
	   Calcola il resto sottraendo a b il quoziente calcolato.
	   Infine stampa il risultato. */
	int quoziente = b >> i;
	int resto = b - (quoziente << i);
	printf("Quoziente: %d | Resto: %d", quoziente, resto);
	
	return 0;
}