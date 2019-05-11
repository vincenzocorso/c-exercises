#ifndef QUEUEITEM_H
#define QUEUEITEM_H

typedef bst_node_ptr queueitem;

#define QUEUE_NULL_ITEM		NULL

queueitem scan_queueitem();
void print_queueitem(queueitem item);

#endif
