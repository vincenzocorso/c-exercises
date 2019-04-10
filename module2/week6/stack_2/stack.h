#ifndef STACK_H
#define STACK_H

#include "item.h"

#define MAXN	10

int is_stack_empty();
void stack_push(Item value);
Item stack_pop();
void stack_print();
int is_present(Item value);

#endif
