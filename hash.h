
#include "structs.h"
#include "linkedList.h"

#ifndef HASH_H
#define HASH_H


using namespace std;

class hash{

public:
	hash();
	bool contains(int val);
	struct hashEntry* insert(int val);
	struct heapNode* remove(int val);
	int hashIt(int val);
	void deletePtr(hashEntry* ptr);

private:
	linkedList *buckets;

};

#endif
