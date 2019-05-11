#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(a,b)	((a) > (b)) ? (a) : (b)
#define BIT	8*sizeof(unsigned int)

#define ITEMS			5
#define MAX_KNAP		15
#define MAX_VALUE		12
#define MAX_WEIGHT		8

typedef struct Item
{
	int value;
	int weight;
} Item;

static int dptable[ITEMS+1][MAX_KNAP+1];
static unsigned int presence;

void print_items(const Item *list, int nitems);
void print_dptable();
int knapsack(const Item *list, int nitems, int maxweight);
void items_taken(const Item *list, int nitems, int maxweight);
void set_presence(int i);
void display_bit(int number);

int main()
{
	srand(time(NULL));

	Item list[ITEMS];
	for(int i = 0; i < ITEMS; i++)
	{
		list[i].value = rand() % MAX_VALUE + 1;
		list[i].weight = rand() % MAX_WEIGHT + 1;
	}
	
	print_items(list, ITEMS);
	printf("Max: %d\n", knapsack(list, ITEMS, 10));
	print_dptable();
	items_taken(list, ITEMS, 10);
	display_bit(presence);

	return 0;
}

void print_items(const Item *list, int nitems)
{
	puts("itemid\tvalue\tweight");
	for(int i = 0; i < nitems; i++)
		printf("%d\t%d\t%d\n", i, list[i].value, list[i].weight);
	puts("");
}

void print_dptable()
{
	for(int i = 0; i <= ITEMS; i++)
	{
		for(int j = 0; j <= MAX_KNAP; j++)
			printf("%3d ", dptable[i][j]);
		puts("");
	}
	puts("");
}

int knapsack(const Item *list, int nitems, int maxweight)
{
	for(int i = 0; i <= ITEMS; i++)
	{
		for(int w = 0; w <= maxweight; w++)
		{
			if(i == 0 || w == 0)
				dptable[i][w] = 0;
			else if(w < list[i-1].weight)
				dptable[i][w] = dptable[i-1][w];
			else
				dptable[i][w] = max(dptable[i-1][w - list[i-1].weight] + list[i-1].value, dptable[i-1][w]);
		}
	}
	
	return dptable[ITEMS][maxweight];
}

void items_taken(const Item *list, int nitems, int maxweight)
{
	printf("Items taken: ");
	int j = maxweight;
	for(int i = ITEMS; i >= 1; i--)
	{
		if(dptable[i][j] != dptable[i-1][j])
		{
			printf("%d ", i-1);
			set_presence(i-1);
			j -= list[i-1].weight;
		}
	}
	puts("");
}

void set_presence(int i)
{
	int mask = 1 << BIT - i - 1;
	presence |= mask;
}

void display_bit(int number)
{
	unsigned int mask = 1 << BIT - 1;
	for(int i = 1; i <= BIT; i++)
	{
		putchar(number & mask ? '1' : '0');
		if(i % 8 == 0) printf(" ");
		number <<= 1;
	}
	puts("");
}
