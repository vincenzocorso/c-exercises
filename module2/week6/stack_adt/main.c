#include <stdio.h>
#include "stackitem.h"
#include "stack.h"

int main()
{
	stack_init();
	
	for(int i = 1; i <= 10; i++)
		stack_push(i);

	for(int i = 1; i <= 11; i++)
		printf("pop: %d\n", stack_pop());
	
	stack_free();
	
	return 0;
}
