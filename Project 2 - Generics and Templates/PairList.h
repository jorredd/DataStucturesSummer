#pragma once
#include "LinkedList.h"
#include "Pair.h"
#include<exception> 
using std::exception;
#include<string> 
using std::string;
#include<vector> 
using std::vector;


template<class T1>
class PairList : public LinkedList<T1>
{
public:
	PairList();
	PairList(T1 data);
	~PairList();
	// Adds a pair of values to the linked list
	void addPair(T1 data);
	// Gets the first value from the pair with the matching second value
	T1 getFirst();
	// Gets the second value from the pair with teh matching first  value
	T1 getSecond();
	// Deletes the pair with the matching values
	void deletePair();
	// Prints the entire list
	void printList();
};

template<class T1>
PairList<T1>::PairList()
{
}
template<class T1>
PairList<T1>::PairList(T1 data)
{
	this->addPair(data);
}


template<class T1>
PairList<T1>::~PairList()
{
}

// Adds a pair of values to the linked list
template<class T1>
void PairList<T1>::addPair(T1 data)
{
	this->push_back(data);
}

// Gets the first value from the pair with the matching second value
template<class T1>
T1 PairList<T1>::getFirst()
{
	Node<T1>* tmp = this->enqeue();

	//return tmp->data->
	// TODO: Add your implementation code here.
	return T1();
}

// Gets the second value from the pair with teh matching first  value
template<class T1>
T1 PairList<T1>::getSecond()
{
	// TODO: Add your implementation code here.
	return T1();
}

// Deletes the pair with the matching values
template<class T1>
void PairList<T1>::deletePair()
{
	// TODO: Add your implementation code here.
	return T1();
}

// Prints the entire list
template<class T1>
void PairList<T1>::printList()
{
	// TODO: Add your implementation code here.
}

//TODO: FINISH THIS CLASS AND CLEAN UP CODE. Possivly add some exceptions and namespaces. Also, comment all items