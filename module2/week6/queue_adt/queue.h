#ifndef QUEUE_H
#define QUEUE_H

#include "queueitem.h"

void queue_init();
int is_queue_empty();
void queue_enqueue(queueitem item);
queueitem queue_dequeue();
void queue_free();

#endif
