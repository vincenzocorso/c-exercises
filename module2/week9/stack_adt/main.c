#include <stdio.h>
#include "stackitem.h"
#include "stack.h"

int main()
{
	stack s = stack_init();
	
	printf("push: ");
	for(int i = 1; i <= 10; i++)
	{
		stack_push(&s, i);
		print_stackitem(i);
		printf(" ");
	}
	puts("");

	stackitem item;
	printf("pop: ");
	for(int i = 1; i <= 11; i++)
	{
		item = stack_pop(&s);
		print_stackitem(item);
		printf(" ");
	}
	puts("");

	stack_free(s);

	return 0;
}
