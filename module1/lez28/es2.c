/*
	Scrivere una funzione che date due matrici A[N][M] e
	B[M][N] ne calcoli il prodotto riga-colonna.
*/
#include <stdio.h>
#include <stdlib.h>

#define N	4
#define M	3
#define O	5

void prodotto_matrici(const unsigned int righe1, const unsigned int colonne1, int matrice1[][colonne1], const unsigned int colonne2, int matrice2[][colonne2], int risultato[][colonne2]);
void stampa_matrice(const unsigned int rows, const unsigned int columns, int matrice[][columns]);

int main()
{
	/* Dichiarazione delle matrici */
	int A[N][M] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{10, 11, 12}	
	};

	int B[M][O] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	};

	int risultato[4][5];

	/* Calcola il prodotto tra matrici */
	stampa_matrice(N, M, A);
	printf("\n\n");
	stampa_matrice(M, O, B);
	printf("\n\n");
	prodotto_matrici(N, M, A, O, B, risultato);
	stampa_matrice(N, O, risultato);

	return 0;
}

void prodotto_matrici(const unsigned int righe1, const unsigned int colonne1, int matrice1[][colonne1], const unsigned int colonne2, int matrice2[][colonne2], int risultato[][colonne2])
{
	unsigned int somma = 0;
	for(unsigned int i = 0; i < righe1; i++)
	{
		for(unsigned int j = 0; j < colonne2; j++)
		{
			for(unsigned int k = 0; k < colonne1; k++)
				somma += matrice1[i][k] * matrice2[k][j];

			risultato[i][j] = somma;
			somma = 0;
		}
	}
}

void stampa_matrice(const unsigned int rows, const unsigned int columns, int matrice[][columns])
{
	for(unsigned int i = 0; i < rows; i++)
	{
		for(unsigned int j = 0; j < columns; j++)
			printf("%5d ", matrice[i][j]);

		printf("\n");
	}
}
