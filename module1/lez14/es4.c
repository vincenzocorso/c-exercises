/*
	Esercizio 4
	Sia data una griglia di dimensione nxn con n fornito in input, e
	si consideri di numerare in ordine crescente, e per riga, la parte
	triangolare inferiore della matrice. Si scriva un programma in C
	che visualizza il conteggio per come scritto in griglia, con i
	numeri separati dalla ", ".
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);
	
	/* Scorre le entrate della matrice in posizione i < j
	   Definizione di matrice triangolare inferiore. */
	unsigned int entrata = 1;
	for(unsigned int riga = 1; riga <= n; riga++)
	{
		for(unsigned int colonna = 1; colonna <= riga; colonna++)
			printf("%4u, ", entrata++);
		
		printf("\n");
	}
	
	return 0;
}
