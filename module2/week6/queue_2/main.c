#include <stdio.h>
#include "item.h"
#include "queue.h"

void menu();

int main()
{
	queue_init();
	
	int choise;
	Item data;
	do
	{
		menu();
		scanf("%d", &choise);
		
		switch(choise)
		{
			case 1:
				printf("--> ");
				data = scan_item();
				enqueue(data);
				break;
				
			case 2:
				data = dequeue();
				if(data != ITEM_NULL)
				{
					printf("Item popped: ");
					print_item(data);
					puts("");
				}
				break;
				
			case 3:
				printf("--> ");
				data = scan_item();
				printf("L'elemento inserito %s presente all'interno dello stack\n", is_present(data) ? "è" : "non è");
				break;
			
			case 4:
				queue_print();
				break;
			
			case 5:	
			default:
				puts("Exit...");
				break;
		}
		
		puts("");
	}
	while(choise >= 1 && choise <= 4);
	
	queue_free();

	return 0;
}

void menu()
{
	puts("Queue Menu");
	puts("1. Aggiungi un nuovo elemento");
	puts("2. Elimina un elemento");
	puts("3. Ricerca un elemento");
	puts("4. Stampa la queue");
	puts("5. Esci");
	printf("--> ");
}
