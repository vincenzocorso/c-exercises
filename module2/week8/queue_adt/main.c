#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queueitem.h"
#include "queue.h"

int main()
{
	srand(time(NULL));

	queue queues[10];
	for(int i = 0; i < 10; i++)
		queues[i] = queue_init(4);
	
	for(int i = 1; i <= 100; i++)
		queue_enqueue(queues[rand() % 10], i);
	
	for(int i = 0; i < 10; i++)
		queue_print(queues[i]);
	
	for(int i = 0; i < 10; i++)
		queue_free(queues[i]);

	puts("\n");
	queue q = queue_init(4);
	for(int i = 0; i < 10; i++)
		queue_enqueue(q, i);
	
	queue_print(q);
	
	queueitem item;
	for(int i = 0; i < 10; i++)
	{
		item = queue_dequeue(q);
		printf("dequeue: ");
		print_queueitem(item);
		puts("");
	}
	queue_free(q);

	return 0;
}
