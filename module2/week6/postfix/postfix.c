#include <stdio.h>
#include "stackitem.h"
#include "stack.h"

int postfix(char expression[]);

int main()
{
	char expression[100];
	gets(expression);
	
	int result = postfix(expression);
	printf("Result: %d\n", result);

	return 0;
}

int postfix(char expression[])
{
	stack_init();
	
	for(int i = 0; expression[i] != '\0'; i++)
	{
		if(expression[i] == '+')
			stack_push(stack_pop() + stack_pop());
		else if(expression[i] == '*')
			stack_push(stack_pop() * stack_pop());
		else if(expression[i] >= '0' && expression[i] <= '9')
		{
			stack_push(expression[i++] - '0');
			while(expression[i] >= '0' && expression[i] <= '9')
				stack_push(stack_pop() * 10 + expression[i++] - '0');
			i--;
		}
	}
	
	int result = stack_pop();
	stack_free();
	
	return result;
}
