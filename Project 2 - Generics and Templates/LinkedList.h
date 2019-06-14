#pragma once
#include<exception> 
using std::exception;
#include<string> 
using std::string;
#include<vector> 
using std::vector;

template<class T1>
struct Node {
	T1 data;
	Node* next;
};


template<class T1>
class LinkedList
{
public:
	LinkedList(){};
	LinkedList(T1 data) { addNode(data); };
	~LinkedList();

protected:
	Node<T1>* head = NULL;
	Node<T1>* pointer;
public:
	// Adds a new node to the linked list
	void addNode(T1 data);

	// Inserts a node at the given parameters
	void insert(string search, T1 data);	
	void insert(T1 search, T1 data);	
	void insert(int search, T1 data);
	// Delets a node at the given parameters
	void deleteNode();

	// Prints the data of all the nodes in the list
	void printList();
};

template<class T1>
LinkedList<T1>::~LinkedList()
{
}

// Adds a new node to the linked list
template<class T1>
void LinkedList<T1>::addNode(T1 data)
{
	if(head == NULL)
	{
		head = new Node<T1>();
		head->data = data;
		head->next = NULL;
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

// Inserts a node {AFTER}  the given parameters
template<class T1>
void LinkedList<T1>::insert(T1 search, T1 data)
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
void LinkedList<T1>::deleteNode()
{
	// TODO: Add your implementation code here.
}

// Prints the data of all the nodes in the list
template<class T1>
void LinkedList<T1>::printList()
{
	// TODO: Add your implementation code here.
}
