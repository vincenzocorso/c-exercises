#ifndef STACK_H
#define STACK_H

#include "stackitem.h"

typedef struct stack *stack;

stack stack_init();
int is_stack_empty(stack);
void stack_push(stack *, stackitem);
stackitem stack_pop(stack *);
stackitem stack_peek(stack s);
void stack_free(stack);

#endif
