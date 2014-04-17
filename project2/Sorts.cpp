#include "Sorts.h"
#include <vector>
#include <math.h> // to use pow()
#include <string>

using std::vector;
using std::string;

/* return sorted vector of books based on publish year.
newest to oldest, using shell sort*/
vector<Book> sortByYear(vector<Book> vec)
{
	// first calc gap[h] values using 2^k -1 where k >= 1
	int size = vec.size(); // number of books in the vector
	vector<int> gaps(0);
	int k=2;
	int gap = 1;
	while(gap < size)
	{
		gaps.push_back(gap);
		gap = pow(2,k++)-1;
	}
	// sort
	for(int gapIndex = gaps.size()-1; gapIndex >= 0; gapIndex--)
	{
		for(int i = gaps[gapIndex]; i < size; i++)
		{
			Book temp = vec[i];
			int tempYear = temp.getPublishYear();
			int j;
			for(j = i; j >= gaps[gapIndex] && vec[j-gaps[gapIndex]].getPublishYear() < tempYear; j-=gaps[gapIndex])
			{
				vec[j] = vec[j-gaps[gapIndex]];
			}
			vec[j] = temp;
		}
	}

	return vec;
}

/* return sorted vector of books based on book price
lowest to highest, using merge sort*/
vector<Book> sortPrice(vector<Book> vec)
{
	mergeSort(vec, 0, vec.size()-1);
	return vec;
}

void mergeSort(vector<Book>& vec, int low, int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;
		mergeSort(vec, low, mid);
		mergeSort(vec, mid+1, high);
		merge(vec, low, mid, high);
	}
}

void merge(vector<Book>& vec, int low, int mid, int high)
{
	int leftIndex = low;
	int rightIndex = mid+1;
	vector<Book> tempVec(0);

	while(leftIndex <= mid && rightIndex <= high)
	{
		if(vec[leftIndex].getPrice() < vec[rightIndex].getPrice())
			tempVec.push_back(vec[leftIndex++]);
		else
			tempVec.push_back(vec[rightIndex++]);

	}
	// reached to the end of one of the sub arrays go to the rest of the other
	while(leftIndex <= mid)
		tempVec.push_back(vec[leftIndex++]);

	while(rightIndex <= high)
		tempVec.push_back(vec[rightIndex++]);

	int vecIndex = low;
	for(int i=0; i < tempVec.size(); i++)
		vec[vecIndex++] = tempVec[i];
	return;
}

/* return sorted vector of books based on book name (title)
alphabetical order, using quick sort*/
vector<Book> sortByName(vector<Book> vec)
{
	quickSort(vec, 0, vec.size()-1);
	return vec;
}

void quickSort(vector<Book>& vec, int low, int high)
{
	if(low < high)
	{
		int q = partition(vec, low, high);
		quickSort(vec, low, q-1);
		quickSort(vec, q+1, high);
	}
}

int partition(vector<Book>& vec, int low, int high)
{
	string pivot = vec[high].getName();
	int i = low-1; // index
	for(int j=low; j < high; j++)
	{
		if(vec[j].getName().compare(pivot) <= 0 )
		{
			i++;
			swapBooks(vec[i], vec[j]);
		}
	}
	swapBooks(vec[i+1], vec[high]);
	return i+1;
}

void swapBooks(Book& b1, Book& b2)
{
	Book temp = b1;
	b1 = b2;
	b2 = temp;
	return;
}