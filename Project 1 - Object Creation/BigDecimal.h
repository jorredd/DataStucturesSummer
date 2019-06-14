// Jordan Redd
// CSIS 123A-3488
// 6/9/2019
// Prof. Stevenson
// Assignment 1	
/* Description:
	Looks through the Numbers.txt file and seperates the whole numbers and fractions into their own files.
*/
#pragma once
#include<string>
#include"Char.h"
#include <iostream>
#include<vector>
using std::stoi;
using std::vector;
using std::string;
namespace projectOne {
	class BigDecimal
	{
	private:
		vector<Char>digits;
	public:
		BigDecimal();
		BigDecimal(string value);
//mutators
		void equals(char ch);
		void equals(string value);
		BigDecimal operator +(BigDecimal value);
		BigDecimal operator -(BigDecimal value);
//Accessors 
		int wholeNumber();
		double fraction();
		double toDouble();
		string toString();
		Char at(int index);

		~BigDecimal() { /*std::cout << "BigDecimal Class Deconstructed" << std::endl;*/ };
	};
}
