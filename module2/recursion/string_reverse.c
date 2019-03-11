#include <stdio.h>

#define SIZE	5

void print_reverse(const char * const sPtr);
void reverse(char string[], size_t a, size_t b);

int main()
{
	char string[SIZE] = "ciao";

	puts("print_reverse: ");
	printf("%s -> ", string);
	print_reverse(string);

	puts("\n\nreverse: ");
	printf("%s -> ", string);
	reverse(string, 0, SIZE - 2);
	printf("%s\n", string);

	return 0;
}

void print_reverse(const char * const sPtr)
{
	if(*sPtr == '\0')
		return;

	print_reverse(sPtr + 1);
	putchar(*sPtr);
}

void reverse(char string[], size_t a, size_t b)
{
	if(a >= b)
		return;

	char temp = string[a];
	string[a] = string[b];
	string[b] = temp;
	reverse(string, a + 1, b - 1);
}
