#ifndef ITEM_H
#define ITEM_H

#include "item.h"

void queue_init();
int is_queue_empty();
void enqueue(Item value);
Item dequeue();
void queue_print();
int is_present(Item value);
void queue_free();

#endif
