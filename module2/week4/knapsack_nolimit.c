#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS			4
#define MAX_VALUE		8
#define MAX_WEIGHT		8
#define MAX_KNAP		15

#define max(a,b) ((a) > (b)) ? (a) : (b)

typedef struct
{
	int value;
	int weight;
} item_t;

void print_items(item_t list[], size_t nitems);
int knapsack(item_t list[], size_t nitems, int maxweight);

static int dptable[MAX_KNAP];

int main()
{
	srand(time(NULL));

	item_t list[ITEMS];
	for(size_t i = 0; i < ITEMS; i++)
	{
		list[i].value = 1 + rand() % MAX_VALUE;
		list[i].weight = 1 + rand() % MAX_WEIGHT;
	}
	
	print_items(list, ITEMS);
	printf("Max: %d\n", knapsack(list, ITEMS, 10));
	
	puts("dptable:");
	for(size_t i = 0; i < MAX_KNAP; i++)
		printf("%d ", dptable[i]);
	puts("");

	return 0;
}

void print_items(item_t list[], size_t nitems)
{
	puts("itemid\tvalue\tweight");
	for(size_t i = 0; i < nitems; i++)
		printf("%d\t%d\t%d\n", i, list[i].value, list[i].weight);
	puts("");
}

int knapsack(item_t list[], size_t nitems, int maxweight)
{
	for(int w = 0; w <= maxweight; w++)
		for(int i = 0; i < nitems; i++)
			if(list[i].weight <= w)
				dptable[w] = max(dptable[w], dptable[w-list[i].weight] + list[i].value);
	
	return dptable[maxweight];
}
