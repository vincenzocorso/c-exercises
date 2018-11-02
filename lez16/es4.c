/*
	Sia data una griglia di dimensione nxn con n fornito in input, e
	si consideri di numerare in ordine crescente dall’alto verso il
	basso, la diagonale della griglia.
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int n;
	printf("Inserisci un numero intero: ");
	scanf("%u", &n);

	// Stampa la diagonale della matrice.
	for(unsigned int riga = 1; riga <= n; riga++)
	{
		for(unsigned int colonna = 1; colonna <= riga - 1; colonna++)
			printf(" ");
		
		printf("%u\n", riga); 
	}

	return 0;
}
