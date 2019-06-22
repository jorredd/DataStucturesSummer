#include "LinkedList.h"
#pragma once
template<class T>
class Stack : public LinkedList<T>
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

#pragma endregion

#pragma region setters
	//Stack FILO data structure
	void push();
#pragma endregion

	

};

//Stack FILO data structure
template<class T>
void Stack<T>::push()
{
	// TODO: Add your implementation code here.
	return T();
}
template<class T>
inline Stack<T>::~Stack()
{
}

