#ifndef QUEUE_H
#define QUEUE_H

#include "queueitem.h"

typedef struct queue *queue; // handle

queue queue_init();
int is_queue_empty(queue);
void queue_enqueue(queue, queueitem);
queueitem queue_dequeue(queue);
void queue_print(queue);
void queue_free(queue);

#endif
