#include"DLL.h"
#include"Book.h"
#include"Library.h"
#include <iostream>
#include<string>
#include <iomanip>
using namespace std;
int main()
{
	Library library;
	int choice;
	do
	{
		int width = 50;
		int screenWidth = 130;
		int padding = (screenWidth - width) / 2;
		string spaces = string(padding, ' ');
		string separator = string(width, '=');
		cout << spaces << "+=======================================================+\n";
		cout << spaces << "|      *****Library Management System****               |\n";
		cout << spaces << "=========================================================\n";
		cout << spaces << "| 1. Add A New Book To The Library                      |\n";
		cout << spaces << "| 2. Remove A Book From The Library                     |\n";
		cout << spaces << "| 3. Borrow A Book From The Library                     |\n";
		cout << spaces << "| 4. Return A Book To The Library                       |\n";
		cout << spaces << "| 5. Update Book Information                            |\n";
		cout << spaces << "| 6. Search For A Book                                  |\n";
		cout << spaces << "| 7. Sort The Library Books                             |\n";
		cout << spaces << "| 8. View Library Statistics                            |\n";
		cout << spaces << "| 9. View All Books                                     |\n";
		cout << spaces << "| 10. Exit                                              |\n";
		cout << spaces << "+=======================================================+\n";
		cout << "Enter Your Choice: ";
		cin >> choice;
		while (cin.fail() || choice < 0 || choice > 10)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR ! Please , Enter A Vaild Number Between (1 & 10) \n";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			Book newBook;
			newBook.readData();
			library.addBook(newBook);
			break;
		}
		case 2:
		{
			string bookISBN;
			cout << "Enter The Book ISBN Of The Book To Remove\n";
			cin.ignore();
			getline(cin, bookISBN);
			library.removeBook(bookISBN);
			break;
		}
		case 3:
		{
			string bookTitle;
			cout << "Enter The Book Tilte Of The Book To Borrow \n";
			cin.ignore();
			getline(cin, bookTitle);
			library.borrowBook(bookTitle);
			break;
		}
		case 4:
		{
			string bookTitle;
			cout << "Enter The Book Tilte Of The Book To Return\n";
			cin.ignore();
			getline(cin, bookTitle);
			library.returnBook(bookTitle);
			break;
		}
		case 5:
		{
			string bookTitle;
			cout << "Enter The Book Tilte Of The Book To Updata\n";
			cin.ignore();
			getline(cin, bookTitle);
			library.updateBook(bookTitle);
			break;
		}
		case 6:
		{
			int searchChoice;
			cout << "\t--- Search Choice ---\n";
			cout << "1. Title\n";
			cout << "2. Genre\n";
			cout << "3. Author\n";
			cout << "Enter Your Choice: ";
			cin >> searchChoice;
			while (cin.fail() || (searchChoice < 1 || searchChoice > 3)) 
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "ERROR! Please choose (1 - Title, 2 - Genre, 3 - Author): ";
				cin >> searchChoice;
			}
			string searchQuery;
			switch(searchChoice)
			{
			case 1:
				cout << "Enter The Book Tilte Of The Book To Search \n ";
				break;
			case 2:
				cout << "Enter The Book Genre Of The Book To Search \n ";
				break;
			case 3:
				cout << "Enter The Book Author Of The Book To Search \n ";
				break;
			}
			cin.ignore();
			getline(cin, searchQuery);
			library.searchBook(searchQuery, searchChoice);
			break;
		}
		case 7:
		{
			int sortChoice;
			cout << "\t--- Sort Books By ( Id ,Borrow Count ) ---\n \n";
			cout << "1.ID (ACS)\n";
			cout << "2.Borrow Count (DES) \n";
			cout << "Enter Your Choice \n";
			cin >> sortChoice;
			while (cin.fail() || (sortChoice != 1 && sortChoice != 2))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "ERROR ! Please , ( 1- For ID , 2- For Borrow Count )\n";
				cin >> sortChoice;
			}
			library.sortBook(sortChoice);
			break;
		}
		case 8:
		{
			library.statisticsBook();
			break;

		}
		case 9:
		{
			char viewSort;
			cout << "Do You Want To View Books Sorted (Y/N)\n";
			cin >> viewSort;
			if (viewSort == 'Y' || viewSort == 'y')
			{
				int sortChoice;
				cout << "\t--- Sort Books By ( Id ,Borrow Count ) ---\n \n";
				cout << "1.ID (ASC) \n";
				cout << "2.Borrow Count (DES) \n";
				cout << "Enter Your Choice \n";
				cin >> sortChoice;
				library.sortBook(sortChoice);
			}
			library.veiwBooks();
			break;
		}
		}

	} while (choice != 10);
	system("pause");
	return 0;
}