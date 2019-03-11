/*
	Esercizio 1
	Dato un carattere in input, stampare il suo codice ascii.
*/
#include <stdio.h>

int main()
{
	// Prende in input un carattere.
	printf("Inserisci un carattere alfanumerico: ");
	char c = getchar();
	
	/* Stampa il codice ascii del carattere.
	   Il char viene viene trattato come un intero. */
	printf("Codice ascii: %d\n", c);

	return 0;
}