/*
	Si scriva un algoritmo che ordini un vettore in maniera crescente
	o decrescente facendo uso della funzione minmax(t, A, n). Tale
	funzione ritorna il minimo se t=0 e il massimo se t=1 di un
	vettore in cui il primo elemento è A[0] e l'ultimo è A[n].
*/
#include <stdio.h>

void ordina(const int t, int vettore[], const unsigned int dimensione);
int minmax(const int vettore[], const unsigned int n, const int t);
void swap(int *a, int *b);
void stampa_vettore(const int vettore[], const unsigned int dimensione);

int main()
{
	int vettore[5] = {1, 8, -5, -35, 78};

	stampa_vettore(vettore, 5);
	ordina(1, vettore, 5);
	stampa_vettore(vettore, 5);

	return 0;
}

void ordina(const int t, int vettore[], const unsigned int dimensione)
{
	int index;
	for(unsigned int i = 0; i < dimensione; i++)
	{
		index = minmax(t, vettore, dimensione - 1 - i);
		//printf("%d in index %d\n", vettore[index], dimensione - 1 - i);
		swap(&vettore[index], &vettore[dimensione - 1 - i]);
		//stampa_vettore(vettore, dimensione);
	}
}

int minmax(const int vettore[], const unsigned int n, const int t)
{
	int index = 0;

	for(unsigned int i = 1; i <= n; i++)
	{
		if(t == 0 && vettore[i] < vettore[index])
			index = i;
		else if(t == 1 && vettore[i] > vettore[index])
			index = i;
	}

	return index;
}

void swap(int *a, int *b)
{
	if(a != b) // se gli indirizzi di memoria sono gli stessi non effettua lo swap.
	{	
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}

void stampa_vettore(const int vettore[], const unsigned int dimensione)
{
	for(unsigned int i = 0; i < dimensione; i++)
		printf("%5d ", vettore[i]);

	printf("\n");
}
