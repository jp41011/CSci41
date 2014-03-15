#ifndef DLL_H
#define DLL_H

#include "NodeD.h"
#include <ctype.h>

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

	void insertInOrder(char ch){
		if(front == NULL) // empty list
		{
			front = tail = new NodeD(toupper(ch), NULL, NULL);
			return;
		}
		NodeD* it = front;
		while(it != NULL){
			if(it->data < )
		}
	}
	//void deleteKthNode(int k)
	//void shiftKNodes(int k)

};

#endif