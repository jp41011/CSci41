#ifndef NODED_H
#define NODED_H

class NodeD
{
public:
	char data;
	NodeD* prev;
	NodeD* next;

	NodeD(){prev = next = 0;}
	NodeD(char d, NodeD* p, NodeD* n){
		data = d;
		prev = p;
		next = n;
	}
	~NodeD(){}
};

#endif