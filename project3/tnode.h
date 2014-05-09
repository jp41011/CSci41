#ifndef TNODE_H
#define TNODE_H

class tnode
{
private:

public:
	char value;
	tnode* parent;
	tnode* left;
	tnode* right;

	tnode();
	tnode(char v);
	tnode(tnode* p, char v, tnode* l, tnode* r);
	~tnode();
	
};

#endif