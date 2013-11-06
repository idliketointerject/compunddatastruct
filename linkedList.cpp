
#include "linkedList.h"

using namespace std;

linkedList::linkedList(){
	head=0;
}

hashEntry* linkedList::addNodeToHead(int val){
	hashEntry * node = new hashEntry;
	hashEntry * tmp = head;
	node->element = val;
	node->next=head;
	node->prev=0;
	if(tmp != 0)
		tmp->prev=node;
	head=node;
	return node;
}

heapNode* linkedList::deleteNode(int val){
	heapNode * tmp;
	hashEntry * probe = head;
	hashEntry * tmp2;
	if (probe==0)
		return 0;
	if (probe->element==val){
		head=probe->next;		
		tmp=probe->heapLink;
		delete probe;
		return tmp;
	}
	while(probe->next != 0){
		if(probe->next->element == val){
			tmp= probe->next->heapLink;
			tmp2 = probe->next;
			probe->next=probe->next->next;			
			delete tmp2;
			return tmp;
		}
		probe = probe->next;	
	}
	return 0;
}

bool linkedList::findNode(int val){
	if(head==0)
		return false;
	hashEntry* current;
	current = head;
	if(current->element == val)
		return true;
	while(current->next != 0){
		if(current->next->element == val)
			return true;
		current = current->next;	
	}

	return false;
}

linkedList::~linkedList(){
	hashEntry* current = head;
	while(current != 0){
		hashEntry* temp = current;
		current = current->next;
		delete temp;
	}
}
