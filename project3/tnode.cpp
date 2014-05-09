#include "tnode.h"

tnode::tnode()
{
	parent = 0; // 0 = NULL
	value = ' ';
	left = 0;
	right = 0;
}

tnode::tnode(char v){ value = v;}

tnode::tnode(tnode* p, char v, tnode* l, tnode* r)
{
	parent = p;
	value = v;
	left = l;
	right = r;
}

tnode::~tnode()
{
	delete left;
	delete right;
}