#include <stdio.h>
#include "bstitem.h"
#include "bst.h"

int main()
{
	bst_init();
	
	char str[100] = "pippo pluto paperino qui quo qua";
	bst_split(str);

	printf("Inorder: ");
	bst_inorder();
	puts("");

	printf("Preorder: ");
	bst_preorder();
	puts("");

	printf("Postorder: ");
	bst_postorder();
	puts("");

	bst_free();
}
