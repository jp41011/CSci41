// Implement selection sort & insertion sort
#include <vector>
using namespace std;

void xchg(short& a, short& b)
{
	short temp = a;
	a = b;
	b = temp;
	return;
}

void selectionSort(vector<short int> & vec)
{
	cout << "Selections Sort" << endl;
	short size = vec.size();
	short minIndex = 0;
	for(short i=0; i<size; i++)
	{
		minIndex = i;
		for(short j=i+1; j<size; j++)
		{
			if(vec[j] < vec[minIndex])
				minIndex = j;
		}
		if(i != minIndex)
			xchg(vec[i], vec[minIndex]); //swap elements
	}
	return;
}

void insertionSort(vector<short> & vec)
{
	cout << "insertion sort" << endl;
}

ostream& operator << (ostream& out, vector<short>& vec)
{
	short size = vec.size();
	for(short i=0; i<size; i++)
	{
		out << vec[i] << " ";
	}
	out << endl;
}