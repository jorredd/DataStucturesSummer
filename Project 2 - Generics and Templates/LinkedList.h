// Jordan Redd
// CSIS 123A-3488
// 6/16/2019
// Prof. Stevenson
// Assignment 2
/* Description:
	Is a container class that can hold any type of data. Can function well with primitive types but once complex types get added you will need to make a new specialized class derived from this.
*/
#pragma once
#include<exception> 
using std::exception;
#include<string> 
using std::string;
#include<vector> 
using std::vector;
#include<iostream>
using std::cout;
using std::endl;

//struct that will hold amd link all the values being passed to the LinkedList class
template<class T>
struct Node {
	T data;
	Node* next;
};


template<class T>
class LinkedList
{
public:
	LinkedList() {};
	LinkedList(T data) { push_back(data); };
	~LinkedList();

protected:
	Node<T>* head = NULL;
	Node<T>* pointer;
public:
	// Adds node to the front of the list
	void push(T data);

	// Adds a new node to the linked list
	void push_back(T data);

	// Inserts a node at the given parameters
	void insert(string search, T data);
	void insert(int search, T data);

	// Delets a node at the given parameters
	void deleteNode(string search);
	void deleteNode(int search);

	// Prints the data of all the nodes in the list
	void printList();

	// Finds a specified Node based on search parameters	
	T find(int search);
	T find(string search);
	// returns the back of the LinkedList
	T pop();
	// Returns the first item put into the list
	T enqeue();

};

template<class T>
LinkedList<T>::~LinkedList()
{
}

// Adds node to the front of the list
template<class T>
void LinkedList<T>::push(T data)
{
	if (this->head == NULL)
	{
		this->push_back(data);
	}
	else {
		Node<T>* p = this->head; // this is pointing at the head NODE

		//Creates the new node
		Node<T>* n = new Node<T>();
		n->data = data;
		n->next = p;
	}
}

// Adds a new node to the linked list
template<class T>
void LinkedList<T>::push_back(T data)
{
	if (this->head == NULL)
	{
		this->head = new Node<T>();
		this->head->data = data;
		this->head->next = NULL;
	}
	else {
		Node<T>* p = this->head; // this is pointing at the head NODE

		while (p->next != NULL) p = p->next; //Transverse the list until you hit the end

		//Creates the new node
		Node<T>* n = new Node<T>();
		n->data = data;
		n->next = NULL;

		//Make the current next pointer equal to the new node created
		p->next = n;
	}
}

// Inserts a node {AFTER}  the given parameters
template<class T>
void LinkedList<T>::insert(string search, T data) //This will not work with complex types but will only work with primitive types.
{
	Node<T>* p = this->head; // this is pointing at the head NODE
	while (p->data != search) p = p->next;

	//Creates the new node
	Node<T>* n = new Node<T>();
	n->data = data;
	n->next = p->next;

	//Make the current next pointer equal to the new node created
	p->next = n;

}

// Inserts a node {AFTER}  the given parameters
template<class T>
void LinkedList<T>::insert(int search, T data)
{
	Node<T>* p = this->head; // this is pointing at the head NODE
	while (p->data != search) p = p->next;

	//Creates the new node
	Node<T>* n = new Node<T>();
	n->data = data;
	n->next = p->next;

	//Make the current next pointer equal to the new node created
	p->next = n;

}

// Delets a node at the given parameters
template<class T>
void LinkedList<T>::deleteNode(string search)
{
	Node<T>* p = this->head;
	while (p->data != search) p = p->next;
	Node<T>* delPtr = p->next;

	p->next = p->next->next;
	delete delPtr;
}
// Delets a node at the given parameters
template<class T>
void LinkedList<T>::deleteNode(int search)
{
	Node<T>* p = this->head;
	while (p->data != search) p = p->next;
	Node<T>* delPtr = p->next;

	p->next = p->next->next;
	delete delPtr;
}

// Finds a specified Node based on search parameters
template<class T>
T LinkedList<T>::find(int search)
{
	Node<T>* p = this->head;
	while (p->data != search) p = p->next;
	return *p;
}

// Finds a specified Node based on search parameters
template<class T>
T LinkedList<T>::find(string search)
{
	Node<T>* p = this->head;
	while (p->data != search) p = p->next;
	return *p;
}

// returns the back of the LinkedList
template<class T>
T LinkedList<T>::pop()
{
	if (this->head == NULL)
	{
		throw new exception("LinkedList is Empty");
	}
	else {
		Node<T>* p = this->head; // this is pointing at the head NODE

		while (p->next != NULL) p = p->next; //Transverse the list until you hit the end
		return p;
	}
}

// Returns the first item put into the list
template<class T>
T LinkedList<T>::enqeue()
{
	if (this->head == NULL)
	{
		throw new exception("LinkedList is Empty");
	}
	else {
		return this->head;
	}
}

// Prints the data of all the nodes in the list
template<class T>
void LinkedList<T>::printList()
{
	Node<T>* p = this->head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}
