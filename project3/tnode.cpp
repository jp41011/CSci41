#include "tnode.h"
#include <iostream>

tnode::tnode()
{
	parent = 0; // 0 = NULL
	value = ' ';
	left = 0;
	right = 0;
}

tnode::tnode(char v)
{
	value = v;
	parent = NULL;
	left = NULL;
	right = NULL;
}

tnode::tnode(tnode* p, char v)
{
	parent = p;
	value = v;
	//assign myself as child of parent
	if(p->left == NULL)
		p->left = this;
	else if(p->right == NULL)
		p->right = this;
	else
		std::cout << value << " already has 2 children"  << std::endl;
	left = NULL;
	right = NULL;
}

tnode::tnode(tnode* p, char v, tnode* l, tnode* r)
{
	parent = p;
	value = v;
	left = l;
	right = r;
	if(p->left == NULL)
		p->left = (tnode*)this;
	else if(p->right == NULL)
		p->right = this;
	else
		std::cout << p->value << " already has 2 children" << std::endl;
}

tnode::~tnode()
{
	delete left;
	delete right;
}