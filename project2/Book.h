#ifndef BOOK_H
#define BOOK_H

class Book
{
private:
	string name;
	string publisher;
	int publishYear;
	double price;
	string category;
public:
	// constructors
	Book();
	Book(string, string, int, double, string);
	// deconstructor
	~Book();

	// price should be the only thing that can change
	void setPrice(double);

	//get functions
	string getName();
	string getPublisher();
	int getPublishYear();
	double getPrice();
	string getCategory();
};

#endif