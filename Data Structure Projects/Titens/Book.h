#pragma once
#include <iostream>
#include<set>
using namespace std;
class Book
{
private:
	int id, borrowCount;
	string title, author, ISBN, genre;
	bool available;
public:
	static set<int> bookId;
	static set<string> bookISBNs;
	Book();
	Book(int id, string title, string author, string ISBN, string genre,int borrowCount , bool available = true);
	void setId(int id);
	void setTitle(string title);
	void setAuthor(string author);
	void setISBN(string ISBN);
	void setGenre(string genre);
	void setAvailability(bool available);
	int getId()  const;
	string getTitle() const;
	string getAuthor() const;
	string getISBN() const;
	string getGenre() const;
	bool getAvailability() const;
	int getBorrowCount() const;
	void incrementBorrowCount();
	static void displayTableHeader();
	void displayBookInfo() const;
	void readData();
	~Book();
};

