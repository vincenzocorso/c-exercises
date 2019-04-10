#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N	10
#define min(a,b)	((a) < (b)) ? (a) : (b)

void print_array(int array[], size_t size);
void mergesort(int array[], size_t size);
void merge(int array[], size_t size, size_t left, size_t middle1, size_t middle2, size_t right);

int main()
{
	srand(time(NULL));

	int array[N];
	for(size_t i = 0; i < N; i++)
		array[i] = -10 + rand() % 21;

	print_array(array, N);
	mergesort(array, N);
	print_array(array, N);
	
	return 0;
}

void print_array(int array[], size_t size)
{
	for(size_t i = 0; i < size; i++)
		printf("%d ", array[i]);
	puts("");
}

void mergesort(int array[], size_t size)
{
	for(int s = 1; s < size; s *= 2)
		for(int j = 0; j < size; j += 2*s)
			merge(array, size, j, j+s-1, j+s, min(j+2*s-1, size-1));
}

void merge(int array[], size_t size, size_t left, size_t middle1, size_t middle2, size_t right)
{
	size_t leftidx = left, rightidx = middle2, tmpidx = left;
	int tmp[size];
	
	while(leftidx <= middle1 && rightidx <= right)
	{
		if(array[leftidx] < array[rightidx])
			tmp[tmpidx++] = array[leftidx++];
		else
			tmp[tmpidx++] = array[rightidx++];
	}
	
	if(leftidx == middle2)
	{
		while(rightidx <= right)
			tmp[tmpidx++] = array[rightidx++];
	}
	else
	{
		while(leftidx <= middle1)
			tmp[tmpidx++] = array[leftidx++];
	}
	
	for(size_t i = left; i <= right; i++)
		array[i] = tmp[i];
}
