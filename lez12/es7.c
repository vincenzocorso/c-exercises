/*
	Esercizio 7
	Scrivete un programma che prende in input un numero di 4 cifre e lo
	scompone in unità, decine, centinaia, migliaia, e visualizza la
	scomposizione separata da spazi.
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero di 4 cifre.
	unsigned int numero;
	printf("Inserisci un numero intero positivo di 4 cifre: ");
	scanf("%u", &numero);
	
	/* Vengono eseguite in ripetizione divisioni e resti per
	   scomporre il numero in migliaia, centinaia, decine, unità. */
	printf("%u migliaia\n", numero / 1000);
	numero %= 1000;
	
	printf("%u centinaia\n", numero / 100);
	numero %= 100;
	
	printf("%u decine\n", numero / 10);
	numero %= 10;
	
	printf("%u unità\n", numero);
	
	return 0;
}