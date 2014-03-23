// Juan Pedraza
// CSCI 41 - Project 1
#include "SLL.h"
#include "DLL.h"
#include <iostream>

using namespace std;

int main()
{
	// part 1 - Singly Linked List
	cout << "Juan Pedraza CSCI 41" << endl;
	cout << "--------- Part 1 ---------" << endl;
	
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
	cout << "--------- Part 2 ---------" << endl;
	DLL list2;
	list2.insertInOrder('c'); // insert in unsorted order
	list2.insertInOrder('b');
	list2.insertInOrder('a');
	list2.insertInOrder('a');
	list2.insertInOrder('c');
	list2.insertInOrder('d');
	list2.insertInOrder('f');
	list2.insertInOrder('e');
	list2.print();
	cout << "Delete 1th node" << endl << "Delete 3th node" << endl;
	list2.deleteKthNode(1); // remove 2nd a
	list2.deleteKthNode(3); // remove 2nd c
	list2.print();
	cout << "Shift 2 spaces to the left" << endl;
	list2.shiftKNodes(2); // shift 2 spaces to the left
	list2.print();
	/*
	char c, d = 'D';
	cin >> c;
	if(c > d)
		cout << "Greater" << endl;
	else
		cout << "Less" << endl;
	*/
	return 0;
}