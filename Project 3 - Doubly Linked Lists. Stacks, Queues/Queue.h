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



