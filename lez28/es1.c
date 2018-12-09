/*
	Scrivere una funzione che data una matrice A[N][M] di
	numeri reali ne determini il massimo e minimo insieme alla
	loro prima posizione.
*/
#include <stdio.h>

#define N	3
#define M	2

void minmax_matrice(const unsigned int righe, const unsigned int colonne, const int matrice[][colonne], int *max, int *min, int *posmax, int *posmin);

int main()
{
	int matrice[N][M] = {
		{1, 2},
		{7, 4},
		{9, 12}	
	};

	int max, min, posmax, posmin;
	minmax_matrice(N, M, matrice, &max, &min, &posmax, &posmin);
	printf("max %d (pos %d) | min %d (pos %d)\n", max, posmax, min, posmin);

	return 0;
}

void minmax_matrice(const unsigned int righe, const unsigned int colonne, const int matrice[][colonne], int *max, int *min, int *posmax, int *posmin)
{
	*max = *min = matrice[0][0];
	*posmax = *posmin = 0;

	for(unsigned int i = 0; i < righe; i++)
	{
		for(unsigned int j = 0; j < colonne; j++)
		{
			if(matrice[i][j] > *max)
			{
				*max = matrice[i][j];
				*posmax = ((int)&matrice[i][j] - (int)matrice) / sizeof(int);
			}
			
			if(matrice[i][j] < *min)
			{
				*min = matrice[i][j];
				*posmin = ((int)&matrice[i][j] - (int)matrice) / sizeof(int);
			}
		}
	}
}
