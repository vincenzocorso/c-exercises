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

static int size;
static Item *stack;
static int MAXN = 5;

void stack_init()
{
	stack = malloc(MAXN * sizeof(Item));
}

int is_stack_empty()
{
	return size == 0;
}

void stack_push(Item value)
{
	if(size >= 0.7 * MAXN)
	{
		MAXN *= 2;
		Item *new_stack = malloc(MAXN * sizeof(Item));
		for(size_t i = 0; i < size; i++)
			new_stack[i] = stack[i];
		
		free(stack);
		stack = new_stack;
		
		printf("Debug size: %d  | MAXN: %d\n", size, MAXN);
	}
	
	stack[size++] = value;
}

Item stack_pop()
{
	if(!is_stack_empty())
	{
		if(size < MAXN / 2)
		{
			MAXN /= 2;
			Item *new_stack = malloc(MAXN * sizeof(Item));
			for(size_t i = 0; i < size; i++)
				new_stack[i] = stack[i];
			
			free(stack);
			stack = new_stack;
			
			printf("Debug size: %d  | MAXN: %d\n", size, MAXN);
		}
		
		return stack[--size];
	}
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

void stack_free()
{
	free(stack);
	size = 0;
	
	stack = NULL;
}
