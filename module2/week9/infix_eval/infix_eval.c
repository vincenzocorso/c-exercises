#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackitem.h"
#include "stack.h"

int is_operator(char c);
int precedence(char a, char b);
char *infix_to_postfix(char *infix);
int postfix_eval(char *postfix);
int infix_eval(char *infix);

int main()
{
	char infix[50] = "(2*4/2+6-3*2)+3*6";
	char *postfix = infix_to_postfix(infix);

	printf("infix: %s\npostfix: %s\n", infix, postfix);

	int result = infix_eval(infix);
	printf("%s = %d\n", infix, result);
	
	free(postfix);

	return 0;
}

int is_operator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

/* return 1 if operator a have higher or equal priority of operator b, 0 otherwise */
int precedence(char a, char b)
{
	if(a == b) return 1;

	if(a == '+') return 0;
	else if(a == '-')
	{
		if(b == '+') return 1;
		else return 0;
	}
	else if(a == '*')
	{
		if(b == '/') return 0;
		else return 1;
	}
	else return 1;
}

char *infix_to_postfix(char *infix)
{
	char *postfix = malloc(150 * sizeof(char));
	postfix[0] = '\0';
	char a[100];
	strcpy(a, infix);

	int i = 0, j = 0;

	stack operatori = stack_init();
	stack_push(&operatori, (stackitem)('('));
	strcat(a, ")");
	while(!is_stack_empty(operatori))
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			postfix[j] = a[i];
			postfix[++j] = '\0';
		}
		else if(a[i] == '(')
			stack_push(&operatori, (stackitem)(a[i]));
		else if(is_operator(a[i]))
		{
			while(is_operator(stack_peek(operatori).c) && precedence(stack_peek(operatori).c, a[i]))
			{
				postfix[j] = ' ';
				postfix[++j] = stack_pop(&operatori).c;
				postfix[++j] = '\0';
			}
			postfix[j] = ' ';
			postfix[++j] = '\0';
			stack_push(&operatori, (stackitem)(a[i]));
		}
		else if(a[i] == ')')
		{
			while(is_operator(stack_peek(operatori).c))
			{
				postfix[j] = ' ';
				postfix[++j] = stack_pop(&operatori).c;
				postfix[++j] = '\0';
			}

			if(stack_peek(operatori).c == '(')
				stack_pop(&operatori);
		}
		i++;
	}
	stack_free(operatori);
	
	return postfix;
}

int postfix_eval(char *postfix)
{
	stack operandi = stack_init();
	
	for(int i = 0; postfix[i] != '\0'; i++)
	{
		if(postfix[i] == '/')
		{
			int b = stack_pop(&operandi).i;
			int a = stack_pop(&operandi).i;
			stack_push(&operandi, (stackitem)(a / b));
		}
		else if(postfix[i] == '*')
			stack_push(&operandi, (stackitem)(stack_pop(&operandi).i * stack_pop(&operandi).i));
		else if(postfix[i] == '-')
		{
			int b = stack_pop(&operandi).i;
			int a = stack_pop(&operandi).i;
			stack_push(&operandi, (stackitem)(a - b));
		}
		else if(postfix[i] == '+')
			stack_push(&operandi, (stackitem)(stack_pop(&operandi).i + stack_pop(&operandi).i));
		else if(postfix[i] >= '0' && postfix[i] <= '9')
		{
			int number = 0;
			while(postfix[i] >= '0' && postfix[i] <= '9')
				number = number * 10 + postfix[i++] - '0';
			
			stack_push(&operandi, (stackitem)(number));
		}
	}
	
	int result = stack_pop(&operandi).i;
	stack_free(operandi);
	return result;
}

int infix_eval(char *infix)
{
	char *postfix = infix_to_postfix(infix);
	int result = postfix_eval(postfix);
	free(postfix);

	return result;
}
