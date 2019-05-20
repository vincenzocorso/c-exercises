#include <stdio.h>
#include <stdlib.h>
#include "queueitem.h"
#include "queue.h"

struct queue
{
	char filename[50];
	FILE *file;
};

queue queue_init(int maxn)
{
	queue q = malloc(sizeof(struct queue));
	if(q != NULL)
	{
		q->file = NULL;
		sprintf(q->filename, "queue_%p.dat", q);
	}
	
	return q;
}

int is_queue_empty(queue q)
{
	return q->file == NULL;
}

void queue_enqueue(queue q, queueitem item)
{
	q->file = fopen(q->filename, "rb+");
	if(q->file == NULL) q->file = fopen(q->filename, "wb");
	
	if(q->file != NULL)
	{
		fseek(q->file, 0, SEEK_END);
		fwrite(&item, sizeof(queueitem), 1, q->file);
		fclose(q->file);
	}
	else puts("ERROR: Can't open queue file.");
}

queueitem queue_dequeue(queue q)
{
	if(!is_queue_empty(q))
	{
		q->file = fopen(q->filename, "rb+");
	
		fseek(q->file, 0, SEEK_END);
		int num = ftell(q->file) / sizeof(queueitem);

		queueitem item;
		fseek(q->file, 0, SEEK_SET);
		fread(&item, sizeof(queueitem), 1, q->file);
		
		queueitem items[num-1];
		fread(items, sizeof(queueitem), num-1, q->file);
		
		q->file = freopen(q->filename, "wb", q->file);
		fwrite(items, sizeof(queueitem), num-1, q->file);
		
		fclose(q->file);
		
		if(num - 1 == 0)
			q->file = NULL;
		
		return item;
	}
	
	return QUEUE_NULL_ITEM;
}

void queue_print(queue q)
{
	if(!is_queue_empty(q))
	{
		q->file = fopen(q->filename, "rb+");
		queueitem item;
		while(fread(&item, sizeof(queueitem), 1, q->file))
		{
			print_queueitem(item);
			printf(" --> ");
		}
		puts("");
		
		fclose(q->file);
	}
}

void queue_free(queue q)
{
	remove(q->filename);
	free(q);
}
