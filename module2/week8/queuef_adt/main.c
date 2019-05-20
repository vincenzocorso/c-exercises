#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queueitem.h"
#include "queue.h"

int main()
{
	queue q = queue_init(0);
	
	for(int i = 1; i <= 10; i++)
		queue_enqueue(q, i);

	queue_print(q);

	queueitem item;
	for(int i = 1; i <= 11; i++)
	{
		item = queue_dequeue(q);
		print_queueitem(item);
		printf(" ");
	}
	puts("");

	queue_free(q);

	return 0;
}
