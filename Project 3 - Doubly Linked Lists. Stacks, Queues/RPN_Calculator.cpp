#include "RPN_Calculator.h"
#include <regex>
#include<iostream>
#include <string>
using std::regex;




RPN_Calculator::RPN_Calculator()
{
}


RPN_Calculator::~RPN_Calculator()
{
}

void RPN_Calculator::parser(string input)
{
	regex match("^[0-9]+$");
	
	for (int i = 0; i < input.size(); i++){
		string now = input[i] + " ";
		if (!std::regex_match(now, match)) continue;
		if (input[i] == ' ') continue;
		this->input.push(input[i]);
	}
}