
#include "minHeap.h"
#include <iostream>

using namespace std;

minHeap::minHeap(){
	currentSize = 0;
}

void minHeap::insert(int val, hashEntry* hashItem){
	//percolate up
	int hole = ++currentSize;
	for(;hole > 1 && val < array[hole/2]->element;hole/=2){
		array[hole] = array[hole/2];
		array[hole]->index = hole;
	}
	heapNode * node = new heapNode();
	node->element = val;
	node->index = hole;
	node->hashLink=hashItem;
	array[hole] = node;
	hashItem->heapLink=node;

}

hashEntry* minHeap::deleteMin(){
	if(currentSize > 1){	
		hashEntry* hashPtr = array[1]->hashLink;
		delete array[1];	
		array[1] = array[currentSize--];
		array[1]->index = 1;
		percolateDown(1);
		return hashPtr;
	}
	else if(currentSize == 1){
		hashEntry* hashPtr = array[1]->hashLink;
		delete array[1];
		array[1]=0;
		currentSize--;
		return hashPtr;
	}
	return 0;
}

void minHeap::percolateDown(int hole){
	int child;
	heapNode* tmp = array[hole];
	for(;hole*2 <= currentSize; hole=child){
		child = hole*2;
		if(child != currentSize && array[child+1]->element < array[child]->element)
			child++;
		if(array[child]->element < tmp->element){
			array[hole] = array[child];
			array[hole]->index = hole;
		}
		else
			break;
	}
	array[hole] = tmp;
	array[hole]->index = hole;
}

void minHeap::deleteNode(heapNode* node){
	int hole = node->index;
	while(hole > 1){
		array[hole] = array[hole/2];
		array[hole]->index = hole;
		hole/=2;
	}
	array[1] = node;
	array[1]->index = 1;
	deleteMin();
}

bool minHeap::isEmpty(){
	return currentSize == 0;
}

int minHeap::getMinValue(){
	return array[1]->element;
}

void minHeap::printElements(){
	for(int i = 1; i< currentSize+1; i++)
		cout << array[i]->element << " ";
	cout << endl;
}

minHeap::~minHeap(){
	for(int i = 1; i < currentSize; i++)
		delete array[i];
}
