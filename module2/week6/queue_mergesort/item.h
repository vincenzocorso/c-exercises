#ifndef ITEM_H
#define ITEM_H

struct Node
{
	int value;
	struct Node *next;
};
typedef struct Node node_t;
typedef node_t *node_ptr;

typedef node_ptr Item;

#define ITEM_NULL	NULL
#define eq(a,b)	((a) == (b))

Item scan_item();
void print_item(Item value);

#endif
