#include "BookStore.h"
#include "Book.h"
#include "Sorts.h"
#include <iostream>

using std::string;
using std::vector;

// constructors
BookStore::BookStore(){bookStoreName = "BookStore";}
BookStore::BookStore(string newName){bookStoreName = newName;}

BookStore::~BookStore(){books.resize(0);}

// add book to the set of books in this book store
void BookStore::addBook(Book b)
{
	b.setStore(bookStoreName);
	books.push_back(b);
}

// Returns all books sorted by publish year newest to oldest
vector<Book> BookStore::getBooks()
{
	vector<Book> sortedBooks = sortByYear(books);
	return sortedBooks;
}

vector<Book> BookStore::sortByPrice()
{
	vector<Book> sortedBooks = sortPrice(books);
	return sortedBooks;
}

// returns  a copy of the oldest book in the store
Book BookStore::oldestBook()
{
	if(books.empty() == true)
	{
		std::cout << "Book Store: " << bookStoreName << " is empty." << std::endl;
		Book empty = Book("empty", "empty", 0, 0, "empty");
		return empty;
	}
	int oldestYear = books[0].getPublishYear();
	unsigned int oldestIndex = 0;  
	for(unsigned int i=1; i < books.size(); i++)
	{
		if(books[i].getPublishYear() < oldestYear)
		{
			oldestYear = books[i].getPublishYear();
			oldestIndex = i;
		}
	}
	return books[oldestIndex];
}

string BookStore::getName(){return bookStoreName;}