#include "BookStore.cpp"

class Portal
{
private:
	string name;

public:
	vector<Book> books;
	// constructors
	Portal(){name = "PortalName";}
	Portal(string newName){name = newName;}
	
	~Portal(){ } //TODO

	// addBookStore will gather all the books from all the bookstores
	void addBookStore(BookStore bookStore)
	{
		//TODO
	}

	//searchCheapestBook will return pointer to cheapest book
	// and print out book info
	Book* searchCheapestBook(string bookName)
	{
		//TODO
	}

	// prints out all the books in the portal in alphabetic order
	// and the number of items that are duplicate
	void print()
	{
		//TODO
	}
};