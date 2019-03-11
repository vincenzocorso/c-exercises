/*
	Implementare la funzione
		void addSort(float *V, int dim, float a);
	che inserisce il float a nel vettore ordinato V in modo che il vettore
	risultante dell'inserimento sia ancora ordinato. Ad es, se
		V = {3.4, 5.2, 9.8, 10.3, 12.0, 130, 250} e
	a = 138,
	la chiamata addSort(V, 8, 138) dovrà produrre l'array
	{3.4, 5.2, 9.8, 10.3, 12.0, 130, 138, 250}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_SIZE	7

void stampa_vettore(float *V, int dim);
float* inserisci(float *V, int dim, int pos, float valore);
float* addSort(float *V, int dim, float a);

int main()
{
	float valori_iniziali[START_SIZE] = {3.4, 5.2, 9.8, 10.3, 12.0, 130, 250};

	float* V = (float*)calloc(START_SIZE, sizeof(float));
	for(size_t i = 0; i < START_SIZE; i++)
		V[i] = valori_iniziali[i];

	stampa_vettore(V, START_SIZE);
	V = addSort(V, START_SIZE, 251);
	stampa_vettore(V, START_SIZE + 1);

	free(V);

	return 0;
}

void stampa_vettore(float *V, int dim)
{
	for(size_t i = 0; i < dim; i++)
		printf("%f ", V[i]);

	printf("\n");
}

float* inserisci(float *V, int dim, int pos, float valore)
{
	V = (float*)realloc(V, (dim + 1) * sizeof(float));
	for(size_t i = dim; i > pos; i--)
		V[i] = V[i-1];

	V[pos] = valore;
	return V;
}

/* Utilizza una variante della ricerca binaria per trovare la posizione corretta */
float* addSort(float *V, int dim, float a)
{
	size_t sx = 0, dx = dim - 1, cx;

	while(sx != dx)
	{
		cx = (sx + dx) / 2;

		if(V[cx] == a)
			sx = dx;
		if(V[cx] > a)
			dx = cx - 1;
		else
			sx = cx + 1;
	}

	if(a > V[sx])
		V = inserisci(V, dim, sx + 1, a);
	else
		V = inserisci(V, dim, sx, a);

	return V;
}
