#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

struct Node
{
	Item value;
	struct Node *next;
};
typedef struct Node node_t;
typedef node_t *node_ptr;

static size_t size;
static Item stack[MAXN];

int is_stack_empty()
{
	return size == 0;
}

void stack_push(Item value)
{
	if(size != MAXN)
		stack[size++] = value;
	else
		puts("ERROR: Stack is full.");
}

Item stack_pop()
{
	if(!is_stack_empty())
		return stack[--size];
	else puts("ERROR: Stack is empty.");
	
	return ITEM_NULL;
}

void stack_print()
{
	for(int i = size-1; i >= 0; i--)
	{
		print_item(stack[i]);
		printf(" --> ");
	}
	puts("");
}

int is_present(Item value)
{
	for(int i = size-1; i >= 0; i--)
		if(stack[i] == value)
			return 1;
	
	return 0;
}
