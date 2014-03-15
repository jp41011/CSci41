// Juan Pedraza
// CSCI 41 - Project 1
#include "SLL.h"
//#include "DLL.h"
#include <iostream>

using namespace std;

int main()
{
	// part 1 - Singly Linked List
	SLL list1;
	list1.print();
	list1.pushBack('A');
	list1.pushBack('B');
	list1.pushBack('C');
	list1.pushBack('D');
	list1.print();
	list1.duplicate();
	cout << "Duplicate" << endl;
	list1.print();
	list1.deleteDuplicate();
	cout << "DeleteDuplicate" << endl;
	list1.print();
	cout << "Added E and F" << endl;
	list1.pushBack('E');
	list1.pushBack('F');
	list1.print();
	cout << "7th from back: ";
	cout << list1.findkthNodeFromBack(7) << endl;
	cout << "3rd from back: ";
	cout << list1.findkthNodeFromBack(3) << endl;
	cout << "6th from back: ";
	cout << list1.findkthNodeFromBack(6) << endl;
	cout << "1st from back: ";
	cout << list1.findkthNodeFromBack(1) << endl;

	// part 2 - Doubly Linked List
	

	return 0;
}