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

static node_ptr stack;

void stack_init()
{
	stack = NULL;
}

int is_stack_empty()
{
	return stack == NULL;
}

void stack_push(Item value)
{
	node_ptr new_node = malloc(sizeof(node_t));
	if(new_node != NULL)
	{
		new_node->value = value;
		new_node->next = stack;
		stack = new_node;
	}
}

Item stack_pop()
{
	if(!is_stack_empty())
	{
		node_ptr temp_ptr = stack;
		stack = stack->next;
		Item value = temp_ptr->value;
		free(temp_ptr);
		return value;
	}
	else puts("ERROR: Stack is empty.");
	
	return ITEM_NULL;
}

void stack_print()
{
	node_ptr current_ptr = stack;
	while(current_ptr != NULL)
	{
		print_item(current_ptr->value);
		printf(" --> ");
		current_ptr = current_ptr->next;
	}
	puts("");
}

int is_present(Item value)
{
	node_ptr current_ptr = stack;
	while(current_ptr != NULL)
	{
		if(current_ptr->value == value)
			return 1;
	
		current_ptr = current_ptr->next;
	}
	
	return 0;
}

void stack_free()
{
	node_ptr previous_ptr = NULL, current_ptr = stack;
	while(current_ptr != NULL)
	{
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next;
		free(previous_ptr);
	}
	
	stack = NULL;
}
