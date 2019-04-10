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

void insert(node_ptr *list, int value);
void delete(node_ptr *list, int value);
node_ptr search(node_ptr list, int value);
void print_list(node_ptr list);
void free_list(node_ptr *list);

void print_inverse_list(node_ptr list);
void insert_head(node_ptr *list, int value);
void mergesort_list(node_ptr *list);
node_ptr merge_list(node_ptr list1, node_ptr list2);

int main()
{
	srand(time(NULL));

	node_ptr list = NULL;
	for(int i = 1; i <= 6; i++)
		insert_head(&list, rand() % 101);

	print_list(list);
	mergesort_list(&list);
	print_list(list);

	return 0;
}

void insert(node_ptr *list, int value)
{
	node_ptr new_node = malloc(sizeof(node_t));
	
	if(new_node != NULL)
	{
		new_node->value = value;
		new_node->next = NULL;
	
		node_ptr previous_ptr = NULL;
		node_ptr current_ptr = *list;
		
		while(current_ptr != NULL && current_ptr->value < value)
		{
			previous_ptr = current_ptr;
			current_ptr = current_ptr->next;
		}
		
		/* Inserimento in testa */
		if(previous_ptr == NULL)
		{
			*list = new_node;
			new_node->next = current_ptr;
		}
		else
		{
			previous_ptr->next = new_node;
			new_node->next = current_ptr;
		}
	}
	else puts("ERROR: Can't create a new node");
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
		if(previous_ptr == NULL) /* Cancellazione in testa */
			*list = current_ptr->next;
		else
			previous_ptr->next = current_ptr->next;
		
		free(current_ptr);
	}
	else puts("ERROR: Node not found or list empty");
}

node_ptr search(node_ptr list, int value)
{
	node_ptr current_node = list;
	
	while(current_node != NULL && current_node->value != value)
		current_node = current_node->next;

	return (current_node != NULL) ? current_node : NULL;
}

void print_list(node_ptr list)
{
	node_ptr current_ptr = list;
	
	while(current_ptr != NULL)
	{
		printf("%3d --> ", current_ptr->value);
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
	
	/* Imposta il puntatore alla lista a NULL*/
	*list = NULL;
}

void print_inverse_list(node_ptr list)
{
	if(list == NULL)
		return;

	print_inverse_list(list->next);
	printf("%3d ", list->value);
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
	else puts("ERROR: Can't create a new node");
}

void mergesort_list(node_ptr *list)
{
	node_ptr temp_ptr = *list;
	size_t i, j;
	int size = 0;
	while(temp_ptr != NULL)
	{
		temp_ptr = temp_ptr->next;
		size++;
	}
	
	node_ptr array[size+1];
	temp_ptr = *list;
	for(i = 0; i < size; i++)
	{
		array[i] = temp_ptr;
		temp_ptr = temp_ptr->next;
		array[i]->next = NULL;
	}
	array[size] = NULL;
	
	for(size_t lim = size; lim > 1; lim = (lim + 1) / 2)
	{
		for(j = i = 0; i < lim; j++, i += 2)
			array[j] = merge_list(array[i], array[i+1]);

		array[j] = NULL;
	}
	
	*list = array[0];
}

node_ptr merge_list(node_ptr list1, node_ptr list2)
{
	if(list1 == NULL)
		return list2;
	else if(list2 == NULL)
		return list1;

	node_ptr result = NULL;
	node_ptr l1 = list1, l2 = list2, r = NULL;
	
	while(l1 != NULL && l2 != NULL)
	{
		node_ptr new_node = malloc(sizeof(node_t));
		
		if(new_node != NULL)
		{
			new_node->next = NULL;
			
			if(l1->value < l2->value)
			{
				new_node->value = l1->value;
				l1 = l1->next;
			}
			else
			{
				new_node->value = l2->value;
				l2 = l2->next;
			}
			
			if(r == NULL) result = r = new_node;
			else
			{
				r->next = new_node;
				r = r->next;
			}
		}
		else free_list(&result);
	}

	if(l1 != NULL)
	{
		while(l1 != NULL)
		{
			node_ptr new_node = malloc(sizeof(node_t));
		
			if(new_node != NULL)
			{
				new_node->next = NULL;
				new_node->value = l1->value;
				l1 = l1->next;
				r->next = new_node;
				r = r->next;
			}
			else free_list(&result);
		}
	}
	else if(l2 != NULL)
	{
		while(l2 != NULL)
		{
			node_ptr new_node = malloc(sizeof(node_t));
		
			if(new_node != NULL)
			{
				new_node->next = NULL;
				new_node->value = l2->value;
				l2 = l2->next;
				r->next = new_node;
				r = r->next;
			}
			else free_list(&result);
		}
	}
	
	return result;
}
