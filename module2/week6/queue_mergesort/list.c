#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"

void queue_mergesort(node_ptr *list);
node_ptr merge(node_ptr list1, node_ptr list2);

void insert_head(node_ptr *list, int value);
void delete(node_ptr *list, int value);
void print_list(node_ptr list);
void free_list(node_ptr *list);

void print_reverse_list(node_ptr list);
node_ptr search_list(node_ptr list, int value);

int main()
{
	srand(time(NULL));

	node_ptr list = NULL;
	for(int i = 0; i < 10; i++)
		insert_head(&list, rand() % 11);
	
	print_list(list);
	queue_mergesort(&list);
	print_list(list);
	
	free_list(&list);

	return 0;
}

void queue_mergesort(node_ptr *list)
{
	queue_init();
	
	node_ptr temp_ptr, current_ptr = *list;
	while(current_ptr != NULL)
	{
		temp_ptr = current_ptr;
		current_ptr = current_ptr->next;
		temp_ptr->next = NULL;
		enqueue(temp_ptr);
	}
	
	Item a = dequeue();
	while(!is_queue_empty())
	{
		enqueue(a);
		a = merge(dequeue(), dequeue());
	}
	
	queue_free();
	*list = a;
}

node_ptr merge(node_ptr list1, node_ptr list2)
{
	node_t temp;
	node_ptr result = &temp;

	node_ptr l1 = list1, l2 = list2, r = result;
	while(l1 != NULL && l2 != NULL)
	{
		if(l1->value < l2->value)
		{
			r->next = l1;
			l1 = l1->next;
		}
		else
		{
			r->next = l2;
			l2 = l2->next;
		}
		
		r = r->next;
		r->next = NULL;
	}
	
	r->next = (l1 != NULL) ? l1 : l2;
	
	return result->next;
}

void insert_head(node_ptr *list, int value)
{
	node_ptr new_node = malloc(sizeof(node_t));
	if(new_node != NULL)
	{
		new_node->value = value;
		new_node->next = *list;
		*list = new_node;
	}
}

void delete(node_ptr *list, int value)
{
	node_ptr previous_ptr = NULL;
	node_ptr current_ptr = *list;
	
	while(current_ptr != NULL && current_ptr->value != value)
	{
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next;
	}
	
	if(current_ptr != NULL)
	{
		if(previous_ptr != NULL)
			previous_ptr->next = current_ptr->next;
		else
			*list = current_ptr->next;
		
		free(current_ptr);
	}
	else puts("ERROR: List empty or node not found.");
}

void print_list(node_ptr list)
{
	node_ptr current_ptr = list;
	while(current_ptr != NULL)
	{
		printf("%d --> ", current_ptr->value);
		current_ptr = current_ptr->next;
	}
	puts("");
}

void free_list(node_ptr *list)
{
	node_ptr previous_ptr = NULL;
	node_ptr current_ptr = *list;
	
	while(current_ptr != NULL)
	{
		previous_ptr = current_ptr;
		current_ptr = current_ptr->next;
		free(previous_ptr);
	}
}

void print_reverse_list(node_ptr list)
{
	if(list == NULL)
		return;
		
	print_reverse_list(list->next);
	printf("%d <-- ", list->value);
}

node_ptr search_list(node_ptr list, int value)
{
	if(list == NULL)
		return NULL;
	if(list->value == value)
		return list;

	return search_list(list->next, value);
}
