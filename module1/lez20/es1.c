/*
	Chiedere 2 num. interi (a,b) e disegnare un rettangolo di
	dimensioni a*b usando il carattere "*".
*/
#include <stdio.h>

void stampa_rettangolo(const unsigned int a, const unsigned int b);

int main()
{
	// Prende in input le dimensioni a e b del rettangolo.
	unsigned int a, b;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u%u", &a, &b);

	stampa_rettangolo(a, b);

	return 0;
}

void stampa_rettangolo(const unsigned int a, const unsigned int b)
{
	for(unsigned int i = 1; i <= a; i++)
	{
		for(unsigned int j = 1; j <= b; j++)
			printf("*");

		printf("\n");
	}
}
