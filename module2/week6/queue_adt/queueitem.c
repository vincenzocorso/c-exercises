#include <stdio.h>
#include "queueitem.h"

queueitem scan_queueitem()
{
	queueitem item;
	scanf("%d", &item);
	return item;
}

void print_queueitem(queueitem item)
{
	printf("%d", item);
}
