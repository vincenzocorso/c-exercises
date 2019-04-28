#ifndef LIST_H
#define LIST_H

struct Node
{
	int value;
	struct Node *next;
};
typedef struct Node node_t;
typedef node_t *node_ptr;

void insert_head(node_ptr *list, int value);
void delete(node_ptr *list, int value);
void print_list(node_ptr list);
void free_list(node_ptr *list);

#endif
