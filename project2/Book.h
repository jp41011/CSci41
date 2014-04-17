#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
private:
	std::string bookName;
	std::string publisher;
	int publishYear;
	double price;
	std::string category;
	std::string store;
public:
	// constructors
	Book();
	Book(std::string, std::string, int, double, std::string);
	// deconstructor
	~Book();

	// price should be the only thing that can change
	void setPrice(double);
	void setStore(std::string); // sets which store book belongs to

	//get functions
	std::string getName();
	std::string getPublisher();
	int getPublishYear();
	double getPrice();
	std::string getCategory();
	void info();
};

#endif