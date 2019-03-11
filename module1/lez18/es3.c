/*
	Scrivete un programma che dato in input un numero
	decimale n, anche negativo, utilizzi una funzione per
	visualizzare le sue singole cifre separate da tre spazi.
*/
#include <stdio.h>
#include <math.h>

void stampa_cifre(int numero);

int main()
{
	// Prende in input un intero.
	int n;
	printf("Inserisci un numero intero: ");
	scanf("%d", &n);

	// Richiama la funzione che permette di stampare le cifre.
	stampa_cifre(n);

	return 0;
}

void stampa_cifre(int numero)
{
	// Prende il numero di cifre del numero.
	unsigned int cifre = 0;
	for(int i = numero; i != 0; i /= 10, cifre++);
	
	/* 
		Utilizzo il seguente metodo per gestire le cifre:
			75450 / 10000 = 7
			75450 % 10000 = 5450
	*/
	int divisore = pow(10, cifre - 1);
	while(divisore)
	{
		printf("%d   ", numero / divisore);
		numero %= divisore;
		divisore /= 10;
	}

	printf("\n");
}
