// Jordan Redd
// CSIS 123A-3488
// 6/16/2019
// Prof. Stevenson
// Assignment 2
/* Description:
	Inherits from the LinkedList class and adds functionality specific for the needs of the Pair Class. 
*/
#pragma once
#include "LinkedList.h"
#include "Pair.h"
#include<exception> 
using std::exception;
#include<string> 
using std::string;
#include<vector> 
using std::vector;


template<class T>
class PairList : public LinkedList<Pair<T>>
{
public:
	PairList();
	PairList(T F, T S); //Creates the PairList and creates the a Pair then adds it to the list with the provided items
	PairList(Pair<T> data); // adds a Pair class to the list
	~PairList();
	// Adds a pair of values to the linked list
	void addPair(T F, T S);
	// Gets the first value from the pair with the matching second value
	T getFirst(T second);
	// Gets the second value from the pair with teh matching first  value
	T getSecond(T first);
	// Deletes the pair with the matching values
	void deletePair(T first, T second);
	// Prints the entire list
	void printList();
};
template<class T>
PairList<T>::PairList()
{
}
//Creates the PairList and creates the a Pair then adds it to the list with the provided items
template<class T>
PairList<T>::PairList(T F, T S)
{
	this->addPair(F, S);
}
// adds a Pair class to the list
template<class T>
PairList<T>::PairList(Pair<T> data)
{
	this->push_back(data);
}

// Adds a pair of values to the linked list
template<class T>
void PairList<T>::addPair(T F, T S)
{
	Pair<T>tmp(F,S);
	this->push_back(tmp);
}

// Gets the first value from the pair with the matching second value
template<class T>
T PairList<T>::getFirst(T second)
{
	this->pointer = this->head;
	while (this->pointer->data.getSecond() != second) this->pointer = this->pointer->next;
	Pair<T> pair = this->pointer->data;
	return pair.getFirst();
}

// Gets the second value from the pair with teh matching first  value
template<class T>
T PairList<T>::getSecond(T first)
{
	this->pointer = this->head;
	while (this->pointer->data.getFirst() != first) this->pointer = this->pointer->next;
	Pair<T> pair = this->pointer->data;
	return pair.getSecond();
}

// Deletes the pair with the matching values
template<class T>
void PairList<T>::deletePair(T first , T second)
{
	this->pointer = this->head;
	while (this->pointer->next->data.getFirst() != first && this->pointer->next->data.getSecond() != second)
	{
		if (this->pointer->data.getFirst() == first && this->pointer->data.getSecond() == second) break; //If the first value holds the searched values then it will break the loop here and then handle that condition in the condition below
		if (this->pointer->next->data.getFirst() == NULL || this->pointer->next->data.getSecond() == NULL) 	throw exception("Value Not Found"); // probably should be a cout instead of a exception.... But regardless this sends a message saying value not found
		this->pointer = this->pointer->next;
	}

	if (this->pointer->data.getFirst() == first && this->pointer->data.getSecond() == second) {
		this->head = this->pointer->next;
		this->pointer->next = this->pointer->next->next;
		return; // handles if the first value has the passed value and if it does finishes 
	}

	Node<Pair<T>>* delPtr = this->pointer->next;
	this->pointer->next = this->pointer->next->next;
	delete delPtr;
}

// Prints the entire list
template<class T>
void PairList<T>::printList()
{
	this->pointer = this->head;
	while (this->pointer != NULL)
	{
		cout << "Pairs: " << this->pointer->data.getFirst() << "," << this->pointer->data.getSecond() << endl;
		this->pointer = this->pointer->next;
	}
}
template<class T>
PairList<T>::~PairList()
{
}

//TODO: FINISH THIS CLASS AND CLEAN UP CODE. Possibly add some exceptions and namespaces. Also, comment all items