#ifndef QUEUE_H
#define QUEUE_H

#include "queueitem.h"
#include "queue.h"

typedef struct queue *queue; // handle

queue queue_init(int);
int is_queue_empty(queue);
void queue_enqueue(queue, queueitem);
queueitem queue_dequeue(queue);
void queue_free(queue);

#endif
