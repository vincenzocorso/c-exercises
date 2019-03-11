#include <stdio.h>
#include "libsort.h"

extern int compare(double *a, double *b);

void swap_pointer(void **a, void **b)
{
	*a = (void*)((int)*a ^ (int)*b);
	*b = (void*)((int)*a ^ (int)*b);
	*a = (void*)((int)*a ^ (int)*b);
}

void simple_sort(void **array, const unsigned int size, const int order)
{
	for(unsigned int i = 0; i < size - 1; i++)
	{
		for(unsigned int j = i + 1; j < size; j++)
			if(compare(array[i], array[j]) == order)
				swap_pointer(&array[i], &array[j]);
	}
}

void selection_sort(void **array, const unsigned int size, const int order)
{
	unsigned int min;
	for(unsigned int i = 0; i < size - 1; i++)
	{
		min = i;
		for(unsigned int j = i + 1; j < size; j++)
			if(compare(array[min], array[j]) == order)
				min = j;
		if(min != i)
			swap_pointer(&array[i], &array[min]);
	}
}

void insertion_sort(void **array, const unsigned int size, const int order)
{
	int j;
	for(unsigned int i = 0; i < size; i++)
	{
		void *tmp = array[i];
		for(j = i - 1; j >= 0 && (compare(array[j], tmp) == order); j--)
			array[j + 1] = array[j];

		array[j + 1] = tmp;
	}
}

void bubble_sort(void **array, const unsigned int size, const int order)
{
	for(unsigned int i = 0; i < size; i++)
	{
		for(unsigned int j = 0; j < size - 1 - i; j++)
		{
			if(compare(array[j], array[j+1]) == order)
				swap_pointer(&array[j], &array[j + 1]);
		}
	}
}
