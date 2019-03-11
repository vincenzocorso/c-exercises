/*
	Scrivere una funzione che data una matrice A[N][M] e due indici
	di riga i e j effettui lo scambio tra le righe i e j della matrice.
*/
#include <stdio.h>
#include <stdlib.h>

void scambia_righe(int **matrice, unsigned int riga1, unsigned int riga2);
void stampa_matrice(int **matrice, const unsigned int righe, const unsigned int colonne);

int main()
{
	const unsigned int righe = 2, colonne = 3;

	/* Alloca la memoria per la matrice */
	int **matrice = (int **)malloc(righe * sizeof(int *));
	for(unsigned int i = 0; i < righe; i++)
		matrice[i] = (int *)malloc(colonne * sizeof(int));

	/* Inizializza la matrice */
	matrice[0][0] = 1;
	matrice[0][1] = 2;
	matrice[0][2] = 3;
	matrice[1][0] = 4;
	matrice[1][1] = 5;
	matrice[1][2] = 6;

	/* Scambia le righe */
	stampa_matrice(matrice, righe, colonne);
	printf("\n\n");
	scambia_righe(matrice, 0, 1);	
	stampa_matrice(matrice, righe, colonne);

	/* Libera la memoria */
	for(unsigned int i = 0; i < righe; i++)
		free(matrice[i]);
	free(matrice);
	

	return 0;
}

void scambia_righe(int **matrice, unsigned int riga1, unsigned int riga2)
{
	matrice[riga1] = (int*)((int)matrice[riga1] ^ (int)matrice[riga2]);
	matrice[riga2] = (int*)((int)matrice[riga1] ^ (int)matrice[riga2]);
	matrice[riga1] = (int*)((int)matrice[riga1] ^ (int)matrice[riga2]);
}

void stampa_matrice(int **matrice, const unsigned int righe, const unsigned int colonne)
{
	for(unsigned int i = 0; i < righe; i++)
	{
		for(unsigned int j = 0; j < colonne; j++)
			printf("%d ", matrice[i][j]);

		printf("\n");
	}
}
