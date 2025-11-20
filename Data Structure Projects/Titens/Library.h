#pragma once
#include "Book.h"
#include"DLL.h"
#include <iostream>
#include<set>
using namespace std;
class Library
{
private:
	DoubleLinkedList<Book> booklist;
	int numofBooks, numofBorrowedBooks, numofAvailableBooks;
public:
	Library();
	void addBook(const Book& newBook);
	void removeBook(const string& bookTitle);
	void borrowBook(const string& bookTitle);
	void returnBook(const string& bookTitle);
	void updateBook(const string& bookTitle);
	void searchBook(const string& query, int searchType);
	void sortBook(int Choice);
	void statisticsBook();
	void veiwBooks();
	~Library();
};