/*
	Implementare la funzione
		void MaxMin(float *V, int dim, float *M, float *m, int *indM, int*indm);
	che dato il vettore V di reali, ne determini il massimo (M) e minimo (m) insieme alla
	loro posizione nel vettore V restituendo i puntatori *M, *m, *indM, *indm rispettivamente.
*/
#include <stdio.h>

#define SIZE	6

void MaxMin(float* V, int dim, float* M, float* m, int* indM, int* indm);

int main()
{
	float vettore1[SIZE] = {4, 8, 21, -54, 12, 5};
	float vettore2[SIZE] = {0, 0, 0, 0, 0, 0};

	float min, max;
	int indm, indM;

	MaxMin(vettore1, SIZE, &max, &min, &indM, &indm);
	printf("vettore1: max %f - min %f - indM %d - indm %d\n", max, min, indM, indm);

	MaxMin(vettore2, SIZE, &max, &min, &indM, &indm);
	printf("vettore2: max %f - min %f - indM %d - indm %d\n", max, min, indM, indm);

	return 0;
}

void MaxMin(float* V, int dim, float* M, float* m, int* indM, int* indm)
{
	*M = V[0];
	*indM = 0;
	*m = V[0];
	*indm = 0;

	for(size_t i = 1; i < dim; i++)
	{
		if(V[i] < *m)
		{
			*m = V[i];
			*indm = i;
		}

		if(V[i] > *M)
		{
			*M = V[i];
			*indM = i;
		}
	}
}
