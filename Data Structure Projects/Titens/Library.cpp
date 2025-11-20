#include "Library.h"
#include"DLL.h"
#include "Book.h"
#include<string>
#include <iostream>
#include <iomanip>
#include<vector>
using namespace std;
Book book;
Library::Library() :numofBooks(0), numofAvailableBooks(0), numofBorrowedBooks(0) {}
void Library::addBook(const Book& newBook)
{
	booklist.insertLast(newBook);
	numofBooks++;
	if (newBook.getAvailability() == false)
	{
		numofBorrowedBooks++;
	}
	else
	{
		numofAvailableBooks++;
	}
	cout << "Book Added Successfully '" << newBook.getTitle() << "'" << endl;
}
void Library::removeBook(const string& bookISBN)
{
	bool bookFound = false;
	for (int position = 0; position < booklist.getSize(); position++)
	{
		if (booklist.get(position).getISBN() == bookISBN)
		{
			string bookTitle = booklist.get(position).getTitle();
			int bookID = booklist.get(position).getId();
			bookFound = true;
			booklist.removeAtPosition(position);
			numofBooks--;
			numofAvailableBooks--;
			Book::bookISBNs.erase(bookISBN);
			Book::bookId.erase(bookID);
			cout << "Book Removed Successfully '" << bookTitle << "'" << endl;
			break;
		}
	}
	if (!bookFound)
	{
		cout << "The Book With ISBN '" << bookISBN << "' Not Found" << endl;
	}
}
void Library::borrowBook(const string& bookTitle)
{
	bool bookFound = false;
	for (int position = 0; position < booklist.getSize(); position++)
	{
		string Tilte = booklist.get(position).getTitle();
		string titleBorrow = booklist.toLowerCase(Tilte);
		if (titleBorrow == booklist.toLowerCase(bookTitle))
		{
			bookFound = true;
			if (booklist.get(position).getAvailability())
			{
				booklist.get(position).setAvailability(false);
				numofBorrowedBooks++;
				numofAvailableBooks--;
				booklist.get(position).incrementBorrowCount();
				cout << "You Have Succesfully Borrowed '" << bookTitle << "'" << endl;
			}
			else
			{
				cout << "The Book '" << bookTitle << "' Is Already Borrowed" << endl;
			}
		}
	}
	if (!bookFound)
	{
		cout << "The Book With Title '" << bookTitle << "' Not Found" << endl;
	}
}
void Library::returnBook(const string& bookTitle)
{
	bool bookFound = false;
	bool wasBorrowed = false;
	for (int position = 0; position < booklist.getSize(); position++)
	{
		string Tilte = booklist.get(position).getTitle();
		string titleReturn = booklist.toLowerCase(Tilte);
		if (titleReturn == booklist.toLowerCase(bookTitle))
		{
			bookFound = true;
			if (!booklist.get(position).getAvailability())
			{
				wasBorrowed = true;
				booklist.get(position).setAvailability(true);
				numofAvailableBooks++;
				numofBorrowedBooks--;
				cout << "The Book '" << bookTitle << "' Has Been Returned Successfully" << endl;
				break;
			}
		}
	}
	if (!bookFound)
	{
		cout << "Book Not Found In The Library" << endl;
	}
	else if (!wasBorrowed)
	{
		cout << "The Book '" << bookTitle << "' Was Not Borrowed" << endl;
	}
}
void Library::updateBook(const string& bookTitle)
{
	bool bookFound = false;
	for (int position = 0; position < booklist.getSize(); position++)
	{
		string Tilte = booklist.get(position).getTitle();
		string titleUpdata = booklist.toLowerCase(Tilte);
		if (titleUpdata == booklist.toLowerCase(bookTitle))
		{
			string bookISBN = booklist.get(position).getISBN();
			int  bookID= booklist.get(position).getId();
			bookFound = true;
			cout << "Book Found : Enter The New Details" << endl;
			Book::bookISBNs.erase(bookISBN);
			Book::bookId.erase(bookID);
			booklist.get(position).readData();
			cout << "Book Details Updated Successfully" << endl;
			Book::displayTableHeader();
			booklist.get(position).displayBookInfo();
			break;
		}

	}
	if (!bookFound)
	{
		cout << "Book with title '" << bookTitle << "' not found in the library." << endl;
	}
}
void Library::searchBook(const string& query, int searchType) 
{
	vector<Book> results = booklist.search(query, searchType);
	if (results.empty()) 
	{
		cout << "No Books Found Matching \"" << query << "\"\n";
		return;
	}
	cout << "Books Found Matching: " << query << endl;
	Book::displayTableHeader();
	for (const Book& book : results) 
	{
		book.displayBookInfo();
	}
}
void Library::statisticsBook()
{
	cout << "\n+----------------------------- Library Statistics -----------------------------+\n";
	cout << "-" << left << setw(25) << "Total Books"
		<< "-" << setw(25) << "Borrowed Books"
		<< "-" << setw(25) << "Available Books" << "\n";
	cout << "-------------------------------------------------------------------------------\n";

	cout << " " << left << setw(25) << numofBooks
		<< " " << setw(25) << numofBorrowedBooks
		<< " " << setw(25) << numofAvailableBooks << "\n";
	cout << "+-----------------------------------------------------------------------------+\n";
}
void Library::sortBook(int Choice)
{
	if (booklist.isEmpty())
	{
		std::cout << "No Books Available To Sort.\n";
		return;
	}
	bool swapped;
	do
	{
		swapped = false;
		Node<Book>* current = booklist.begin();
		while (current && current->next)
		{
			Node<Book>* nextNode = current->next;
			if (Choice == 1)
			{
				if (current->item.getId() > nextNode->item.getId() ||
					(current->item.getId() == nextNode->item.getId() && current->item.getBorrowCount() < nextNode->item.getBorrowCount()))
				{
					swap(current->item, nextNode->item);
					swapped = true;
				}
			}
			else if (Choice == 2)
			{
				if (current->item.getBorrowCount() < nextNode->item.getBorrowCount() ||
					(current->item.getBorrowCount() == nextNode->item.getBorrowCount() && current->item.getId() > nextNode->item.getId()))
				{
					swap(current->item, nextNode->item);
					swapped = true;
				}
			}
			current = current->next;
		}
	} while (swapped);
	cout << "Books Sorted Successfully\n";
}
void Library::veiwBooks()
{
	if (booklist.isEmpty())
	{
		cout << "Library Is Empty First Added Book\n";
		return;
	}
	Book::displayTableHeader();
	booklist.printFirstToLast();
}
Library::~Library() {}