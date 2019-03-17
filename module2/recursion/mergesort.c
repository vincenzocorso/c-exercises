#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Order relations */
int descending(int a, int b);
int ascending(int a, int b);

/* Mergesort */
void mergesort(int *array, size_t size, int (*comp)(int a, int b));
void sortarray(int *array, size_t size, size_t left, size_t right, int (*comp)(int a, int b));
void merge(int *array, size_t size, size_t left, size_t middle1, size_t middle2, size_t right, int (*comp)(int a, int b));

/* Insertion sort */
void insertionsort(int *array, size_t left, size_t right, int (*comp)(int a, int b));

/* Utils */
void print_array(const int *array, size_t size);

/* Global vars */
static int optimised = 0;

int main()
{
	/* Richiede un numero positivo in input */
	unsigned int N;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &N);

	/* Riempie due array con gli stessi valori casuali */
	int array1[N], array2[N];
	srand(time(NULL));
	for(size_t i = 0; i < N; i++)
		array1[i] = array2[i] = rand() % N;

	/* Permette di scegliere l'ordinamento con cui saranno ordinati i due array */
	unsigned int order;
	do
	{
		printf("\nInserisci un ordinamento:\n0. Ordina in maniera decrescente\n1. Ordina in maniera crescente\n--> ");
		scanf("%u", &order);
	}
	while(order > 2);

	int (*sorting[2])(int a, int b) = {descending, ascending};
	
	/* Stampa l'array */
	clock_t time1, time2;
	double result1, result2;
	puts("\nArray");
	print_array(array1, N);

	/* Ordina il primo array utilizzando il mergesort non ottimizzato */
	puts("\nMergesort non ottimizzato");
	optimised = 0;
	time1 = clock();
	mergesort(array1, N, sorting[order]);
	time2 = clock();
	print_array(array1, N);
	result1 = (double)(time2 - time1) / CLOCKS_PER_SEC;

	/* Ordina il secondo array utilizzando il mergesort combinato a insertion sort */
	puts("\nMergesort ottimizzato");
	optimised = 1;
	time1 = clock();
	mergesort(array2, N, sorting[order]);
	time2 = clock();
	print_array(array2, N);
	result2 = (double)(time2 - time1) / CLOCKS_PER_SEC;

	/* Stampa le statistiche */
	printf("Mergesort non ottimizzato: %f\nMergesort ottimizzato: %f\n", result1 / 60.0, result2 / 60.0);

	return 0;
}

/* Order relations */
int descending(int a, int b)
{
	return a > b;
}

int ascending(int a, int b)
{
	return a < b;
}

/* Mergesort */
void mergesort(int *array, size_t size, int (*comp)(int a, int b))
{
	sortarray(array, size, 0, size - 1, comp);
}

void sortarray(int *array, size_t size, size_t left, size_t right, int (*comp)(int a, int b))
{
	if(left == right)
		return;

	if(optimised && right - left < 7)
	{
		insertionsort(array, left, right, comp);
	}
	else
	{
		size_t middle1 = (left + right) / 2;
		size_t middle2 = middle1 + 1;
		sortarray(array, size, left, middle1, comp);
		sortarray(array, size, middle2, right, comp);
		merge(array, size, left, middle1, middle2, right, comp);
	}
}

void merge(int *array, size_t size, size_t left, size_t middle1, size_t middle2, size_t right, int (*comp)(int a, int b))
{
	size_t leftidx = left, rightidx = middle2, tempidx = left;
	int arraytmp[size];

	while(leftidx <= middle1 && rightidx <= right)
	{
		if((*comp)(array[leftidx], array[rightidx]))
			arraytmp[tempidx++] = array[leftidx++];
		else
			arraytmp[tempidx++] = array[rightidx++];
	}

	if(leftidx == middle2)
		while(rightidx <= right)
			arraytmp[tempidx++] = array[rightidx++];
	else
		while(leftidx <= middle1)
			arraytmp[tempidx++] = array[leftidx++];

	for(size_t i = left; i <= right; i++)
		array[i] = arraytmp[i];
}

/* Insertion sort */
void insertionsort(int *array, size_t left, size_t right, int (*comp)(int a, int b))
{
	for(size_t i = left; i <= right; i++)
	{
		int tmp = array[i], j;
		for(j = i; j > left && (*comp)(tmp, array[j - 1]); j--)
			array[j] = array[j - 1];

		array[j] = tmp;
	}
}

/* Utils */
void print_array(const int *array, size_t size)
{
	for(size_t i = 0; i < size; i++)
		printf("%d ", array[i]);
	puts("");
}
