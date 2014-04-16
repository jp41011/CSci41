// Juan Pedraza
/* CSCI 41 - Lab7
Implementation of merge sort and quick sort
*/
#include <iostream>
#include <stdlib.h> // rand()
#include <time.h> // for srand(time(NULL))
#include <vector>
#include "sorts.cpp"
using namespace std;

// overloading the << operator to print out vectors
ostream& operator << (ostream& out, vector<short>& vec)
{
	short size = vec.size();
	for(short i=0; i<size; i++)
		out << vec[i] << " ";
	out << endl;
}

int main()
{
	//cout << "time: " << time(NULL) << endl;
	unsigned short nums = 0;
	cout << "How many random numbers: ";
	cin >> nums;
	vector<short int> vec0 (0);
	srand(time(NULL));
	for(unsigned short i=0; i<nums; i++)
		vec0.push_back(rand()%2000 - 1000);

	cout << "Random numbers: ";
	cout << vec0;
	//copy vectors to sort with merge and quick sort
	vector<short> vec1(vec0);
	vector<short> vec2(vec0);
	cout << "Merge Sort: ";
	mergeSort(vec1);
	cout << vec1;
	cout << "Quick Sort: ";
	quickSort(vec2);
	cout << vec2;
	char ch;
	cout << "Redo: r\tExit: e" << endl;
	cin >> ch;
	if(ch == 'r')
		main();

	return 0;
}