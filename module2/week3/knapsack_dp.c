#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS		10
#define MAX_VALUE	10
#define MAX_WEIGHT	15

typedef struct {
	unsigned int value;
	unsigned int weight;
} item_t;

void print_items(const item_t *list, size_t nitems);
int knapsack(const item_t *list, size_t nitems, unsigned int maxweight);
void stampa_itemtrack(const item_t *list, size_t nitems, unsigned int maxweight, unsigned int maxvalue);
int max(int a, int b);

static unsigned int dptable[ITEMS][MAX_WEIGHT];

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
	unsigned int max = knapsack(list, ITEMS, 10);	

	printf("Max: %d\n", max);
	stampa_itemtrack(list, ITEMS, 10, max);

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

	if(list[nitems-1].weight > maxweight)
		return knapsack(list, nitems-1, maxweight);

	if(dptable[nitems-1][maxweight - list[nitems-1].weight] == 0)
		dptable[nitems-1][maxweight - list[nitems-1].weight] = knapsack(list, nitems-1, maxweight - list[nitems-1].weight);

	if(dptable[nitems-1][maxweight] == 0)
		dptable[nitems-1][maxweight] = knapsack(list, nitems-1, maxweight);

	return max(dptable[nitems-1][maxweight - list[nitems-1].weight] + list[nitems-1].value, dptable[nitems-1][maxweight]);
}

void stampa_itemtrack(const item_t *list, size_t nitems, unsigned int maxweight, unsigned int maxvalue)
{
	/* Stampa l'header */
	for(size_t i = 0; i < nitems; i++)
		printf("Item %d\t", i);
	puts("");

	/* Genera le combinazioni e stampa quelle ottime */
	for(unsigned int combination = 0; combination < pow(2, nitems); combination++)
	{
		unsigned int mask = 1, value = 0, weight = 0;

		for(unsigned int i = 0; i <= nitems - 1; i++, mask <<= 1)
		{
			if((combination & mask) >> i == 1)
			{
				value += list[nitems - 1 - i].value;
				weight += list[nitems - 1 - i].weight;
			}
		}

		if(value == maxvalue && weight <= maxweight)
		{
			mask = 1 << (nitems - 1);
			for(int i = nitems - 1; i >= 0; i--, mask >>= 1)
				printf("%4d\t", ((combination & mask) >> i == 1) ? 1 : 0);
			puts("");
		}
	}
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}
