typedef char* bstitem;

#define BST_NULL_ITEM	'\0'

#define eq(a,b) strcmp(a,b) == 0
#define lt(a,b) strcmp(a,b) < 0
#define gt(a,b) strcmp(a,b) > 0
#define assign(a,b) strcpy(a,b)

bstitem scan_bstitem();
void print_bstitem(bstitem item);
