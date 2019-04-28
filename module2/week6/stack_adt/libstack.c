#include <stdio.h>
#include <stdlib.h>
#include "stackitem.h"
#include "stack.h"

struct stack_node
{
	stackitem item;
	struct stack_node *next;
};
typedef struct stack_node stack_node_t;
typedef stack_node_t *stack_node_ptr;

static stack_node_ptr top;

void stack_init()
{
	top = NULL;
}

int is_stack_empty()
{
	return top == NULL;
}

void stack_push(stackitem item)
{
	stack_node_ptr new_node = malloc(sizeof(stack_node_t));
	if(new_node != NULL)
	{
		new_node->item = item;
		new_node->next = top;
		top = new_node;
	}
	else puts("STACK ERROR: Can't allocate more memory.");
}

stackitem stack_pop()
{
	if(!is_stack_empty())
	{
		stack_node_ptr temp_node = top;
		top = top->next;
		stackitem item = temp_node->item;
		free(temp_node);
		return item;
	}
	else puts("STACK ERROR: Stack is empty.");
	return STACK_NULL_ITEM;
}

void stack_free()
{
	stack_node_ptr temp_ptr;
	while(top != NULL)
	{
		temp_ptr = top;
		top = top->next;
		free(temp_ptr);
	}
}
