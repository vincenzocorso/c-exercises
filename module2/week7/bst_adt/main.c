#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bstitem.h"
#include "bst.h"

int main()
{
	srand(time(NULL));

	bst_init();
	
	/*printf("value inserted: ");
	for(int i = 1; i <= 10; i++)
	{
		int r = rand() % 21;
		print_item(r);
		printf(" ");
		bst_insert(r);
	}
	puts("");*/
	bst_insert(23);
	bst_insert(17);
	bst_insert(45);
	bst_insert(13);
	bst_insert(21);
	bst_insert(7);
	bst_insert(15);
	bst_insert(2);
	bst_insert(9);
	bst_insert(8);
	bst_insert(33);
	bst_insert(48);
	bst_insert(27);
	bst_insert(35);
	bst_insert(25);
	bst_insert(28);
	bst_insert(29);
	bst_insert(14);

	printf("inorder: ");
	bst_inorder();
	puts("");

	printf("preorder: ");
	bst_preorder();
	puts("");

	printf("postorder: ");
	bst_postorder();
	puts("");

	for(int i = 1; i <= 10; i++)
	{
		int r = rand() % 21;
		printf("search ");
		print_bstitem(r);
		printf(" : %d\n", bst_search(r));
	}

	printf("distance(%d,%d) = %d\n", 15, 28, bst_distance(15, 28));
	
	bst_levelorder();
	
	puts("");
	bst_print();
	
	bst_delete(28);
	
	puts("");
	bst_print();

	bst_free();
}
