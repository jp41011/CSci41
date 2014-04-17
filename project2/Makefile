all: Book.o BookStore.o Portal.o Sorts.o project2.0 p2

Book.o: Book.h Book.cpp
	g++ -c Book.cpp -o Book.o

BookStore.o: BookStore.h BookStore.cpp
	g++ -c BookStore.cpp -o BookStore.o

Portal.o: Portal.h Portal.cpp
	g++ -c Portal.cpp -o Portal.o

Sorts.o: Sorts.h Sorts.cpp
	g++ -c Sorts.cpp -o Sorts.o

project2.0: project2.cpp
	g++ -c project2.cpp -o project2.o

p2: project2.o Sorts.o Portal.o BookStore.o Book.o
	g++ project2.o Sorts.o Portal.o BookStore.o Book.o -o project2