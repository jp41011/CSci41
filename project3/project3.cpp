// Juan Pedraza
// CSCI 41 - Project 3
#include <iostream>
#include <deque>
#include <stack>
#include <string>
#include "tnode.h"

using std::cout;
using std::endl;
using std::deque;
using std::stack;
using std::string;

/* BT is valid if
	leaf nodes are alphabetic variables or integers
	interior nodes are + - * /
	binary tree
*/
bool isBinaryTree(tnode* root)
{
	bool isBT = true;
	deque<tnode*> myQ;
	myQ.push_back(root);
	tnode* temp;
	while(myQ.empty() == false)
	{
		temp = myQ.front();
		myQ.pop_front();
		if(temp->left != NULL) // if there is a left child
			myQ.push_back(temp->left);
		if(temp->right != NULL) // if there is a right child
			myQ.push_back(temp->right);

		if(temp->left != NULL || temp->right != NULL) // it has a child
		{
			// if it has children it must be + or - or * or /
			if(temp->value != '+' && temp->value != '-' && temp->value != '*' && temp->value != '/')
			{
				isBT = false;
				break;
			}
		}
		else // it does not have any children (leaf node)
		{
			// value must be a alpha or integers
			if(isalnum(temp->value) == 0 ) // neither number or alpha
			{
				isBT = false;
				break;
			}
		}
	}
	return isBT;
}

// returns the number of alphabetic variables.
int computeLeaf(tnode* root)
{
	stack<tnode*> myStack;
	myStack.push(root);
	tnode* temp;
	int count=0;
	while(myStack.empty() == false)
	{
		temp = myStack.top();
		myStack.pop();
		if(isalpha(temp->value) != 0) // it IS alphabetic letter
		{	
			count++;
		}
		if(temp->right != NULL)
			myStack.push(temp->right);
		if(temp->left != NULL)
			myStack.push(temp->left);
	}

	return count;
}

// returns level in which char is in the tree. -1 otherwise
int lookup(tnode* root, char ch)
{
	int level = -1;
	//cout << "looking for " << ch << endl;
	deque<tnode*> myQ;
	tnode* newline = new tnode('\n');
	
	myQ.push_back(root);
	myQ.push_back(newline);

	while(!myQ.empty())
	{
		tnode* nextNode = myQ.front();
		//cout << "Next Node: " << nextNode->value << endl;
		myQ.pop_front();
		if(nextNode->value == '\n' && myQ.empty() == false)
		{
			myQ.push_back(newline);
			level++;
			continue;
		}
		else if(nextNode->value == ch) // found char
		{
			level++;
			break;
		}

		if(nextNode->left != NULL)
			myQ.push_back(nextNode->left);

		if(nextNode->right != NULL)
			myQ.push_back(nextNode->right);

	}
	
	delete newline; // clear up memory that was used
	return level;
}

// find ch in tree and change value to val
void assign(tnode* root, char ch, char val)
{
	deque<tnode*> myQ;
	myQ.push_back(root);
	tnode* temp;
	while(!myQ.empty())
	{
		temp = myQ.front();
		myQ.pop_front();
		if(temp->value == ch) // found target
		{
			temp->value = val; // assign new value
			return; //exit
		}

		if(temp->left != NULL)
			myQ.push_back(temp->left);
		if(temp->right != NULL)
			myQ.push_back(temp->right);
	}
	return;
}

string postOrder(tnode* node)
{
	if(node != NULL)
	{
		string str = "";

		if(node->left != NULL)
			str += postOrder(node->left);
		if(node->right != NULL)
			str = str + postOrder(node->right);
		//cout << node->value << " ";
		str = str + node->value;
		return str;
	}
	return "";
}

int computeNumericalResult(tnode* root)
{
	string str = postOrder(root);
	//cout << str << endl;
	stack<int> myStack;
	int tempInt, temp2;
	for(int i=0; i < str.size(); i++)
	{
		if(str[i] >= '0' && str[i]<= '9') // if the char is a digit 0 - 9
		{
			tempInt = int(str[i] - '0');
			//cout << "Adding: " << tempInt << endl;
			myStack.push(tempInt);
			continue;
		}else if(isalpha(str[i])) // if it is a variable (letter)
		{
			cout << "Variables should not be present. Exchange for numbers." << endl;
			return -1;
		}

		// get the top 2 numbers from the stack
		temp2 = myStack.top();
		myStack.pop();
		tempInt = myStack.top();
		myStack.pop();

		switch(str[i])
		{
			case '+':
				myStack.push(tempInt+temp2);
				break;
			case '-':
				myStack.push(tempInt-temp2);
				break;
			case '*':
				myStack.push(tempInt*temp2);
				break;
			case '/':
				myStack.push(tempInt/temp2);
				break;
			default:
				cout << "unknown operator: " << str[i] << endl;
				return -1;
				break;
		}
	}
	if(myStack.size() == 1)
	{
		tempInt = myStack.top();
		myStack.pop();
		return tempInt;
	}
	else
	{
		cout << "Error: More than one number left in stack." << endl;
		while(!myStack.empty())
		{
			cout << myStack.top() << endl;
			myStack.pop();
		}
		return -1;
	}
}

