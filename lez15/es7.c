/*
	Scrivere un programma che calcoli il fattoriale di un numero
	intero fornito dall’utente.
*/
#include <stdio.h>

int main()
{
	// Prendo in input un numero intero positivo.
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);

	/* Calcolo il fattoriale di n.
	   n! = n * (n-1) * (n-2) * ... * 1
	   Imponendo n > 1 anziché n >= 1 la moltiplicazione per 1
	   non viene effettuata, dato che è superflua.
	*/
	unsigned long int fattoriale = 1;
	for(; n > 1 ; n--)
		fattoriale *= n;

	// Stampo il risultato ottenuto.
	printf("%lu\n", fattoriale);

	return 0;
}
