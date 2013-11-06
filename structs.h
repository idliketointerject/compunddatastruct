
#ifndef STRUCTS_H
#define STRUCTS_H

struct heapNode{
	int element;
	int index;
	struct hashEntry *hashLink;
};

struct hashEntry{
	int element;
	struct heapNode *heapLink;
	hashEntry *next;
	hashEntry *prev;
};

#endif