bool isCompleteTree(tnode* root)
{
	if(root == NULL)
		return true;
	deque<tnode*> myQ;
	myQ.push_back(root);
	// Full node = node with both left and right children
	bool seenNonFullNode = false; // have you seen a non Full node
	tnode* tempNode;
	while(!myQ.empty())
	{
		tempNode = myQ.front();
		myQ.pop_front();
		if(tempNode->left != NULL)
		{
			// if we have seen a non full node, then all the nodes after should be be leaf nodes
			// so it should not have had a left child
			if(seenNonFullNode == true)
				return false;
			myQ.push_back(tempNode->left);
		}else // did not have a left child, so it is a non full node
		{
			seenNonFullNode = true;
		}
		// no check right child
		if(tempNode->right != NULL)
		{
			// same logic as before
			// if we already saw a non full node, then these should also be non full nodes
			if(seenNonFullNode == true)
				return false;
			myQ.push_back(tempNode->right);
		}else // there was no right child
			seenNonFullNode = true; // set seen non full node flag
	}

	return true;
}

// will make a better way of print this out later
void printTree(tnode* root)
{
	deque<tnode*> levelQueue;
	tnode* newline = new tnode('\n'); // sentinal value to printout newlines
	levelQueue.push_back(root);
	levelQueue.push_back(newline);
	while(levelQueue.empty() == false)
	{
		tnode* temp = levelQueue.front(); //get next node
		cout << '\t' << temp->value << '\t';
		levelQueue.pop_front(); // remove next node
		if(temp->value == '\n' && levelQueue.empty() == false)
			levelQueue.push_back(newline);

		if(temp->left != NULL)
			levelQueue.push_back(temp->left);
		if(temp->right != NULL)
			levelQueue.push_back(temp->right);
	}
	delete newline;
}

string printPreOrder(tnode* node)
{
	if(node != NULL)
	{
		cout << node->value << " ";
		string str = "";
		str = str + (node->value);
		if(node->left != NULL)
		{	
			str = str + printPreOrder(node->left);
		}
		if(node->right != NULL)
		{
			str = str + printPreOrder(node->right);
		}
		return str;
	}
	return "";
}

void printInOrder(tnode* node)
{
	if(node != NULL)
	{
		if(node->left != NULL)
			printInOrder(node->left);
		
		cout << node->value << " ";

		if(node->right != NULL)
			printInOrder(node->right);
	}
}

void printPostOrder(tnode* node)
{
	if(node != NULL)
	{
		if(node->left != NULL)
			printPostOrder(node->left);
		if(node->right != NULL)
			printPostOrder(node->right);
		cout << node->value << " ";
	}
}

int main()
{
	// Create Binary Tree - level by level, left to right
	tnode* root = new tnode('-');
	tnode* plus1 = new tnode(root, '+');
	tnode* star1 = new tnode(root, '*');
	tnode* nodeA = new tnode(plus1, 'a');
	tnode* slash1 = new tnode(plus1, '/');
	tnode* node2 = new tnode(star1, '2');
	tnode* plus2 = new tnode(star1, '+');
	tnode* star2 = new tnode(slash1, '*');
	tnode* nodeD = new tnode(slash1, 'd');
	tnode* nodeE = new tnode(plus2, 'e');
	tnode* node3 = new tnode(plus2, '3');
	tnode* nodeB = new tnode(star2, 'b');
	tnode* nodeC = new tnode(star2, 'c');

	printTree(root);
	cout << endl;

	cout << "Look up: -\t" << "Level: " << lookup(root, '-') << endl;
	cout << "Look up: a\t" << "Level: " << lookup(root, 'a') << endl;
	cout << "Look up: 3\t" << "Level: " << lookup(root, '3') << endl;
	cout << "Look up: c\t" << "Level: " << lookup(root, 'c') << endl;
	
	/****** Test isBinaryTree() ****/
	cout << "Is Binary Tree: ";
	if(isBinaryTree(root) == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	/*******************************/

	cout << "Alphabetic var count: " << computeLeaf(root) << endl;

	assign(root, 'a', '4');
	assign(root, 'b', '5');
	assign(root, 'c', '6');
	assign(root, 'd', '7');
	assign(root, 'e', '8');
	printTree(root); cout << endl;

	cout << "PreOrder:\t"; printPreOrder(root); cout << endl;
	cout << "InOrder:\t"; printInOrder(root); cout << endl;
	cout << "PostOrder:\t"; printPostOrder(root); cout << endl;

	cout << "Compute Result: " << computeNumericalResult(root) << endl;

	cout << "Is complete tree: ";
	if(isCompleteTree(root)==true)
		cout << "True";
	else
		cout << "False";
	cout << endl;

	cout << "---------- TESTING with Complete Tree ----------" << endl;
	//test with complete tree
	tnode* nA = new tnode('A');
	tnode* nB = new tnode(nA, 'B');
	tnode* nC = new tnode(nA, 'C');
	tnode* nD = new tnode(nB, 'D');
	tnode* nE = new tnode(nB, 'E');
	tnode* nF = new tnode(nC, 'F');
	tnode* nG = new tnode(nC, 'G');
	tnode* nH = new tnode(nD, 'H');

	printTree(nA); cout << endl;
	cout << "Complete tree: ";
	if(isCompleteTree(nA))
		cout << "True";
	else
		cout << "False";
	cout << endl;

	return 0;
}