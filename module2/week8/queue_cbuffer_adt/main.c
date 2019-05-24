#include <stdio.h>
#include "queueitem.h"
#include "queue.h"

int main()
{
	queue q = queue_init(4);
	
	puts("enqueue:");
	for(int i = 1; i <= 10; i++)
	{
		queue_enqueue(q, i);
		print_queueitem(i);
		puts("");
	}
	
	queueitem item;
	puts("\ndequeue:");
	for(int i = 1; i <= 11; i++)
	{
		item = queue_dequeue(q);
		print_queueitem(item);
		puts("");
	}
	
	queue_free(q);
}
