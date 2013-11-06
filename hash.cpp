
#include "hash.h"

using namespace std;
//returns true if the value is already in the hash
bool hash::contains(int val){
	int pos = hashIt(val);
	return buckets[pos].findNode(val);
}

heapNode* hash::remove(int val){
	int pos = hashIt(val);
	return buckets[pos].deleteNode(val);
}

hashEntry* hash::insert(int val){
	int pos = hashIt(val);
	return buckets[pos].addNodeToHead(val);
}

int hash::hashIt(int val){
  if(val < 0)
    val = val - 2*val;

  return val % 43;
}

void hash::deletePtr(hashEntry* ptr){
	buckets[hashIt(ptr->element)].deleteNode(ptr->element);
}

hash::hash(){
	buckets  = new linkedList[43];
}
