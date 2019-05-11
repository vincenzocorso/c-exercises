#include <stdio.h>
#include "bstitem.h"

bstitem scan_bstitem()
{
	bstitem item;
	scanf("%d", &item);
	return item;
}

void print_bstitem(bstitem item)
{
	printf("%d", item);
}
