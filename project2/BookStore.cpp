#include <vector>
#include "Book.cpp"
#include "Sorts.cpp"

class BookStore
{
private:
	string name;

public:
	vector<Book> books;
	// constructors
	BookStore(){name = "BookStore";}
	BookStore(string newName){name = newName;}
	
	~BookStore(){ } //TODO

	// add a book to bookstore
	void addBook(Book b){books.push_back(b);}
	
	// returns a vector of books sorted based on publish year newest to oldest
	vector<Book> getBooks()
	{
		//TODO
	}

	// returns vector<Book> sorted by price - lowest to highest
	vector<Book> sortByPrice()
	{
		//TODO
	}

	Book oldestBook()
	{
		//TODO
	}
};