#pragma once
#include "LinkedList.h"
template<class T>
class Queue :public LinkedList<T>
	
{
public:
	Queue();
	~Queue();
};


template<class T>
Queue<T>::Queue()
{
}

template<class T>
Queue<T>::~Queue()
{
}
