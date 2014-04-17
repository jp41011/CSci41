#include "Book.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

Book::Book()
{
	bookName = "BookName";
	publisher = "BookPublisher";
	publishYear = 0;
	price = 0;
	category = "BookCategory";
	store = "NoStore";
}

Book::Book(string Bname, string Bpublisher, int BpublishYear, double Bprice, string Bcategory)
{
	bookName = Bname;
	publisher = Bpublisher;
	publishYear = BpublishYear;
	price = Bprice;
	category = Bcategory;
	store = "NoStore";
}

Book::~Book(){ } // nothing to do 

void Book::setPrice(double newPrice){price = newPrice;}

void Book::setStore(string newStore){store = newStore;}

// Get functions
string Book::getName(){return bookName;}
string Book::getPublisher(){return publisher;}
int Book::getPublishYear(){return publishYear;}
double Book::getPrice(){return price;}
string Book::getCategory(){return category;}

void Book::info()
{
	cout << bookName << ", " << publisher << ", " << publishYear << ", $" << price << ", " << category << ", " << store << endl;
}