#pragma once
#include "Pair.h"
#include "LinkedList.h"
template<class T1, class T2, class T3>
class PairListAlt : public LinkedList<Pair<T2, T3>>
{
public:
	PairListAlt();
	PairListAlt(T1 data);
	~PairListAlt();

	// Adds a pair of values to the linked list
	void addPair(T2 F, T3 S);
	// Gets the first value from the pair with the matching second value
	T2 getFirst(T3 S);
	// Gets the second value from the pair with teh matching first  value
	T3 getSecond(T2 F);
	// Deletes the pair with the matching values
	void deletePair(T2 F, T3 S);
	// Prints the entire list
	void printList() ;

	T1 find(T2 search) ;
	T1 find(T3 search) ;

};

template<class T1, class T2, class T3>
inline PairListAlt<T1, T2, T3>::PairListAlt()
{
}

template<class T1, class T2, class T3>
 PairListAlt<T1, T2, T3>::PairListAlt(T1 data)
{
	this->push_back(data);
}

 template<class T1, class T2, class T3>
 inline PairListAlt<T1, T2, T3>::~PairListAlt()
 {
 }

template<class T1, class T2, class T3>
void PairListAlt<T1, T2, T3>::addPair(T2 F, T3 S)
{
	Pair<T2, T3> node(F, S);
	this->push_back(node);
}

template<class T1, class T2, class T3>
T2 PairListAlt<T1, T2, T3>::getFirst(T3 S)
{
	Pair<T2, T3> node = this->enqeue();
	return node.getFirst();
}

template<class T1, class T2, class T3>
T3 PairListAlt<T1, T2, T3>::getSecond(T2 F)
{
	Pair<T2, T3> node = this->enqeue();
	return node.getSecond();
}

template<class T1, class T2, class T3>
void PairListAlt<T1, T2, T3>::deletePair(T2 F, T3 S)
{
	Pair<T2, T3> node = this->deleteNode();

	//(T1 F, T2 S);
}

template<class T1, class T2, class T3>
inline void PairListAlt<T1, T2, T3>::printList()
{
}

template<class T1, class T2, class T3>
T1 PairListAlt<T1, T2, T3>::find(T2 search)
{
	//Pair<T2, T3>* p = this->head;
	//while (p-> != search) p = p->next;


	//Pair<T2, T3> node = *p;
	return T1();
}

template<class T1, class T2, class T3>
T1 PairListAlt<T1, T2, T3>::find(T3 search)
{
	return T1();
}
