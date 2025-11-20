#pragma once
#include <iostream>
#include"Book.h"
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
template<typename T>
struct Node
{
	T item;
	Node* next;
	Node* previous;
	Node(T element) :item(element), next(nullptr), previous(nullptr) {}
};
template<typename T>
class DoubleLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int lenght;
public:
	DoubleLinkedList() :head(nullptr), tail(nullptr), lenght(0) {}
	bool isEmpty() const 
	{
		return (head == nullptr);
	}
	void insertFirst(T element)
	{
		Node<T>* newNode = new Node<T>(element);
		newNode->previous = nullptr;
		if (isEmpty()) 
		{
			head = tail = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
		}
		lenght++;
	}
	void insertLast(T element)
	{
		Node<T>* newNode = new Node<T>(element);
		newNode->next = nullptr;
		if (isEmpty())
		{
			head = tail = newNode;
			newNode->previous = nullptr;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		lenght++;
	}
	void insertAtPosition(T element, int position)
	{
		if (position == 0)
		{
			insertFirst(element);
			return;
		}
		else if (position == lenght)
		{
			insertLast(element);
			return;
		}
		else if (position < 0 || position > lenght)
		{
			cout << "Out Of Range , Please Enter Position From 0 To " << lenght << endl;
			return;
		}
		Node<T>* newNode = new Node<T>(element);
		Node<T>* current = head;
		for (int i = 1; i < position; i++)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next->previous = newNode;
		current->next = newNode;
		newNode->previous = current;
		lenght++;
	}
	void removeFirst()
	{
		if (isEmpty())
		{
			cout << "The List Is Empty , Can't Remove \n";
			return;
		}
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			lenght = 0;
			return;
		}
		Node<T>* current = head;
		head = head->next;
		head->previous = nullptr;
		current->next = nullptr;
		delete current;
		lenght--;
	}
	void removeLast()
	{
		if (isEmpty())
		{
			cout << "The List Is Empty , Can't Remove \n";
			return;
		}
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			lenght = 0;
			return;
		}
		Node<T>* current = tail;
		tail = tail->previous;
		tail->next = nullptr;
		current->previous = nullptr;
		delete current;
		lenght--;
	}
	void removeAtPosition(int position)
	{
		if (isEmpty())
		{
			cout << "The List is Empty , Can't Remove \n";
			return;
		}
		if (position == 0)
		{
			removeFirst();
			return;
		}
		if (position == lenght - 1)
		{
			removeLast();
			return;
		}
		if (position < 0 || position >= lenght)
		{
			cout << "Out Of Range , Please Enter Position From 0 To " << lenght << endl;
			return;
		}
		Node<T>* temp = head;
		Node<T>* current = head->next;
		for (int i = 1; i < position; i++)
		{
			temp = current;
			current = current->next;
		}
		temp->next = current->next;
		current->next->previous = temp;
		current->next = current->previous = nullptr;
		delete current;
		lenght--;
	}
	int linerSearch(T element)
	{
		Node<T>* current = head;
		int index = 0;
		while (current != nullptr)
		{
			if (current->item == element)
			{
				return index;
			}
			current = current->next;
			index++;
		}
		return -1;
	}
	string toLowerCase(const string& str)
	{
		string result = str;
		transform(result.begin(), result.end() , result.begin(), ::tolower);
		return result;
	}
	vector<Book> search(const string& query, int searchType)
	{
		vector<Book> results;
		Node<Book>* temp = head;
		string lowerQuery = toLowerCase(query);
		while (temp)
		{
			string title = toLowerCase(temp->item.getTitle());
			string genre = toLowerCase(temp->item.getGenre());
			string author = toLowerCase(temp->item.getAuthor());
			if ((searchType == 1 && title.find(lowerQuery) != string::npos) ||
				(searchType == 2 && genre.find(lowerQuery) != string::npos) ||
				(searchType == 3 && author.find(lowerQuery) != string::npos))
			{
				results.push_back(temp->item);
			}

			temp = temp->next;
		}
		return results;
	}
	void reverse()
	{
		if (!head || !head->next)
		{
			return;
		}
		Node<T>* current = head;
		Node<T>* temp = nullptr;
		while (current)
		{
			temp = current->previous;
			current->previous = current->next;
			current->next = temp;
			current = current->previous;
		}
		if (temp)
		{
			tail = head;
			head = temp->previous;
		}
	}
	void sort()
	{
		if (!head || !head->next)
		{

			return;
		}
		bool swapped;
		Node<T>* ptr;
		Node<T>* last = nullptr;
		do
		{
			swapped = false;
			ptr = head;

			while (ptr->next != last)
			{
				if (ptr->item > ptr->next->item)
				{
					std::swap(ptr->item, ptr->next->item);
					swapped = true;
				}
				ptr = ptr->next;
			}
			last = ptr;
		} while (swapped);
	}
	int getSize() const
	{
		return lenght;
	}
	Node<T>* begin() const
	{
		return head;
	}
	Node<T>* end() const
	{
		return tail;
	}
	Node<T>* next(Node<T>* X) const
	{
		return X->next;
	}
	Node<T>* previous(Node<T>* X) const
	{
		return X->previous;
	}
	T& get(int position) const
	{
		if (position < 0 || position >= lenght)
		{
			cout << "Out Of Range \n";
		}
		Node<T>* current = head;
		for (int i = 0; i < position; i++)
		{
			current = current->next;
		}
		return current->item;
	}
	void clear()
	{
		while (!isEmpty())
		{
			Node<T>* temp = head;
			head = head->next;
			temp->next = nullptr;
			delete temp;
			lenght--;
		}
		head = tail = nullptr;
		lenght = 0;
	}
	void printFirstToLast() const
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			current->item.displayBookInfo();
			current = current->next;
		}
		cout << endl;
	}
	void printLastToFirst() const
	{
		Node<T>* current = tail;
		while (current != nullptr)
		{
			current->item.displayBookInfo();
			current = current->previous;
		}
		cout << endl;
	}
	~DoubleLinkedList()
	{
		clear();
	}
};