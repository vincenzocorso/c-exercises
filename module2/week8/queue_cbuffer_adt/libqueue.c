#include <stdio.h>
#include <stdlib.h>
#include "queueitem.h"
#include "queue.h"

struct queue
{
	int maxn;
	queueitem *items;
	int size;
	int head;
	int tail;
};

queue queue_init(int maxn)
{
	queue q = malloc(sizeof(struct queue));
	q->maxn = maxn;
	q->items = malloc(maxn * sizeof(queueitem));
	q->size = q->head = q->tail = 0;
	return q; 
}

int is_queue_empty(queue q)
{
	return q->size == 0;
}

void _queue_resize(queue q, int maxn)
{
	queueitem *resized = malloc(maxn * sizeof(queueitem));
	for(int i = q->head, j = 0; j < q->size; i = (i+1) % q->maxn, j++)
		resized[j] = q->items[i];

	free(q->items);
	q->items = resized;
	q->maxn = maxn;
	q->head = 0;
	q->tail = q->size;
	//printf("WARNING: resized to %d\n", maxn);
}

void queue_enqueue(queue q, queueitem item)
{
	if(q->size >= 1.0 * q->maxn)
		_queue_resize(q, 2 * q->maxn);
	
	q->items[q->tail] = item;
	q->tail = (q->tail + 1) % q->maxn;
	(q->size)++;
}

queueitem queue_dequeue(queue q)
{
	if(!is_queue_empty(q))
	{
		if(q->size < 0.5 * q->maxn)
			_queue_resize(q, q->maxn / 2);
		
		queueitem item = q->items[q->head];
		q->head = (q->head + 1) % q->maxn;
		(q->size)--;
		return item;
	}
	
	return QUEUEITEM_NULL;
}

void queue_free(queue q)
{
	free(q->items);
	free(q);
}
