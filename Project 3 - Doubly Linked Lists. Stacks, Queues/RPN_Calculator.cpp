#include "RPN_Calculator.h"
#include <regex>
#include<iostream>
#include <string>
#include <exception>
using std::regex;




RPN_Calculator::RPN_Calculator()
{
}


RPN_Calculator::~RPN_Calculator()
{
}

void RPN_Calculator::parser(string input)
{
	char match[] = {'1','2', '3', '4', '5', '6', '7', '8', '9', '0', '+', '-' , '/', '*', '.'};
	bool flag = false;
	for (int i = 0; i < input.size(); i++){
		//This code snippet will make sure that the current character we are on is a number or math operator
		for(int c = 0; c <= sizeof(match); c++)
		{ 
			char now = input[i];
			char nowMatch = match[c];
			if (input[i] != match[c] && input[i] != ' ') {
				if(c == sizeof(match)) throw exception("NAN");
				continue;
			}
			else {
				break;
			}
		}
		char noww = input[i];

		//If more than one space is used in the input it will just be ignored
		if (i != 0 && input[i] == ' ') {
			if (this->input.peek() == ' ') continue;
			this->input.push(input[i]);
			this->count++;
			continue;
		}

		//This code snippet below will ensure that there is only 1 occurence of a math operator  at a given time ex {13 + 52 -} is ok but {13 ++ 52 -} will fail
		char symbolMatch[] = {'+', '-' , '/', '*'};
		for (int j = 0; j <= sizeof(symbolMatch); j++) {
			if (i != 0 && this->input.peek() != symbolMatch[j] )
			{
				continue;
			}
			else {
				for(int h = 0; h <= sizeof(symbolMatch); h++) 
					if (input[i] == symbolMatch[h]) 
						throw exception("Not Proper Format");
			}
		}
		// If we hit a math operator then that means that we are on a
		for (int f = 0; f <= sizeof(symbolMatch); f++) {
			if (input[i] == symbolMatch[f] && flag || input[i] == symbolMatch[f] && flag) flag = false;
		}

		//This code snippet below handles multiple '.' characters throughout the input... ex:{123.456.789} will thow exception on this
		if (input[i] == '.' && !flag)
		{
			this->input.push(input[i]);
			this->count++;
			flag = true;
			continue;
		}
	    if (input[i] == '.' && flag) throw exception("NAN: \"Multiple decimal places\"");

		this->input.push(input[i]);
		this->count++;
	}
}

// //Add //WHERE I LEFT OFF

string RPN_Calculator::add()
{
	for (int i = 0; i < this->count; i++)
	{
		  
	}
	return string();
}


// Subtract
string RPN_Calculator::sub()
{
	// TODO: Add your implementation code here.
	return string();
}


// Multiplication
string RPN_Calculator::product()
{
	// TODO: Add your implementation code here.
	return string();
}


// Division
string RPN_Calculator::quotient()
{
	// TODO: Add your implementation code here.
	return string();
}
