
#ifndef MINHEAP_H
#define MINHEAP_H

#include "structs.h"

using namespace std;


class minHeap{

public:
	minHeap();
	~minHeap();
	void insert(int val, hashEntry* hashItem);
	hashEntry* deleteMin();
	void buildHeap();
	void percolateDown(int hole);
	bool isEmpty();
	void printElements();
	int getMinValue();
	void deleteNode(heapNode* node);

private:
	struct heapNode * array[44];
	int currentSize;

};

#endif
