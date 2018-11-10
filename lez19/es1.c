/*
	Si scriva una funzione in linguaggio C per calcolare il minimo
	comune multiplo (mcm) tra due numeri interi positivi a e b.
*/
#include <stdio.h>

unsigned int mcm(unsigned int a, unsigned int b);

int main()
{
	// Prende in input due numeri interi positivi.
	unsigned int a, b;
	printf("Inserisci due numeri interi positivi: ");
	scanf("%u%u", &a, &b);
	
	// Stampa il minimo comune multiplo tra a e b.
	printf("Il minimo comune multiplo è %u\n", mcm(a, b));

	return 0;
}

unsigned int mcm(unsigned int a, unsigned int b)
{
	// Trovo il minimo valore tra a e b
	unsigned int min = a;
	if(b < a)
		min = b;

	// Il mcm è il più piccolo intero che divide a e b.
	unsigned int mcm;
	for(mcm = min; mcm % a || mcm % b; mcm++);

	return mcm;
}
