#ifndef DLL_H
#define DLL_H

#include "NodeD.h"
#include <ctype.h>
#include <iostream>
using namespace std;

class DLL
{
public:
	NodeD* front;
	NodeD* tail;

	DLL(){front = tail = 0;}
	~DLL(){
		while(front != NULL){
			tail = front; // using tail as a temp node pointer
			front = front->next;
			delete tail;
		}
	}
	
	void print(){
		NodeD* it = front;
		int count = 0;
		cout << "Dlist: ";
		while(it != NULL)
		{
			cout << it->data << " ";
			it = it->next;
			count++;
		}
		cout << endl;
		//cout << "Nodes: " << count << endl; // for testing
		return;
	}

	// Insert a character in order to the list
	void insertInOrder(char ch){
		char ch2 = toupper(ch);
		if(front == NULL) // empty list
		{
			front = tail = new NodeD(ch2, NULL, NULL);
			return;
		}
		NodeD* it = front;
		while(it != NULL)
		{
			if(ch2 <= it->data){
				NodeD* newNode = new NodeD(ch2, it->prev, it);
				// error here it->prev when null
				if(it->prev != NULL) // if not front
					newNode->prev->next = newNode;
				else // it was front
				{	

					front = newNode; // update new front
				}
				it->prev = newNode; // update it's prev to new node
				return;
			}else if(it == tail){ //->next == NULL){ // if it is tail
				NodeD* newNode = new NodeD(ch2,it, NULL);
				it->next = newNode;
				tail = newNode;
				return;
			}else
				it = it->next;
		}
	}
	// delete kth node from the begining starting at 0
	void deleteKthNode(int k){
		NodeD* it = front;
		bool error = false;
		for(int i=0; i<k; i++){
			if(it == NULL)
			{
				error = true;
				break;
			}else
				it = it->next;
		}
		if(error==true)
			return;
		//else
		//	cout << "Found: " << it->data << endl; // testing
		NodeD* p = it->prev;
		NodeD* n = it->next;
		if(p != NULL)
			p->next = n;
		if(n != NULL)
			n->prev = p;
		if(it == front)
			front = n;
		if(it == tail)
			tail = p;
		delete it;
	}
	// shift k nodes to the left (circular)
	void shiftKNodes(int k){
		// first make list circular
		if(front == NULL) // empty list
			return; //exit
		front->prev = tail;
		tail->next = front;
		// then shift front and tail to the left k times
		for(int i=0; i<k; i++)
		{
			front = front->next;
			tail = tail->next;
		}
		//unlink ends of the list
		front->prev = NULL;
		tail->next = NULL;
		return;
	}

};

#endif