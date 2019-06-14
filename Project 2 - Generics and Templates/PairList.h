#pragma once
#include "LinkedList.h"

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
	~PairList();
	// Adds a pair of values to the linked list
	void addPair();
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
PairList<T1>::~PairList()
{
}

// Adds a pair of values to the linked list
template<class T1>
void PairList<T1>::addPair()
{
	// TODO: Add your implementation code here.
}

// Gets the first value from the pair with the matching second value
template<class T1>
T1 PairList<T1>::getFirst()
{
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
