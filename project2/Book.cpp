#include "Book.h"

Book::Book()
{
	name = "BookName";
	publisher = "BookPublisher";
	publishYear = 0;
	price = 0
	category = "BookCategory";
}

Book::Book(string Bname, string Bpublisher, int BpublishYear, double Bprice, string Bcategory)
{
	name = Bname;
	publisher = Bpublisher;
	publishYear = BpublishYear;
	price = Bprice;
	category = Bcategory;
}

Book::~Book(){ } //TODO

void Book::setPrice(double newPrice){price = newPrice;}

string Book::getName(){return name;}
string Book::getPublisher(){return publisher;}
int Book::getPublishYear(){return publishYear;}
double Book::getPrice(){return price;}
string Book::getCategory(){return category;}