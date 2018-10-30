/*
	Dato un numero N calcolare e visualizzare tutte le coppie di numeri
	che danno per prodotto il numero stesso.
*/
#include <stdio.h>
#include <math.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int n;
	printf("Inserisci un numero positivo n: ");
	scanf("%u", &n);

	/* Stampa le coppie di numeri tali che il loro prodotto
	   sia n. Queste coppie sono del tipo (i ; k) dove i
	   aumenta di ogni ogni iterazione e k è un numero
	   intero tale che k = n / i. Per aumentare l'efficienza
	   si può sfruttare il crivello di Eratostene, secondo cui,
	   i fattori di un numero n sono tutti minori di radice di n. */
	for(unsigned int i = 1; i <= sqrt(n); i++)
		if(!(n % i))
			printf("(%d, %d)\n", i, n / i);

	return 0;
}
