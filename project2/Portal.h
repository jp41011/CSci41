#ifndef PORTAL_H
#define PORTAL_H
#include <string>
#include "Book.h"
#include "BookStore.h"

class Portal
{
private:
	std::string portalName;

public:
	std::vector<Book> books;

	Portal();
	Portal(std::string);
	~Portal();

	void addBookStore(BookStore);
	Book* searchCheapestBook(std::string);
	void print();
};

#endif