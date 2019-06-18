// Jordan Redd
// CSIS 123A-3488
// 6/16/2019
// Prof. Stevenson
// Assignment 2
/* Description:
	Simple container class that can hold two values of any type. Has basic getter/setter functionaiity
*/
#pragma once
template<class T>
class Pair
{
private:
	T F; //First Value of Pair
	T S; //Second Value of Pair

public:
	Pair(){};
	Pair(T val, T val2) :F(val), S(val2) {};  //sets values
	~Pair() {}; //Mr Stark, I don't feel so good......;
	// Returns the 1st of the pair
	T getFirst() { return this->F;};  //get
	// Returns the 2nd of the pair
	T getSecond() { return this->S;}; //get
	// Sets the first of the pair
	void setFirst(T val) { this->F = val; }; //set
	// Sets the second of the pair
	void setSecond(T val2) { this->S = val2; }; //set

};