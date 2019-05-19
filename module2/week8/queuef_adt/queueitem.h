#ifndef QUEUEITEM_H
#define QUEUEITEM_H

typedef int queueitem;

#define QUEUE_NULL_ITEM		-1
#define eq(a,b)		((a) == (b))
#define lt(a,b)		((a) < (b))
#define gt(a,b)		((a) > (b))

void print_queueitem(queueitem item);
queueitem scan_queueitem();

#endif
