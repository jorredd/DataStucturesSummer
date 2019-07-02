// Jordan Redd
// CSIS 123A-3488
// 6/30/2019
// Prof. Stevenson
// Assignment 4
/* Description:
	Uses the Queue to create a Palindrome checker. This file has one method that handles evrything for this class
	The Parser() metho handles the Reading and Writing and Parses through the read text saving each Char to Stack
	and a Queue to be tested against.
*/
#pragma once
#include "LinkedList.h"

#pragma region HEADERS/PROTOTYPING
template<class T>
class Queue : protected DblyLinkedList<T>

{
public:
	Queue();
	~Queue();
#pragma region Getters
	T dequeue();
	T peek();
#pragma endregion

#pragma region Mutators
	void enqueue(T data);
#pragma endregion

};
#pragma endregion


template<class T>
Queue<T>::Queue()
{

}

template<class T>
Queue<T>::~Queue()
{

}


#pragma region Mutators Definitions
template<class T>
void Queue<T>::enqueue(T data)
{
	DblyLinkedList<T>::push_back(data);
}

template<class T>
T Queue<T>::dequeue()
{
	return DblyLinkedList<T>::pop();
}
#pragma endregion


#pragma region Getters Definition

template<class T>
T Queue<T>::peek()
{
	return DblyLinkedList<T>::peek();
}
#pragma endregion



