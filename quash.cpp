
#include "quash.h"

using namespace std;

bool quash::contains(int val){
	return hash1.contains(val);
}

bool quash::erase(int val){
	if(hash1.contains(val) == false)
		return false;
	else{
		heap.deleteNode(hash1.remove(val));
	}
	return true;
}

void quash::insert(int val){
	hashEntry* hashItem = hash1.insert(val);
	heap.insert(val, hashItem);

}

int quash::deleteMin(){
	int minValue = heap.getMinValue();
	hash1.deletePtr(heap.deleteMin());
	return minValue;
}

void quash::print(){
	heap.printElements();
}

bool quash::isEmpty(){
	return heap.isEmpty();
}

int quash::getMinValue(){
	return heap.getMinValue();
}

