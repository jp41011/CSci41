// Implement selection sort & insertion sort
#include <vector>
#include <math.h>
using namespace std;

/*function xchg - takes in 2 references to short integers and will
swap the values. 
*/
void xchg(short& a, short& b)
{
	short temp = a;
	a = b;
	b = temp;
	return;
}

// Selection Sort implementation 
void selectionSort(vector<short int> & vec)
{
	//cout << "Selections Sort" << endl;
	short size = vec.size();
	short minIndex = 0; // keep track of the index with the current min value
	for(short i=0; i<size; i++) // iterate through whole vector
	{
		minIndex = i; // initialize the min index to current index
		for(short j=i+1; j<size; j++) // go through rest of vector looking for a new min value
		{
			if(vec[j] < vec[minIndex]) // if you find new min value
				minIndex = j;			// update to new min index
		}
		if(i != minIndex) // if min index is different from current index swap the values
			xchg(vec[i], vec[minIndex]); //swap elements
	}
	return;
}

// Insertion Sort implementation
void insertionSort(vector<short> & vec)
{
	//cout << "insertion sort" << endl;
	short size = vec.size();
	short i, j; // variables to iterate through vector
	for(i=1; i<size; i++) // start @ 2nd element because 1st is trivially sorted
	{
		j = i;
		while(j>0 && vec[j-1] > vec[j]) //if the one to the left is smaller then exchange
		{
			xchg(vec[j-1], vec[j]);
			j--; //decrement j index, go towards the left
		}
	}
}

// Shell sort implementation
void shellSort(vector<short> & vec)
{
	//first calculate gap [h] values using 2^k-1 where k >= 1
	short size = vec.size();
	vector<short> gaps(0);
	short k=2;
	short gap=1;
	while(gap<size) // add gaps to vector of gaps logest must be smaller than size of vector
	{
		gaps.push_back(gap);
		gap = pow(2,k++)-1;
	}
	//short gapIndex = gaps.size()-1;
	for(short gapIndex = gaps.size()-1; gapIndex >= 0; gapIndex--)
	{
		for(short i=gaps[gapIndex]; i < size; i++)
		{
			short temp = vec[i];
			short j;
			for(j=i; j>=gaps[gapIndex] && vec[j-gaps[gapIndex]] > temp; j-=gaps[gapIndex])
			{
				vec[j] = vec[j-gaps[gapIndex]];
			}
			vec[j] = temp;
		}
	}

}

// overloading the << operator to print out vector. same as print(vector<short> & vec) { ... }
ostream& operator << (ostream& out, vector<short>& vec)
{
	short size = vec.size(); // get size of vector
	for(short i=0; i<size; i++) // iterate through vector
		out << vec[i] << " "; // printing values into output stream
	out << endl; // new line at the end
}