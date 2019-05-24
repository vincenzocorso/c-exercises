#ifndef STACKITEM_H
#define STACKITEM_H

#ifndef ITEM
#define ITEM
typedef union
{
	int i;
	char c;
} stackitem;
#endif

#define STACKITEM_NULL	(stackitem)(-1)

void print_stackitem(stackitem);
stackitem scan_stackitem();

#endif
