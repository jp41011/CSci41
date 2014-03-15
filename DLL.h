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
		cout << "Dlist: ";
		while(it != NULL)
		{
			cout << it->data << " ";
			it = it->next;
		}
		cout << endl;
		return;
	}
	// TODO fix insertInOrder
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
			if(ch2 < it->data){
				NodeD* newNode = new NodeD(ch2, it->prev, it);
				it->prev = newNode;
				newNode->prev->next = newNode;
				return;
			}else if(it->next == NULL){
				NodeD* newNode = new NodeD(ch2,it, NULL);
				it->next = newNode;
				tail = newNode;
				return;
			}
		}
	}
	//void deleteKthNode(int k)
	//void shiftKNodes(int k)

};

#endif