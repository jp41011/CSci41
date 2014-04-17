#include "Portal.h"
#include "BookStore.h"
#include "Sorts.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Portal::Portal(){portalName = "Portal";}
Portal::Portal(string newName){portalName = newName;}

Portal::~Portal(){books.resize(0);}

void Portal::addBookStore(BookStore bookstore)
{
	for(int i=0; i < bookstore.books.size(); i++)
	{
		books.push_back(bookstore.books[i]);
	}
}

Book* Portal::searchCheapestBook(string bookTitle)
{
	vector<Book> sortedPrice = sortPrice(books);
	for(int i=0; i < books.size(); i++)
	{
		if(sortedPrice[i].getName() == bookTitle)
		{
			Book* cheapestBook = &sortedPrice[i];
			cheapestBook->info();
			return cheapestBook;
		}
	}
}

void Portal::print()
{
	vector<Book> sortedAlpha = sortByName(books);
	for(int i=0; i<sortedAlpha.size(); i++)
	{
		cout << "Book " << i+1 << ": ";
		sortedAlpha[i].info();
	}
}