#include <stdio.h>
#include "stackitem.h"

void print_stackitem(stackitem item)
{
	printf("%d", item);
}

stackitem scan_stackitem()
{
	stackitem item;
	scanf("%d", &item);
	return item;
}
