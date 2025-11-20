#include "Book.h"
#include<string>
#include <iomanip>
#include <iostream>
#include<set>
using namespace std;
set<int> Book::bookId;
set<string> Book::bookISBNs;
Book::Book() {}
Book::Book(int id, string title, string author, string ISBN, string genre,int borrowCount , bool available)
	:id(id), title(title), author(author), ISBN(ISBN), genre(genre), available(available), borrowCount(0) { }
void Book::setId(int id)
{
	this->id = id;
}
void Book::setTitle(string title)
{
	this->title = title;
}
void Book::setAuthor(string author)
{
	this->author = author;
}
void Book::setISBN(string ISBN)
{
	this->ISBN = ISBN;
}
void Book::setGenre(string genre)
{
	this->genre = genre;
}
void Book::setAvailability(bool available)
{
	this->available = available;
}
int Book::getId()  const
{
	return id;
}
string Book::getTitle() const
{
	return title;
}
string Book::getAuthor() const
{
	return author;
}
string Book::getISBN() const
{
	return ISBN;
}
string Book::getGenre() const
{
	return genre;
}
bool Book::getAvailability() const
{
	return available;
}
int Book::getBorrowCount() const
{
	return borrowCount;
}
void Book::incrementBorrowCount()
{
	borrowCount++;
}
void Book::displayTableHeader()
{
	cout << "+-------------------------------------------------------------------------------------------------------------+\n";
	cout << "-" << left << setw(4) << "ID"
		<< "- " << setw(18) << "Title"
		<< "-" << setw(18) << "Author"
		<< "-" << setw(16) << "ISBN"
		<< "-" << setw(18) << "Genre"
		<< "-" << setw(12) << "Available"
		<< "-" << setw(8) << "Borrow Counter" << "\n";
	cout << "---------------------------------------------------------------------------------------------------------------\n";
}
void Book::displayBookInfo() const
{
	cout << " ." << left << setw(4) << id
		<< " ." << setw(18) << title
		<< " ." << setw(18) << author
		<< " ." << setw(16) << ISBN
		<< " ." << setw(18) << genre
		<< " ." << setw(12) << (available ? "Yes" : "No")
		<< " ." << setw(8) << borrowCount << "\n";
	cout << "+-------------------------------------------------------------------------------------------------------------+\n";
}
void Book::readData()
{
	int tempId;
	string tempISBN;
	while (true)
	{
		cout << "Enter Book Id\n";
		cin >> tempId;
		if (cin.fail() || tempId < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR ! Please , Enter A Vaild Non-negtive Integer \n";
			continue;
		}
		if (bookId.find(tempId) == bookId.end())
		{
			id = tempId;
			bookId.insert(tempId);
			break;
		}
		else
		{
			cout << "ERROR ! A Book With This ID Already Exists . Try Again \n";
		}
	}
	cin.ignore();
	cout << "Enter Book Title\n";
	getline(cin, title);
	cout << "Enter Author Name \n";
	getline(cin, author);
	while (true)
	{
		cout << "Enter Book ISBN\n";
		getline(cin, tempISBN);
		if (bookISBNs.find(tempISBN) == bookISBNs.end())
		{
			ISBN = tempISBN;
			bookISBNs.insert(tempISBN);
			break;
		}
		else
		{
			cout << "ERROR ! A Book With This ISBN Already Exists . Try Again \n";
		}
	}
	cout << "Enter Book Genre\n";
	getline(cin, genre);
	cout << "Enter Availability(1 For Available, 0 For Borrowed) \n";
	cin >> available;
	while (cin.fail() || (available != 0 && available != 1))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR ! Please , Enter (1 For Available , 0 For Borrowed) \n";
		cin >> available;
	}
	cout << "Enter Borrow Count (0 If The Book Is Addded For The First Time, Borrow Count) \n";
	cin >> borrowCount;
	if (available == false && borrowCount == 0)
	{
		borrowCount++;
	}
	while (cin.fail() || borrowCount < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR ! Please , Enter A Vaild Non-negative Number \n";
		cin >> borrowCount;
	}
}
Book::~Book() {}