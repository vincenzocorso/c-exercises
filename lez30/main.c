#include <stdio.h>
#include <stdlib.h>
#include "libsort.h"

#define N 5

int compare(double *a, double *b);
void print_array(void **array, const int size);

int main()
{
	double array[N] = {5.6, 41.3, 1.2, 3.0, -34.5};

	// Simple sort
	void **V = (void **)malloc(N * sizeof(void *));
	for(unsigned int i = 0; i < N; i++)
		V[i] = &array[i];

	simple_sort(V, N, 1);
	print_array(V, N);
	free(V);
	V = NULL;

	// Selection sort
	V = (void **)malloc(N * sizeof(void *));
	for(unsigned int i = 0; i < N; i++)
		V[i] = &array[i];

	selection_sort(V, N, 1);
	print_array(V, N);
	free(V);
	V = NULL;

	// Insertion sort
	V = (void **)malloc(N * sizeof(void *));
	for(unsigned int i = 0; i < N; i++)
		V[i] = &array[i];

	insertion_sort(V, N, 1);
	print_array(V, N);
	free(V);
	V = NULL;

	// Bubble sort
	V = (void **)malloc(N * sizeof(void *));
	for(unsigned int i = 0; i < N; i++)
		V[i] = &array[i];

	bubble_sort(V, N, 1);
	print_array(V, N);
	free(V);
	V = NULL;

	return 0;
}

int compare(double *a, double *b)
{
	if(*a > *b)
		return 1;
	else if(*a < *b)
		return -1;
	else
		return 0;
}

void print_array(void **array, const int size)
{
	for(unsigned int i = 0; i < size; i++)
		printf("%lf ", *(double*)array[i]);
	printf("\n");
}
