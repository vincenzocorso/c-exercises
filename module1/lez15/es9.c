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
	*/
	unsigned int c;
	for(unsigned int a = 1; a < n; a++)
	{
		for(unsigned int b = a; b < n; b++)
		{
			c = (int)sqrt(a * a + b * b);
			if(c < n && c * c == a * a + b * b) // verifico che c sia una radice perfetta
				printf("a=%u, b=%u, c=%u\n", a, b, c);
		}
	}

	return 0;
}
