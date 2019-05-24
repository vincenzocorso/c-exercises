#include <stdio.h>
#include "stackitem.h"

void print_stackitem(stackitem item)
{
	printf("%d", item.i);
}

stackitem scan_stackitem()
{
	/*unused*/
	return STACKITEM_NULL;
}
