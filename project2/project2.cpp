#include <iostream>
#include "Book.h"
#include "BookStore.h"
#include "Portal.h"
#include "Sorts.h"

using namespace std;

int main()
{
	cout << "Juan Pedraza - CSCI 41 Project 2" << endl;
	cout << "Create Books" << endl;
	Book book1 = Book("Harry Potter", "Landon", 2009, 20.5, "fiction");
	Book book2 = Book("Finding Nemo", "Disney", 2007, 15.5, "children");
	Book book3 = Book("Harry Potter", "Landon", 2009, 15.5, "fiction");
	Book book4 = Book("Finding Nemo", "Disney", 2008, 22.5, "children");
	Book book5 = Book("Data Structure", "Addison", 2011, 60, "text");
	Book book6 = Book("Algorithms", "Weley", 2007, 79.5, "text");
	Book book7 = Book("Old Man and Sea", "Penquin", 1976, 12, "fiction");
	Book book8 = Book("Bill Clinton", "Penquin", 2005, 50, "autobiography");
	Book book9 = Book("Bill Clinton", "Penquin", 2006, 61.5, "autobiography");
	Book book10 = Book("Compiler", "Geek", 2001, 40.5, "text");
	cout << "-----------------------------------------------" << endl;
	cout << "Create Amazon store and add books to store" << endl;
	BookStore bstore1 = BookStore("Amazon");
	bstore1.addBook(book1);
	bstore1.addBook(book2);
	bstore1.addBook(book5);
	bstore1.addBook(book6);
	bstore1.addBook(book9);
	cout << "Oldest Book in " << bstore1.getName() << endl << "\t";
	Book oldest = bstore1.oldestBook();
	oldest.info();
	cout << "-----------------------------------------------" << endl;
	cout << "Create Ebay Store and add books to store" << endl;
	BookStore bstore2 = BookStore("Ebay");
	bstore2.addBook(book3);
	bstore2.addBook(book4);
	bstore2.addBook(book7);
	bstore2.addBook(book8);
	bstore2.addBook(book10);
	cout << "-----------------------------------------------" << endl;
	cout << "Create Portal and add bookstores" << endl;
	Portal portal = Portal("onlinePortal");
	portal.addBookStore(bstore1);
	portal.addBookStore(bstore2);
	cout << "Total books in portal: " << portal.books.size() << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Cheapest Harry Potter Book:" << endl;
	portal.searchCheapestBook("Harry Potter");
	cout << "-----------------------------------------------" << endl;
	cout << "Print all books in portal" << endl;
	portal.print();
	
	return 0;
}