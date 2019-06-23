#include "LinkedList.h"
#pragma once


#pragma region header/prototyping
template<class T>
class Stack : private DblyLinkedList<T>
{

private:
#pragma region Data

#pragma endregion

public:
#pragma region consturctors
	Stack();
	~Stack();
#pragma endregion

#pragma region getters
	T peek();

#pragma endregion

#pragma region Mutators
	//Stack FILO data structure
	void push(T data);
	T pop();
#pragma endregion

};
#pragma endregion



#pragma region Constructors Definition
template<class T>
 Stack<T>::Stack()
{
}
template<class T>
 Stack<T>::~Stack()
{
}

#pragma endregion

#pragma region Mutators Definitions

 template<class T>
 void Stack<T>::push(T data)
 {
	 DblyLinkedList<T>::push(data);
 }

 template<class T>
 T Stack<T>::pop()
 {
	 return DblyLinkedList<T>::pop();
 }
#pragma endregion

#pragma region Getters Definitions
 template<class T>
 T Stack<T>::peek()
 {
	 return DblyLinkedList<T>::peek();
 }
#pragma endregion



