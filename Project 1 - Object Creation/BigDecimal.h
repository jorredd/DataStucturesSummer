#pragma once
#include<string>
#include"Char.h"
using std::string;
namespace projectOne {
	class BigDecimal
	{
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

		~BigDecimal();
	};
}
