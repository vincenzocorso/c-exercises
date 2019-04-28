#include <stdio.h>
#include "stackitem.h"

stackitem scan_stackitem()
{
	stackitem item;
	scanf("%d", &item);
	return item;
}

void print_stackitem(stackitem item)
{
	printf("%d", item);
}
