#include <stdio.h>
#include "item.h"

Item scan_item()
{
	Item value;
	scanf(ITEM_FORMAT_SPECIFIER, &value);
	return value;
}

void print_item(Item value)
{
	printf(ITEM_FORMAT_SPECIFIER, value);
}
