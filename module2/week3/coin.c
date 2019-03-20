#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COIN	10
#define RIGHE		9
#define COLONNE		15

static int backtrack[RIGHE][COLONNE];

int coin(const int array[][COLONNE], size_t i, size_t j);
void stampa_backtrack(const int backtrack[][COLONNE], size_t i, size_t j);

void stampa_matrice(size_t righe, size_t colonne, const int array[][colonne]);
int max(int a, int b);

int main()
{
	int array[RIGHE][COLONNE];

	srand(time(NULL));
	for(size_t i = 0; i < RIGHE; i++)
		for(size_t j = 0; j < COLONNE; j++)
			array[i][j] = rand() % (MAX_COIN + 1);

	stampa_matrice(RIGHE, COLONNE, array);
	printf("Coin: %d\n", coin(array, RIGHE - 1, COLONNE - 1));
	puts("Track:");
	stampa_backtrack(backtrack, RIGHE - 1, COLONNE - 1);

	return 0;
}

int coin(const int array[][COLONNE], size_t i, size_t j)
{
	static int dp_table[RIGHE][COLONNE];

	if(i == 0 && j == 0)
		return array[0][0];
	
	if(dp_table[i][j] == 0)
	{
		if(i == 0)
		{
			backtrack[i][j] = -1;
			dp_table[i][j] = coin(array, i, j - 1) + array[i][j];
		}
		else if(j == 0)
		{
			backtrack[i][j] = 1;
			dp_table[i][j] = coin(array, i - 1, j) + array[i][j];
		}
		else
		{
			int left = coin(array, i, j - 1);
			int up = coin(array, i - 1, j);
			backtrack[i][j] = (left > up) ? -1 : 1;
			dp_table[i][j] = max(left, up) + array[i][j];
		}
	}

	return dp_table[i][j];
}

void stampa_backtrack(const int backtrack[][COLONNE], size_t i, size_t j)
{
	if(i == 0 && j == 0)
	{
		printf("(%u, %u)\n", i, j);
		return;
	}

	if(backtrack[i][j] == -1)
		stampa_backtrack(backtrack, i, j - 1);
	else
		stampa_backtrack(backtrack, i - 1, j);

	printf("(%u, %u)\n", i, j);
}

void stampa_matrice(size_t righe, size_t colonne, const int array[][colonne])
{
	for(size_t i = 0; i < righe; i++)
	{
		for(size_t j = 0; j < colonne; j++)
			printf("%-2d ", array[i][j]);
		puts("");
	}
	puts("");
}

int max(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}
