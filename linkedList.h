

#include "structs.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

class linkedList{
public:
	linkedList();
	~linkedList();
	struct hashEntry* addNodeToHead(int val);
	struct heapNode* deleteNode(int val);
	bool findNode(int val);
private:
	hashEntry* head;
};

#endif
