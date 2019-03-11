/*
	Scrivere una funzione in C che, dati in input una Matrice M
	di interi n x m e due interi 0 <= i, j <= m, scambi le colonne
	i e j di M;

	VERSIONE A
	SCAMBIO I RISPETTIVI VALORI USANDO LO XOR
*/
#include <stdio.h>

#define N	3
#define M	5

void swap(int *a, int *b);
void swap_colonne(const unsigned int righe, const unsigned int colonne, int matrice[][colonne], const unsigned int colonna1, const unsigned int colonna2);
void stampa_matrice(const unsigned int righe, const unsigned int colonne, const int matrice[][colonne]);

int main()
{
	int matrice[N][M] = {
		{1, 2, 4, 43, 0},
		{-2, 4, 6, 32, 1},
		{9, 1, 0, 12, 1}
	};

	stampa_matrice(N, M, matrice);
	swap_colonne(N, M, matrice, 0, 4);
	stampa_matrice(N, M, matrice);

	return 0;
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void swap_colonne(const unsigned int righe, const unsigned int colonne, int matrice[][colonne], const unsigned int colonna1, const unsigned int colonna2)
{
	for(unsigned int i = 0; i < righe; i++)
		swap(&matrice[i][colonna1], &matrice[i][colonna2]);
}

void stampa_matrice(const unsigned int righe, const unsigned int colonne, const int matrice[][colonne])
{
	for(unsigned int i = 0; i < righe; i++)
	{
		for(unsigned int j = 0; j < colonne; j++)
			printf("%4d ", matrice[i][j]);

		printf("\n");	
	}
	printf("\n");
}
