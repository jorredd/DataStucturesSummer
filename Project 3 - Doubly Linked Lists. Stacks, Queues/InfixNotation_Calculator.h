#pragma once
#include "RPN_Calculator.h"
class InfixNotation_Calculator :
	public RPN_Calculator
{
private:
	Stack<char>input;
public:
	void parser(string input);
	InfixNotation_Calculator();
	~InfixNotation_Calculator();
};

