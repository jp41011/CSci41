Juan Pedraza
CSCI 41 - Project 3
5/12/14

I have included a Makefile to complile and run this project.
The files needed are: project3.cpp, tnode.h, tnode.cpp
project3 will be the name of the binary file, to run the program

tnode
	contains variables: char value, tnode* parent, tnode* left, tnode* right.
	I created constructor functions that would initialize the variable values. I also created a destructor that would call the destructor of both the left and the right child nodes.

isBinaryTree
	To check if it is a valid binary tree I go through the tree level by level using a queue. If a node has children then the char must be either + - * or /. If a node is a leaf (no children) then it must be a integer or a variable

computeLeaf
	returns the number of alphabetic variables. Here I use a stack to go through the tree (DFS) and increase the count every time i encounter a node with a char value that isalpha() returns as true.

lookup
	I initialize a level variable to -1. I go through the tree level by level using a queue (BFS) and compare the my target value to current node value if they are the same then i return the level. I increase the level every time i find my sentinal value node ('\n') which tells me i will have one more level. Once i find the target I break out of the loop and return the level number

assign
	For this i use the same process as for lookup except that once i find the target node i change the value to the new value, and then break out of the loop.

computeNumericalResult
	For this i created an auxilary function that would iterate through the tree and produce a string of the char in post order. I call this function from my computeNumericalResult function from there I use stack to keep track of the values. reading the string from left to right, if i read a number then i add it to the stack. if i read a operator then i pop off the last 2 numbers from the stack and then use the operator on them, adding the result back onto the stack. once i have gone through the whole string there should only be one value in the stack and that is the answer that i return.

isCompleteTree
	For a binary tree to be complete all but the last level must be completely filled. I have a bool variable that tells me if i have seen an incomplete node (non full node) which is a node that does not have 2 children. once i find a node that is non full then all other nodes after that should be leaf nodes (no children) if that is not true then the tree is not complete. I do these check level by level so i iteretate through the tree with a queue (BFS).