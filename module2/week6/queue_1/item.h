typedef int Item;

#define ITEM_NULL	-1
#define ITEM_FORMAT_SPECIFIER	"%d"
#define eq(a,b)	((a) == (b))

Item scan_item();
void print_item(Item value);
