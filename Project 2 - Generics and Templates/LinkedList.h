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


template<class T1>
struct Node {
	T1 data;
	Node* next;
};


template<class T1>
class LinkedList
{
public:
	LinkedList() {};
	LinkedList(T1 data) { push_back(data); };
	~LinkedList();

protected:
	Node<T1>* head = NULL;
	Node<T1>* pointer;
public:
	// Adds node to the front of the list
	void push(T1 data);

	// Adds a new node to the linked list
	void push_back(T1 data);

	// Inserts a node at the given parameters
	void insert(string search, T1 data);
	void insert(int search, T1 data);

	// Delets a node at the given parameters
	void deleteNode(string search);
	void deleteNode(int search);

	// Prints the data of all the nodes in the list
	void printList();


	// Finds a specified Node based on search parameters	
	T1 find(int search);
	T1 find(string search);
	// returns the back of the LinkedList
	T1 pop();
	// Returns the first item put into the list
	T1 enqeue();
};

template<class T1>
LinkedList<T1>::~LinkedList()
{
}

// Adds node to the front of the list
template<class T1>
void LinkedList<T1>::push(T1 data)
{
	if (this->head == NULL)
	{
		this->push_back(data);
	}
	else {
		Node<T1>* p = this->head; // this is pointing at the head NODE

		//Creates the new node
		Node<T1>* n = new Node<T1>();
		n->data = data;
		n->next = p;
	}
}

// Adds a new node to the linked list
template<class T1>
void LinkedList<T1>::push_back(T1 data)
{
	if (this->head == NULL)
	{
		this->head = new Node<T1>();
		this->head->data = data;
		this->head->next = NULL;
	}
	else {
		Node<T1>* p = this->head; // this is pointing at the head NODE

		while (p->next != NULL) p = p->next; //Transverse the list until you hit the end

		//Creates the new node
		Node<T1>* n = new Node<T1>();
		n->data = data;
		n->next = NULL;

		//Make the current next pointer equal to the new node created
		p->next = n;
	}
}

// Inserts a node {AFTER}  the given parameters
template<class T1>
void LinkedList<T1>::insert(string search, T1 data) //This will not work with complex types but will only work with primitive types.
{
	Node<T1>* p = this->head; // this is pointing at the head NODE
	while (p->data != search) p = p->next;

	//Creates the new node
	Node<T1>* n = new Node<T1>();
	n->data = data;
	n->next = p->next;

	//Make the current next pointer equal to the new node created
	p->next = n;

}

// Inserts a node {AFTER}  the given parameters
template<class T1>
void LinkedList<T1>::insert(int search, T1 data)
{
	Node<T1>* p = this->head; // this is pointing at the head NODE
	while (p->data != search) p = p->next;

	//Creates the new node
	Node<T1>* n = new Node<T1>();
	n->data = data;
	n->next = p->next;

	//Make the current next pointer equal to the new node created
	p->next = n;

}

// Delets a node at the given parameters
template<class T1>
void LinkedList<T1>::deleteNode(string search)
{
	Node<T1>* p = this->head;
	while (p->data != search) p = p->next;
	Node<T1>* delPtr = p->next;

	p->next = p->next->next;
	delete delPtr;
}
// Delets a node at the given parameters
template<class T1>
void LinkedList<T1>::deleteNode(int search)
{
	Node<T1>* p = this->head;
	while (p->data != search) p = p->next;
	Node<T1>* delPtr = p->next;

	p->next = p->next->next;
	delete delPtr;
}

// Finds a specified Node based on search parameters
template<class T1>
T1 LinkedList<T1>::find(int search)
{
	Node<T1>* p = this->head;
	while (p->data != search) p = p->next;
	return *p;
}

// Finds a specified Node based on search parameters
template<class T1>
T1 LinkedList<T1>::find(string search)
{
	Node<T1>* p = this->head;
	while (p->data != search) p = p->next;
	return *p;
}

// returns the back of the LinkedList
template<class T1>
T1 LinkedList<T1>::pop()
{
	if (this->head == NULL)
	{
		throw new exception("LinkedList is Empty");
	}
	else {
		Node<T1>* p = this->head; // this is pointing at the head NODE

		while (p->next != NULL) p = p->next; //Transverse the list until you hit the end
		return p;
	}
}

// Returns the first item put into the list
template<class T1>
T1 LinkedList<T1>::enqeue()
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
template<class T1>
void LinkedList<T1>::printList()
{
	Node<T1>* p = this->head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}
