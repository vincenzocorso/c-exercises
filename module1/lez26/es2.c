/*
	Scrivere una funzione che dati due vettori di interi
	a e b, restituisca un altro vettore contenente la loro somma.
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE	5

int* somma_vettori(int dimensione, int vettore1[], int vettore2[]);
void stampa_vettore(int dimensione, int vettore[]);

int main()
{
	int a[SIZE] = {1, 2, 4, 5, 9};
	int b[SIZE] = {5, 7, 2, 4, 1};

	int* vettore = somma_vettori(SIZE, a, b);
	stampa_vettore(SIZE, vettore);
	free(vettore);

	return 0;
}

int* somma_vettori(int dimensione, int vettore1[], int vettore2[])
{
	int* vettore = (int*)calloc(dimensione, sizeof(int));

	for(size_t i = 0; i < dimensione; i++)
		vettore[i] = vettore1[i] + vettore2[i];

	return vettore;
}

void stampa_vettore(int dimensione, int vettore[])
{
	for(size_t i = 0; i < dimensione; i++)
		printf("%d ", vettore[i]);

	printf("\n");
}
