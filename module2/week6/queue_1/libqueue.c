#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

struct Node
{
	Item value;
	struct Node *next;
};
typedef struct Node node_t;
typedef node_t *node_ptr;

static node_ptr head;
static node_ptr tail;

void queue_init()
{
	tail = head = NULL;
}

int is_queue_empty()
{
	return head == NULL;
}

void enqueue(Item value)
{
	node_ptr new_node = malloc(sizeof(node_t));
	if(new_node != NULL)
	{
		new_node->value = value;
		new_node->next = NULL;
		
		if(is_queue_empty())
			head = tail = new_node;
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
	}
	else puts("ERROR: Can't create a new node.");
}

Item dequeue()
{
	if(!is_queue_empty())
	{
		node_ptr temp_ptr = head;
		head = head->next;
		Item value = temp_ptr->value;
		free(temp_ptr);
		
		if(is_queue_empty())
			tail = NULL;
		
		return value;
	}
	else puts("ERROR: Queue is empty.");
	
	return ITEM_NULL;
}

void queue_print()
{
	node_ptr current_ptr = head;
	while(current_ptr != NULL)
	{
		print_item(current_ptr->value);
		printf(" <-- ");
		current_ptr = current_ptr->next;
	}
	puts("");
}

int is_present(Item value)
{
	for(node_ptr current_ptr = head; current_ptr != NULL; current_ptr = current_ptr->next)
		if(eq(current_ptr->value, value))
			return 1;

	return 0; 
}

void queue_free()
{
	node_ptr current_ptr = head, previous_ptr = NULL;
	while(current_ptr != NULL)
	{
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next,
		free(previous_ptr);
	}
	
	head = tail = NULL;
}
