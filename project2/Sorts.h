#ifndef SORTS_H
#define SORTS_H
#include "Book.h"
#include <vector>

// will use shell sort for this function
std::vector<Book> sortByYear(std::vector<Book>);

// will use merge sort to sort from lowest to highest price
std::vector<Book> sortPrice(std::vector<Book>);

// use quicksort to sort in alphabetic order
std::vector<Book> sortByName(std::vector<Book>);

void mergeSort(std::vector<Book>& , int , int);
void merge(std::vector<Book>&, int, int, int);

void quickSort(std::vector<Book>&, int low, int high);
int partition(std::vector<Book>&, int low, int high);

void swapBooks(Book&, Book&);

#endif