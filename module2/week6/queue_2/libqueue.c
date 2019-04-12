#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

static Item *queue;
static int size;
static int MAXN = 2;
static int head, tail;

static void resize(int newsize)
{
	Item *newqueue = malloc(newsize * sizeof(Item));
	for(size_t j = 0, i = head; j < size; j++, i = (i+1) % MAXN)
		newqueue[j] = queue[i];

	head = 0;
	tail = size;
	MAXN = newsize;
	
	free(queue);
	queue = newqueue;
}

void queue_init()
{
	queue = malloc(MAXN * sizeof(Item));
	tail = head = 0;
}

int is_queue_empty()
{
	return size == 0;
}

void enqueue(Item value)
{
	if(size >= 0.7 * MAXN)
	{
		resize(MAXN * 2);
		printf("Debug size: %d  | MAXN: %d\n", size, MAXN);	
	}
	
	queue[tail] = value;
	tail = (tail+1) % MAXN;
	size++;
}

Item dequeue()
{
	if(size != 0)
	{
		if(size >= MAXN/4 && size < MAXN / 2)
		{
			resize(MAXN / 2);
			printf("Debug size: %d  | MAXN: %d\n", size, MAXN);
		}

		Item value = queue[head];
		head = (head+1) % MAXN;
		size--;
		
		return value;
	}
	else puts("ERROR: Queue is empty.");
	
	return ITEM_NULL;
}

void queue_print()
{
	for(size_t j = 0, i = head; j < size; j++, i = (i+1) % MAXN)
	{
		print_item(queue[i]);
		printf(" <-- ");	
	}
	puts("");
}

int is_present(Item value)
{
	for(size_t j = 0, i = head; j < size; j++, i = (i+1) % MAXN)
		if(eq(queue[i], value))
			return 1;

	return 0; 
}

void queue_free()
{
	free(queue);
	queue = NULL;
}
