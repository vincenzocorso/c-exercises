#include <stdio.h>
#include <stdlib.h>
#include "queueitem.h"
#include "queue.h"

typedef struct queue_node
{
	queueitem item;
	struct queue_node *next;
} queue_node;
typedef queue_node *queue_node_ptr;

struct queue
{
	queue_node_ptr head;
	queue_node_ptr tail;
};

queue queue_init(int maxn)
{
	queue q = malloc(sizeof(struct queue));
	if(q != NULL)
		q->head = q->tail = NULL;
	
	return q;
}

int is_queue_empty(queue q)
{
	return q->head == NULL;
}

void queue_enqueue(queue q, queueitem item)
{
	queue_node_ptr new_ptr = malloc(sizeof(queue_node));
	if(new_ptr != NULL)
	{
		new_ptr->item = item;
		new_ptr->next = NULL;
		
		if(is_queue_empty(q))
			q->head = new_ptr;
		else
			q->tail->next = new_ptr;
		
		q->tail = new_ptr;
	}
}

queueitem queue_dequeue(queue q)
{
	if(!is_queue_empty(q))
	{
		queue_node_ptr temp_ptr = q->head;
		q->head = q->head->next;
		queueitem item = temp_ptr->item;
		free(temp_ptr);
		
		if(is_queue_empty(q))
			q->tail = NULL;
		
		return item;
	}
	
	return QUEUE_NULL_ITEM;
}

void queue_print(queue q)
{
	queue_node_ptr current_ptr = q->head;
	while(current_ptr != NULL)
	{
		print_queueitem(current_ptr->item);
		printf(" <-- ");
		current_ptr = current_ptr->next;
	}
	puts("");
}

void queue_free(queue q)
{
	queue_node_ptr previous_ptr = NULL, current_ptr = q->head;
	while(current_ptr != NULL)
	{
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next;
		free(previous_ptr);
	}
	free(q);
}
