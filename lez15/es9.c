/*
	Esercizio 9
	Siano a, b, c tre numeri interi minori di n. Dato n dato in input,
	visualizzare le terne pitagoriche a, b, c, ovvero tali che a^2+b^2=c^2.
*/
#include <stdio.h>
#include <math.h>

int main()
{
	// Prendo in input un numero positivo n.
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);

	/* Stampa le terne pitagoriche tali che a, b, c sono minori di n.
	   Impostando b = a nel secondo for, evitiamo di stampare delle terne doppioni.
	   Aumentiamo a e b di 1 finché questi sono minori di radice di n (sfruttiamo
	   il crivello di Eratostene per aumentare l'efficienza ed effettuare meno calcoli)
	*/
	for(unsigned int a = 1; a <= sqrt(n); a++)
		for(unsigned int b = a; b <= sqrt(n); b++)
			if(a * a + b * b < n)
				printf("a=%u, b=%u, c=%u\n", a, b, a * a + b * b);

	return 0;
}
