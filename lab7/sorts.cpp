// Implement Merge Sort and Quick Sort
#include <vector>
#include <iostream>
#include <stdlib.h> // for rand()
using namespace std;

/*function xchg - takes in 2 references to short integers and will
swap the values. 
*/
void xchg(short& a, short & b)
{
	short temp = a;
	a = b;
	b = temp;
	return;
}
/************************ Merge Sort ************************/
// Merge Sort
void mergeSortHelper(vector<short>&, short, short); // declarring functions
void merge(vector<short>&, short, short, short); // will define them later

void mergeSort(vector<short>& vec)
{
	mergeSortHelper(vec, 0, vec.size()-1);
}

void mergeSortHelper(vector<short>& vec, short low, short high)
{
	if(low < high)
	{
		short mid = (low+high)/2; // low+(high-low)/2
		mergeSortHelper(vec, low, mid);
		mergeSortHelper(vec, mid+1, high);
		merge(vec, low, mid, high);
	}
}

void merge(vector<short> & vec, short low, short mid, short high)
{
	short leftIndex = low; // index for the left array
	short rightIndex = mid+1; // index for the right array
	vector<short> tempVec (0);

	while(leftIndex <= mid && rightIndex <= high)
	{
		if(vec[leftIndex] < vec[rightIndex])
		{
			tempVec.push_back(vec[leftIndex]);
			leftIndex++;
		}else{
			tempVec.push_back(vec[rightIndex]);
			rightIndex++;
		}
	}
	while(leftIndex <= mid)
	{
		tempVec.push_back(vec[leftIndex++]);
	}
	while(rightIndex <= high){
		tempVec.push_back(vec[rightIndex++]);
	}

	short vecIndex = low;
	for(unsigned short i=0; i<tempVec.size(); i++)
		vec[vecIndex++] = tempVec[i];
}
/********************* Quick Sort ************************/

// quick sort helper functions
short partition(vector<short>& vec, short low, short high)
{
	short pivot = vec[high]; // set pivot to the last element
	short i = low-1; // index
	// for loop to place values is left sub array < pivot value < right sub array
	for(short j=low; j < high; j++) // from begining to end of current sub array
	{
		if(vec[j] <= pivot) // if value is less than pivot
		{
			i++;
			xchg(vec[i], vec[j]); // move to the left sub array
		}
	}
	xchg(vec[i+1], vec[high]); // move pivot to its correct position
	return i+1; // return pivot index
}
// to make quicksort perform slightly better use a randomized pivot
short random_partition(vector<short>& vec, short low, short high)
{
	short i = rand()%(high-low+1)+low; // get random value between low and high
	xchg(vec[i], vec[high]);
	return partition(vec, low, high); // call the real partition function
}

// quick sort algo actuall starts here
void quick_sort(vector<short>& vec, short low, short high)
{
	if(low < high)
	{
		short q = random_partition(vec, low, high); // get pivot in correct position
		quick_sort(vec, low, q-1); // recursively sort the left sub array
		quick_sort(vec, q+1, high); // recursively sort the right sub array
	}
}

// Quick Sort - with a random pivot
void quickSort(vector<short>& vec)
{
	quick_sort(vec, 0, vec.size()-1); // call helper function with values
}