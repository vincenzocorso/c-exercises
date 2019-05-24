#include <stdio.h>
#include <stdlib.h>
#include "stackitem.h"
#include "stack.h"

struct stack
{
	stackitem item;
	struct stack *next;
};

stack stack_init()
{
	return NULL;
}

int is_stack_empty(stack s)
{
	return s == NULL;
}

void stack_push(stack *s, stackitem item)
{
	stack new_ptr = malloc(sizeof(struct stack));
	if(new_ptr != NULL)
	{
		new_ptr->item = item;
		new_ptr->next = *s;
		*s = new_ptr;
	}
	else puts("ERROR: Can't create a new node.");
}

stackitem stack_pop(stack *s)
{
	if(!is_stack_empty(*s))
	{
		stack temp_ptr = *s;
		*s = (*s)->next;
		stackitem item = temp_ptr->item;
		free(temp_ptr);
		return item;
	}

	return STACKITEM_NULL;
}

stackitem stack_peek(stack s)
{
	return s->item;
}

void stack_free(stack s)
{
	stack previous_ptr = NULL, current_ptr = s;
	while(current_ptr != NULL)
	{
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next;
		free(previous_ptr);
	}
}
