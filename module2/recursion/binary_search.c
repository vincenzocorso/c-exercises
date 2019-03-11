#include <stdio.h>

#define SIZE	5

int binary_search_iterative(const int array[], size_t size, int key);
int binary_search_recursive(const int array[], int a, int b, int key);

int main()
{
	int array[SIZE] = {-6, 5, 9, 11, 24};

	puts("Binary search iterative:");
	printf("%d --> %d\n", 5, binary_search_iterative(array, SIZE, 5));
	printf("%d --> %d\n", 24, binary_search_iterative(array, SIZE, 24));
	printf("%d --> %d\n", -18, binary_search_iterative(array, SIZE, -18));
	printf("%d --> %d\n", 15, binary_search_iterative(array, SIZE, 15));

	puts("\nBinary search recursive:");
	printf("%d --> %d\n", 5, binary_search_recursive(array, 0, SIZE - 1, 5));
	printf("%d --> %d\n", 24, binary_search_recursive(array, 0, SIZE - 1, 24));
	printf("%d --> %d\n", -18, binary_search_recursive(array, 0, SIZE - 1, -18));
	printf("%d --> %d\n", 15, binary_search_recursive(array, 0, SIZE - 1, 15));

	return 0;
}

int binary_search_iterative(const int array[], size_t size, int key)
{
	int left = 0, right = size - 1, middle;

	while(left <= right)
	{
		middle = (left + right) / 2;
		if(key > array[middle])
			left = middle + 1;
		else if(key < array[middle])
			right = middle - 1;
		else return middle;
	}

	return -1;
}

int binary_search_recursive(const int array[], int a, int b, int key)
{
	if(a > b)
		return -1;

	size_t middle = (a + b) / 2;
	if(key > array[middle])
		binary_search_recursive(array, middle + 1, b, key);
	else if(key < array[middle])
		binary_search_recursive(array, a, middle - 1, key);
	else return middle;
}
