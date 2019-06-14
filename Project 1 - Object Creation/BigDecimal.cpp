// Jordan Redd
// CSIS 123A-3488
// 6/9/2019
// Prof. Stevenson
// Assignment 1	
/* Description:
	Looks through the Numbers.txt file and seperates the whole numbers and fractions into their own files.
*/
#include "BigDecimal.h"
#include "BigDecimalException.h"
#include <iostream>
using std::cout;
using std::endl;
using std::to_string;
namespace projectOne {
	//defaults the container  to 0.0
	BigDecimal::BigDecimal()
	{
		this->digits.reserve(100);
		BigDecimal("0.0");
	}
	//trying to keep up with that one line of code so this calls the equals method
	BigDecimal::BigDecimal(string value)
	{
		equals(value);
	}
	// loops through the string and pushs individual chars to teh Char class
	void BigDecimal::equals(string value)
	{
		for (int c = 0; c < value.size(); c++)
		{
			try {
				this->digits.push_back(Char(value[c]));
			}
			catch (CharException e)
			{
				cout << e.what() << endl; //if Char throws something its caught here
			}
		}
	}
	//Basically the same thing as the previous equals except the char is directly added to the digits vector
	void BigDecimal::equals(char ch)
	{
		try {
			this->digits.push_back(Char(ch));
		}
		catch (CharException e)
		{
			 cout << e.getMessage() << endl;
		}
	}
	//converts the value of the current bigdeciml to a double and adds it to the double value of the next parameters bigdecimal and then converts everything back to to a string before returning a new bigdecimal with the converted values
	BigDecimal BigDecimal::operator+(BigDecimal value)
	{
		BigDecimal tmp;
		double result = this->toDouble() + value.toDouble();
		string convert = to_string(result);
		return BigDecimal(convert);
	}
	//converts the value of the current bigdeciml to a double and subtracts it to the double value of the next parameters bigdecimal and then converts everything back to to a string before returning a new bigdecimal with the converted values
	BigDecimal BigDecimal::operator-(BigDecimal value)
	{
		BigDecimal tmp;
		double result = this->toDouble() - value.toDouble();
		string convert = to_string(result);
		return BigDecimal(convert);
	}
	//returns the whole number value  of the bigdecimal. 
	int BigDecimal::wholeNumber()
	{
		string whole = this->toString();
		string val;
		int ret;
		for (int c = 0; c < whole.size(); c++)
		{
			char check = whole[c];
			if (check == '.') ret = (stoi(val)); // once we hit the decimal we will give the returning value the value held witin the val string
			int convert = stoi(to_string(check)) - 48;  // converting the current value into its actual numerical value and not its ASCII value
			val.append(to_string(convert)); //then reconverts it back to a string 
		}
		return ret;
	}
	//returns the numbers after the decimal pont
	double BigDecimal::fraction()
	{
		string whole = this->toString();
		string val;
		int flag = 0; // using this as a flag for conditions below
		double ret;
		for (int c = 0; c < whole.size(); c++)
		{
			char check = whole[c];
			if (check != '.' && flag != 1) continue; // skips the first values before the '.' point
			if (check == '.' && flag != 1) { // once we find the decimal point we will append the . to the val string and set the flag to one and continue the loop.. if we encounter another '.' it will be skipped here 
				val.append(".");
				flag = 1;
				continue;
			}
			int convert = stoi(to_string(check)) - 48; // will run after we get past thedecimal.
			val.append(to_string(convert));
		}
		//error handling
		try {
			if (val == ".") val.append("0");
			ret = (stod(val));
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
		return ret;

	}
	//returns the bigdecunak as a double
	double BigDecimal::toDouble()
	{
		double dbl = stod(this->toString());
		return dbl;
	}
	//returns the string bigdecimal as a string value
	string BigDecimal::toString()
	{
		vector<Char>::iterator it;
		string str;
		for (it = this->digits.begin(); it != this->digits.end(); it++)
		{
			str.append(it->toString()); //itterates through and appends each digit to a string
		}
		return str;
	}
	//pull an individual Char out of a Bigdecimal
	Char BigDecimal::at(int index)
	{
		return this->digits.at(index);
	}
}