#ifndef STACK_H
#define STACK_H

#include "stackitem.h"

void stack_init();
int is_stack_empty();
void stack_push(stackitem item);
stackitem stack_pop();
void stack_free();

#endif
