#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include <string>
#include <vector>
#include "Book.h"

class BookStore
{
private:
	std::string bookStoreName;

public:
	std::vector<Book> books;
	// constructors
	BookStore();
	BookStore(std::string);
	
	~BookStore();

	// add a book to bookstore
	void addBook(Book b);
	
	// returns a vector of books sorted based on publish year newest to oldest
	std::vector<Book> getBooks();

	// returns vector<Book> sorted by price - lowest to highest
	std::vector<Book> sortByPrice();

	Book oldestBook();
	std::string getName();
};

#endif