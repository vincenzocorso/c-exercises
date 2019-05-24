#include <stdio.h>
#include "queueitem.h"

void print_queueitem(queueitem item)
{
	printf("%d", item);
}

queueitem scan_queueitem()
{
	queueitem item;
	scanf("%d", &item);
	return item;
}
