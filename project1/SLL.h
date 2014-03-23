#ifndef SLL_H
#define SLL_H

#include "NodeS.h"
#include <iostream>
using namespace std;

class SLL
{
public:
	NodeS* front;
	NodeS* back;
	// default constructor
	SLL(){front = back = 0;}
	// free up all the space that was taken by the list
	~SLL(){
		while(front != NULL)
		{
			back = front; // using back as a temp node pointer
			front = front->next;
			delete back;
		}
	}
	// add to the back of the list
	void pushBack(char ch){
		if(front == NULL) // front is empty == empty list
		{
			NodeS* newNode = new NodeS(ch); // create new node
			front = back = newNode; // update front and back
		}else{ // list is not empty
			NodeS* newNode = new NodeS(ch); // create node
			back->next = newNode; // add to end of list
			back = newNode; // update back to new last node
		}
	}
	// Go through list and duplicate every node
	void duplicate(){
		NodeS* it = front;
		while(it != NULL)
		{
			NodeS* newNode = new NodeS(it->data, it->next);
			it->next = newNode;
			it = newNode->next;
		}
	}
	// delete all duplicate nodes
	void deleteDuplicate(){ //TODO error with itPrev
		NodeS* cur = front; // start iterator at front (matching index)
		NodeS* prv = cur; // previous node
		NodeS* nxt; // next node
		while(cur != NULL){ // while havent reached the end
			prv = cur; // new matching index, set prv to cur
			nxt = cur->next; // get next node
			while(nxt != NULL){ // if next node is not null (end of list)
				if(cur->data == nxt->data) // if match
				{
					prv->next = nxt->next; // make prv point to nxt's next
					delete nxt; // delete duplicate node
					nxt = prv->next; // update nxt to next node
				}else{ // no match
					prv = nxt; // prv becomes current node
					if(nxt->next == NULL) // if next is end of list
						break; // stop
					nxt = nxt->next; //otherwise move to next node
				}
			}
			if(cur->next == NULL) // if there is no more matching index
				break; // stop
			cur = cur->next; // otherwise get next matching index
		}
	}
	char findkthNodeFromBack(int k){
		NodeS* one = front;
		NodeS* two = front;
		if(one == NULL) // empty list
			return '~';
		for(int i=1; i<k; i++) // move two pointer to kth node from the front
		{
			if(two->next != NULL)
				two = two->next;
			else
			{
				cout << "k greater than size of list" << endl;
				return '~';
			}
		}
		while(two->next != NULL)
		{
			two = two->next;
			one = one->next;
		}
		return (one->data);
	}
	// print all elements in list
	void print(){
		NodeS* it = front;
		cout << "List: ";
		while(it != NULL)
		{
			cout << it->data << " ";
			it = it->next;
		}
		cout << endl;
	}
	
};

#endif