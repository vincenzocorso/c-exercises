#include <stdio.h>
#include <stdlib.h>
#include "queueitem.h"

struct queue_node
{
	queueitem item;
	struct queue_node *next;
};
typedef struct queue_node queue_node_t;
typedef queue_node_t *queue_node_ptr;

static queue_node_ptr head, tail;

void queue_init()
{
	head = tail = NULL;
}

int is_queue_empty()
{
	return head == NULL;
}

void queue_enqueue(queueitem item)
{
	queue_node_ptr new_node = malloc(sizeof(queue_node_t));
	if(new_node != NULL)
	{
		new_node->item = item;
		new_node->next = NULL;
		
		if(head == NULL)
			head = tail = new_node;
		else
		{
			tail->next = new_node;
			tail = tail->next;
		}
	}
	else puts("QUEUE ERROR: Can't allocate more memory.");
}

queueitem queue_dequeue()
{
	if(!is_queue_empty())
	{
		queue_node_ptr temp_ptr = head;
		head = head->next;
		queueitem item = temp_ptr->item;
		free(temp_ptr);
		
		if(is_queue_empty())
			tail = NULL;
		
		return item;
	}
	else puts("QUEUE ERROR: Queue is empty.");
	return QUEUE_NULL_ITEM;
}

void queue_free()
{
	queue_node_ptr temp_node;
	while(head != NULL)
	{
		temp_node = head;
		head = head->next;
		free(temp_node);
	}
}
