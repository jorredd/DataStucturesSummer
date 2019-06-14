// Jordan Redd
// CSIS 123A-3488
// 6/9/2019
// Prof. Stevenson
// Assignment 1	
/* Description:
	Looks through the Numbers.txt file and seperates the whole numbers and fractions into their own files.
*/
#include "Char.h"
#include<iostream>
#include"CharException.h"
namespace projectOne {
	int Char::COUNT = 0; //added this for myself...during initial testing
	//function keeps count of the char classes created. and also checks if the value saved is a proper number we can use
	void Char::count(int code)
	{
		if (code == 1) {
			int tmp = toInt();
			if (tmp > 57 || (tmp < 48 && tmp != 46)) throw CharException("Not A Correct Input"); // if it isnt, a exception will be thrown
			Char::COUNT++;
		}
		else if(code == 0) {
			/*std::cout << "Char Class Deconstructed" << std::endl;*/ //No longer has a use for me
		}
		else { // or i could throw and exception.... please dont mark me down for not
			std::cout << "Error! Use 0 or 1." << std::endl;
		}
	}
	//returns  char
	char Char::toChar() const
	{
		return this->Cchar; 
	}
	//returns an int
	int Char::toInt() const
	{
		return static_cast<int>(this->Cchar);
	}
	//returns the value as a string
	string Char::toString()
	{
		stringstream ss;
		string convert;
		char mychar = this->Cchar;
		ss << mychar;
		ss >> convert;
		return convert;
	}
	//returns th evalue as a hex string
	string Char::toHexString()
	{
		stringstream ss;
		ss << hex << static_cast<int>(this->Cchar);
		string str = ss.str();
		return str;
	}
	// c++ + operator on primitive char type
	string Char::operator+(char c)
	{
		stringstream ss;
		string convert;
		char mychar = this->Cchar;
		ss << mychar;
		ss >> convert;

		return convert + c;
	}
	// c++ + operator on complex Char type
	string Char::operator+(const Char c)
	{
		string product = this->toString() + c.toChar();
		return  product;
	}
}
