#pragma once
template<class T1, class T2>
class Pair
{
private:
	T1 F; //First Value of Pair
	T2 S; //Second Value of Pair

public:
	Pair(){};
	Pair(T1 val, T2 val2) :F(val), S(val2) {};  //sets values
	~Pair() {}; //Mr Stark, I don't feel so good......;
	// Returns the 1st of the pair
	T1 getFirst() { return this->F;};  //get
	// Returns the 2nd of the pair
	T2 getSecond() { return this->S;}; //get
	// Sets the first of the pair
	void setFirst(T1 val) { this->F = val; }; //set
	// Sets the second of the pair
	void setSecond(T2 val2) { this->S = val2; }; //set

};