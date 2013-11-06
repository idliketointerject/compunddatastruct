
#include "hash.h"
#include "minHeap.h"

#ifndef QUASH_H
#define QUASH_H

using namespace std;


class quash{

public:
	bool contains(int val);
	bool erase(int val);
	void insert(int val);
	int deleteMin();
	void print();
	bool isEmpty();
	int getMinValue();
	
private:
	minHeap heap;
	hash hash1;
};

#endif

