#include <stdio.h>
#include <stdlib.h>
#include "bstitem.h"

bstitem scan_bstitem()
{
	bstitem item = malloc(100 * sizeof(char));
	scanf("%s", item);
	return item;
}

void print_bstitem(bstitem item)
{
	printf("%s", item);
}
