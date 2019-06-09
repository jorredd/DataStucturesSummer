#include "BigDecimal.h"

namespace projectOne {

	BigDecimal::BigDecimal()
	{
		this->digits.reserve(100);
		this->digits.push_back(Char(48));
		this->digits.push_back(Char(46));
		this->digits.push_back(Char(48));
	}

	BigDecimal::BigDecimal(string value)
	{
		int convert = stoi(value);
	}

	void BigDecimal::equals(char ch)
	{
	}

	void BigDecimal::equals(string value)
	{
	}

	BigDecimal BigDecimal::operator+(BigDecimal value)
	{
		return BigDecimal();
	}

	BigDecimal BigDecimal::operator-(BigDecimal value)
	{
		return BigDecimal();
	}

	int BigDecimal::wholeNumber()
	{
		return 0;
	}

	double BigDecimal::fraction()
	{
		return 0.0;
	}

	double BigDecimal::toDouble()
	{
		return 0.0;
	}

	string BigDecimal::toString()
	{
		return string();
	}

	Char BigDecimal::at(int index)
	{
		return Char();
	}
}