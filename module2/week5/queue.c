#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node *next;
};
typedef struct Node node_t;
typedef node_t *node_ptr;

void enqueue(node_ptr *head, node_ptr *tail, int value);
void dequeue(node_ptr *head, node_ptr *tail);
void print_queue(node_ptr head);
void free_queue(node_ptr *head, node_ptr *tail);

int main()
{
	node_ptr head = NULL, tail = NULL;
	
	enqueue(&head, &tail, 10);
	enqueue(&head, &tail, 20);
	enqueue(&head, &tail, -50);
	enqueue(&head, &tail, 30);
	print_queue(head);
	
	dequeue(&head, &tail);
	dequeue(&head, &tail);
	print_queue(head);
	
	dequeue(&head, &tail);
	dequeue(&head, &tail);
	print_queue(head);
	
	free_queue(&head, &tail);

	return 0;
}

void enqueue(node_ptr *head, node_ptr *tail, int value)
{
	node_ptr new_node = malloc(sizeof(node_t));
	
	if(new_node != NULL)
	{
		new_node->value = value;
		new_node->next = NULL;
		
		if(*head == NULL)
			*head = new_node;
		else
			(*tail)->next = new_node;
		
		*tail = new_node;
	}
	else puts("ERROR: Can't create a new node.");
}

void dequeue(node_ptr *head, node_ptr *tail)
{
	if(*head != NULL)
	{
		node_ptr temp_ptr = *head;
		*head = (*head)->next;
		free(temp_ptr);
		
		if(*head == NULL)
		*tail = NULL;
	}
}

void print_queue(node_ptr head)
{
	node_ptr current_ptr = head;
	while(current_ptr != NULL)
	{
		printf("%d <-- ", current_ptr->value);
		current_ptr = current_ptr->next;
	}
	puts("");
}

void free_queue(node_ptr *head, node_ptr *tail)
{
	node_ptr current_ptr = *head, previous_ptr = NULL;
	while(current_ptr != NULL)
	{
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next;
		free(previous_ptr);
	}
	
	*head = *tail = NULL;
}
