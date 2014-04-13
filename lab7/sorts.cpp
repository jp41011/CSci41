// Implement Merge Sort and Quick Sort
#include <vector>
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

// Merge Sort
void mergeSortHelper(vector<short>&, short, short); // declarring functions
void merge(vector<short>&, short, short, short); // will define them later

void mergeSort(vector<short>& vec)
{
	mergeSortHelper(vec, 0, vec.size());
}

void mergeSortHelper(vector<short>& vec, short low, short high)
{
	if(low < high)
	{
		short mid = (low+high)/2;
		mergeSortHelper(vec, low, mid);
		mergeSortHelper(vec, mid+1, high);
		merge(vec, low, mid, high);
	}
}

void merge(vector<short> & vec, short low, short mid, short high)
{
	short leftIndex = low; // index for the left array
	short rightIndex = mid; // index for the right array
	vector<short> tempVec (0);

	while(leftIndex < mid && rightIndex <= high)
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
	while(leftIndex < mid)
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

// Quick Sort
void quickSort(vector<short>& vec)
{
	
}