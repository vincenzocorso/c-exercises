#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
	int value;
	struct Node *next;
};
typedef struct Node node_t;
typedef node_t *node_ptr;

void insert_head(node_ptr *list, int value);
void print_list(node_ptr list);
void free_list(node_ptr *list);

void mergesort_list(node_ptr *list);
node_ptr merge(node_ptr list1, node_ptr list2);

int main()
{
	srand(time(NULL));

	node_ptr list = NULL;
	for(size_t i = 1; i <= 10; i++)
		insert_head(&list, rand() % 41);
		
	print_list(list);
	mergesort_list(&list);
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

void mergesort_list(node_ptr *list)
{
	/* Calcola il numero di elementi in un array */
	int size = 0;
	for(node_ptr temp_ptr = *list; temp_ptr != NULL; temp_ptr = temp_ptr->next)
		size++;
	
	/* Crea un array ausiliario di (size+1) elementi inizializzati a NULL */
	node_ptr array[size+1];
	for(size_t i = 0; i <= size; i++)
		array[i] = NULL;
	
	node_ptr current_ptr = *list, temp_ptr;
	size_t i;
	for(i = 0; i < size && current_ptr != NULL; i++)
	{
		array[i] = current_ptr;
		while(current_ptr->next != NULL && current_ptr->next->value > current_ptr->value)
			current_ptr = current_ptr->next;
		temp_ptr = current_ptr;
		current_ptr = current_ptr->next;
		temp_ptr->next = NULL;
	}

	for(int lim = i; lim > 1; lim = (lim + 1) / 2)
	{
		int j, k;
		for(j = k = 0; k < lim; j++, k += 2)
			array[j] = merge(array[k], array[k+1]);
		array[j] = NULL;
	}
	
	*list = array[0];
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
	r->next = (l1 == NULL) ? l2 : l1;
	
	return result->next;
}
