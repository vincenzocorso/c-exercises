#include <stdio.h>
#include <stdlib.h>
#include "queueitem.h"
#include "queue.h"

struct queue
{
	int maxn;
	char filename[50];
	FILE *file;
	int size;
	int head;
	int tail;
};

queue queue_init(int maxn)
{
	queue q = malloc(sizeof(struct queue));
	q->maxn = maxn;
	sprintf(q->filename, "queue_%p.dat", q);
	q->file = NULL;
	q->size = q->head = q->tail = 0;
	return q; 
}

int is_queue_empty(queue q)
{
	return q->size == 0;
}

void _queue_resize(queue q, int maxn)
{
	q->file = fopen(q->filename, "rb+");
	if(q->file != NULL)
	{
		queueitem items[q->size];
		for(int i = q->head, j = 0; j < q->size; i = (i+1) % q->maxn, j++)
		{
			fseek(q->file, i * sizeof(queueitem), SEEK_SET);
			fread(&items[j], sizeof(queueitem), 1, q->file);
		}
		
		q->file = freopen(q->filename, "wb", q->file);
		fwrite(items, sizeof(queueitem), q->size, q->file);
		
		q->maxn = maxn;
		q->head = 0;
		q->tail = q->size;
		fclose(q->file);
		printf("WARNING: resized to %d\n", maxn);	
	}
}

void queue_enqueue(queue q, queueitem item)
{
	if(q->size >= 1.0 * q->maxn)
		_queue_resize(q, 2 * q->maxn);
	
	q->file = fopen(q->filename, "rb+");
	if(q->file == NULL) q->file = fopen(q->filename, "wb");
	
	if(q->file != NULL)
	{
		fseek(q->file, q->tail * sizeof(queueitem), SEEK_SET);
		fwrite(&item, sizeof(queueitem), 1, q->file);
		q->tail = (q->tail + 1) % q->maxn;
		(q->size)++;
		fclose(q->file);
	}
}

queueitem queue_dequeue(queue q)
{
	if(!is_queue_empty(q))
	{
		if(q->size < 0.5 * q->maxn)
			_queue_resize(q, q->maxn / 2);

		q->file = fopen(q->filename, "rb+");
		if(q->file == NULL) q->file = fopen(q->filename, "wb");
		
		if(q->file != NULL)
		{
			queueitem item;
			fseek(q->file, q->head * sizeof(queueitem), SEEK_SET);
			fread(&item, sizeof(queueitem), 1, q->file);
			q->head = (q->head + 1) % q->maxn;
			(q->size)--;
			fclose(q->file);
			return item;
		}
	}
	
	return QUEUEITEM_NULL;
}

void queue_free(queue q)
{
	remove(q->filename);
	free(q);
}
