#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS		5
#define MAX_VALUE	10
#define MAX_WEIGHT	15

typedef struct {
	unsigned int value;
	unsigned int weight;
} item_t;

void print_items(const item_t *list, size_t nitems);
int knapsack(const item_t *list, size_t nitems, unsigned int maxweight);
int max(int a, int b);

int main()
{
	srand(time(NULL));

	item_t list[ITEMS];
	for(size_t i = 0; i < ITEMS; i++)
	{
		list[i].value = rand() % MAX_VALUE + 1;
		list[i].weight = rand() % MAX_WEIGHT + 1;
	}

	print_items(list, ITEMS);
	printf("Max: %d\n", knapsack(list, ITEMS, 10));

	return 0;
}

void print_items(const item_t *list, size_t nitems)
{
	puts("itemid\tvalue\tweight");
	for(size_t i = 0; i < nitems; i++)
		printf("%u\t%d\t%d\n", i, list[i].value, list[i].weight);
	puts("");
}

int knapsack(const item_t *list, size_t nitems, unsigned int maxweight)
{
	if(nitems == 0 || maxweight == 0)
		return 0;

	if(list[nitems-1].weight <= maxweight)
		return max(knapsack(list, nitems-1, maxweight - list[nitems-1].weight) + list[nitems-1].value, knapsack(list, nitems-1, maxweight));
	else
		return knapsack(list, nitems-1, maxweight);
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}
