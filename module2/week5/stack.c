#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node *next;
};
typedef struct Node node_t;
typedef node_t *node_ptr;

void push(node_ptr *stack, int value);
void pop(node_ptr *stack);
void print_stack(node_ptr stack);
void free_stack(node_ptr *stack);

int main()
{
	node_ptr stack = NULL;

	push(&stack, 4);
	push(&stack, 3);
	push(&stack, 10);
	push(&stack, -520);
	print_stack(stack);
	
	pop(&stack);
	pop(&stack);
	print_stack(stack);
	
	pop(&stack);
	pop(&stack);
	print_stack(stack);

	free_stack(&stack);

	return 0;
}

void push(node_ptr *stack, int value)
{
	node_ptr new_node = malloc(sizeof(node_t));

	if(new_node != NULL)
	{
		new_node->value = value;
		new_node->next = *stack;
		*stack = new_node;
	}
	else puts("ERROR: Can't create a new node.");
}

void pop(node_ptr *stack)
{
	if(*stack != NULL)
	{
		node_ptr temp_ptr = *stack;
		*stack = (*stack)->next;
		free(temp_ptr);
	}
	else puts("ERROR: Stack is empty.");
}

void print_stack(node_ptr stack)
{
	node_ptr current_ptr = stack;
	while(current_ptr != NULL)
	{
		printf("%d <-- ", current_ptr->value);
		current_ptr = current_ptr->next;
	}
	puts("");
}

void free_stack(node_ptr *stack)
{
	node_ptr current_ptr = *stack, previous_ptr = NULL;
	while(current_ptr != NULL)
	{
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next;
		free(previous_ptr);
	}

	*stack = NULL;
}
