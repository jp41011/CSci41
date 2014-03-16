#ifndef NODES_H
#define NODES_H

class NodeS
{
public:
	char data;
	NodeS* next;

	//constructors
	NodeS(){next = 0;}
	NodeS(char ch){
		data = ch;
		next = 0;
	}
	NodeS(char ch, NodeS* nxt)
	{
		data = ch;
		next = nxt;
	}
	~NodeS(){} // deconstructor
};

#endif