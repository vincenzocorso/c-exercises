/*
	Si scriva una funzione che implementi la Ricerca Binaria.
*/
#include <stdio.h>

int ricerca_binaria(const int vettore[], const unsigned int dimensione, const int valore);

int main()
{
	int vettore[5] = {1, 69, 87, 112, 200};
	
	int numero;
	printf("Inserisci un valore da ricercare all'intero dell'array: ");
	scanf("%d", &numero);

	printf("Il valore inserito %s presente nell'array.\n", (ricerca_binaria(vettore, 5, numero) >= 0) ? "è" : "non è");
}

int ricerca_binaria(int vettore[], unsigned int dimensione, int valore)
{
	int sx = 0, dx = dimensione - 1, cx;

	while(sx <= dx)
	{
		cx = (sx + dx) / 2;

		if(valore == vettore[cx])
			return cx;
		else if(valore > vettore[cx])
			sx = cx + 1;
		else
			dx = cx - 1;
	}

	return -1;
}
