#include <stdio.h>
#include "queueitem.h"
#include "queue.h"

int main()
{
	queue_init();
	
	for(int i = 1; i <= 10; i++)
		queue_enqueue(i);
	
	for(int i = 1; i <= 11; i++)
		printf("dequeue: %d\n", queue_dequeue());
	
	queue_free();
	
	return 0;
}
