// Juan Pedraza
// CSCI 41 - Lab 6
#include <iostream>
#include <stdlib.h> //generate random number
#include <vector>
#include "sorts.cpp"

using namespace std;

int main()
{
	unsigned short elements=0;
	cout << "How many random numbers: ";
	cin >> elements;
	vector<short int> vec0(elements); // create vector w/ given number of elements
	for(unsigned short i=0; i<elements; i++) // fill vector w/ random values
		vec0[i] = rand()%200 - 100; // random number -100 to 100

	cout << "Random numbers: ";
	cout << vec0; // print out vector using overloaded operator
	vector<short int> vec1(vec0); // copy of vector vec0
	vector<short int> vec2(vec0); // copy vec0
	vector<short int> vec3(vec0); // for shell sort
	cout << "Selection Sort: ";
	selectionSort(vec1); // call selection sort
	cout << vec1; // print vector after selection sort
	cout << "Insertion Sort: ";
	insertionSort(vec2); // call insertion sort
	cout << vec2; // print vector
	cout << "Shell Sort:\t";
	shellSort(vec3);
	cout << vec3;
	char ch;
	cout << "Redo: r\tExit: e" << endl;
	cin >> ch;
	if(ch == 'r')
		main();
	return 0;
}