#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "queueitem.h"
#include "queue.h"

void list_mergesort(node_ptr *list);
node_ptr merge(node_ptr list1, node_ptr list2);

int main()
{
	srand(time(NULL));

	node_ptr list = NULL;
	
	for(int i = 1; i <= 10; i++)
		insert_head(&list, rand() % 21);
	
	print_list(list);
	list_mergesort(&list);
	print_list(list);
	
	free_list(&list);

	return 0;
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

void list_mergesort(node_ptr *list)
{
	queue_init();
	
	node_ptr temp_ptr = NULL, current_ptr = *list;
	while(current_ptr != NULL)
	{
		temp_ptr = current_ptr;
		current_ptr = current_ptr->next;
		temp_ptr->next = NULL;
		queue_enqueue(temp_ptr);
	}
	
	queueitem t = queue_dequeue();
	while(!is_queue_empty())
	{
		queue_enqueue(t);
		t = merge(queue_dequeue(), queue_dequeue());
	}
	
	*list = t;
	queue_free();
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
