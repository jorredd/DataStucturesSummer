// Jordan Redd
// CSIS 123A-3488
// 6/16/2019
// Prof. Stevenson
// Assignment 6 Hash Tables
/* Description:
	Is a container class that can hold any type of data. Can function well with primitive types but once complex types get added you will need to make a new specialized class derived from this.
*/
#pragma once
#pragma region INCLUDES/USINGS
#include<exception> 
using std::exception;
#include<string> 
using std::string;
#include<vector> 
using std::vector;
#include<iostream>
using std::cout;
using std::endl;
#pragma endregion

#pragma region Header/Protoyping
//struct that will hold amd link all the values being passed to the LinkedList class
template<class T>
struct Node {
	T data;
	Node* next;
	Node* prev;
};


template<class T>
class DblyLinkedList
{
public:

#pragma region Constructors
	DblyLinkedList() {};
	DblyLinkedList(T data) { push_back(data); };
	~DblyLinkedList();
#pragma endregion

protected:

#pragma region Data
	Node<T>* head = NULL;
	Node<T>* pointer;
#pragma endregion

public:

#pragma region StackLike Functionality 
	// Adds node to the front of the list
	void push(T data);
	// returns the back of the LinkedList
	T peek();
	T pop();
	int LENGTH = 0;
#pragma endregion

#pragma region QueueLike Functionlity
	// Adds a new node to the linked list
	void push_back(T data);
	// Returns the first item put into the list
#pragma endregion


#pragma region Mutators
	// Inserts a node at the given parameters
	void insert(string search, T data);
	void insert(int search, T data);

	// Delets a node at the given parameters
	void deleteNode(string search);
	void deleteNode(int search);
#pragma endregion

#pragma region Getters
	// Finds a specified Node based on search parameters	
	T find(int search);
	T find(string search);
	T findIndex(string search);

	// Prints the data of all the nodes in the list
	void printList();
#pragma endregion


};


#pragma endregion

#pragma region Mutators Definitions

// Inserts a node {AFTER}  the given parameters
template<class T>
void DblyLinkedList<T>::insert(string search, T data) //This will not work with complex types but will only work with primitive types.
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
void DblyLinkedList<T>::insert(int search, T data)
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
void DblyLinkedList<T>::deleteNode(string search)
{
	Node<T>* p = this->head;
	while (p->data != search) p = p->next;
	Node<T>* delPtr = p->next;

	p->next = p->next->next;
	delete delPtr;
}
// Delets a node at the given parameters
template<class T>
void DblyLinkedList<T>::deleteNode(int search)
{
	Node<T>* p = this->head;
	while (p->data != search) p = p->next;
	Node<T>* delPtr = p->next;

	p->next = p->next->next;
	delete delPtr;
}


// Returns the first item put into the list
template<class T>
T DblyLinkedList<T>::pop()
{
	if (this->head == NULL)
	{
		throw new exception("LinkedList is Empty");
	}
	else {

		Node<T>* p = new Node<T>();
		Node<T>* tmp = this->head;
		Node<T> ret = *tmp;
		Node<T>* delPtr = this->head;

		p->data = tmp->next->data;
		p->next = tmp->next->next;
		p->prev = NULL;
		this->head = p;

		delete delPtr;

		return ret.data;
	}
}

#pragma endregion

#pragma region Getters Definitions


// Finds a specified Node based on search parameters
template<class T>
T DblyLinkedList<T>::find(int search)
{
	Node<T>* p = this->head;
	while (p->data != search) p = p->next;
	return p->data;
}

// Finds a specified Node based on search parameters
template<class T>
T DblyLinkedList<T>::find(string search)
{
	Node<T>* p = this->head;
	while (p->data != search) p = p->next;
	return p->data;
}

// Finds a specified Node based on search parameters
template<class T>
T DblyLinkedList<T>::findIndex(string search)
{
	
	Node<T>* p = this->head;
	while (p->next != NULL) {
		while (p->data.find(search) == -1) p = p->next;
	}
	return p->data;
}

// Prints the data of all the nodes in the list
template<class T>
void DblyLinkedList<T>::printList()
{
	Node<T>* p = this->head;
	if (p == NULL) return;
	//while (p->next != NULL)
	//{
	//	cout << this->peek() << endl;
	//	p = p->next;
	//}
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

#pragma endregion

#pragma region QueueLike Functionality Definitions

// Adds a new node to the linked list
template<class T>
void DblyLinkedList<T>::push_back(T data)
{
	if (this->head == NULL)
	{
		this->push(data);
		LENGTH++;
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
		//Make the previous node equal to the previous Node
		n->prev = p;
		LENGTH++;
	}
}
#pragma endregion

#pragma region StackLike Functionality Definitions


// Adds node to the front of the list
template<class T>
void DblyLinkedList<T>::push(T data)
{
	if (this->head == NULL)
	{

		this->head = new Node<T>();
		this->head->data = data;
		this->head->next = NULL;
		this->head->prev = NULL;
		LENGTH++;
	}
	else {
		Node<T>* p = this->head; // this is pointing at the head NODE

		while (p->next != NULL) p = p->next; //Transverse the list until you hit the end

		//Creates the new node
		Node<T>* n = new Node<T>();
		n->data = data;
		n->next = this->head;
		this->head = n;

		n->prev = this->head;
		n->next->prev = this->head;
		this->head->prev = NULL;
		LENGTH++;
	}
}

// Returns the first item put into the list
template<class T>
T DblyLinkedList<T>::peek()
{
	if (this->head == NULL)
	{
		throw new exception("LinkedList is Empty");
	}
	else {
		return this->head->data;
	}
}


#pragma endregion

#pragma region deconstructor definition
template<class T>
DblyLinkedList<T>::~DblyLinkedList()
{
}
#pragma endregion


