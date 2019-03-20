#include <stdio.h>

#define SIZE	5

void print_array(const int array[], size_t size);
void swap(int array[], size_t a, size_t b);
size_t find_minimum(const int array[], size_t size);
size_t find_maximum(const int array[], size_t size);

void selection_sort_recursive(int array[], size_t size);

int main()
{
	int array1[SIZE] = {5, 8, -4, 3, 0};
	size_t temp = find_minimum(array1, SIZE);
	printf("minimum is %d (position %d)\n", array1[temp], temp);
	temp = find_maximum(array1, SIZE);
	printf("maximum is %d (position %d)\n", array1[temp], temp);

	int array2[SIZE] = {-6, 8, -4, 3, 1};
	print_array(array2, SIZE);
	selection_sort_recursive(array2, SIZE);
	print_array(array2, SIZE);

	return 0;
}

void print_array(const int array[], size_t size)
{
	for(size_t i = 0; i < size; i++)
		printf("%d ", array[i]);
	puts("");
}

void swap(int array[], size_t a, size_t b)
{
	array[a] = array[a] ^ array[b];
	array[b] = array[a] ^ array[b];
	array[a] = array[a] ^ array[b];
}

size_t find_minimum(const int array[], size_t size)
{
	if(size == 1)
		return 0;

	size_t min = 1 + find_minimum(array + 1, size - 1);
	if(array[0] < array[min]) return 0;
	else return min;
}

size_t find_maximum(const int array[], size_t size)
{
	if(size == 1)
		return 0;

	size_t max = 1 + find_maximum(array + 1, size - 1);
	if(array[0] > array[max]) return 0;
	else return max;
}

void selection_sort_recursive(int array[], size_t size)
{
	if(size == 1)
		return;

	size_t min = 1 + find_minimum(array + 1, size - 1);
	if(array[min] < array[0]) swap(array, 0, min);
	selection_sort_recursive(array + 1, size - 1);
}
