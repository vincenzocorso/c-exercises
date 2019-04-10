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
void print_list(node_ptr list);
void free_list(node_ptr *list);

void print_reverse_list(node_ptr list);
node_ptr search_list(node_ptr list, int value);

int main()
{
	srand(time(NULL));

	node_ptr list = NULL;
	for(int i = 1; i <= 10; i++)
		insert(&list, -10 + rand() % 21);
	
	print_list(list);
	
	delete(&list, 8);
	delete(&list, 7);
	
	print_list(list);
	
	print_reverse_list(list);
	puts("");
	
	free_list(&list);

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
		
		if(previous_ptr != NULL)
			previous_ptr->next = new_node;
		else
			*list = new_node;
		
		new_node->next = current_ptr;
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
