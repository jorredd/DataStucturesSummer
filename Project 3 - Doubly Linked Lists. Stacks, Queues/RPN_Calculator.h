#pragma once
#include "Stack.h"
#include <string>
using std::string;
using std::stoi;
using std::stod;

class RPN_Calculator 
{
private:
	Stack<char>input;
public:
	RPN_Calculator();
	RPN_Calculator(string input) { parser(input); };
	~RPN_Calculator();

	void parser(string input);
};

