// Jordan Redd
// CSIS 123A-3488
// 6/9/2019
// Prof. Stevenson
// Assignment 1	
/* Description:
	Looks through the Numbers.txt file and seperates the whole numbers and fractions into their own files.
*/
#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;
//Char Exception that that inehrit the public exception class 
namespace projectOne {
	class CharException : public exception
	{
	public:
		int errorCode;
		string message;
		CharException() : message("This Error is Unknown") {}
		CharException(string message) : message(message) {}
		virtual const char *what() { return message.c_str(); }
		string getMessage() { return this->message; };
		int getCode() { return this->errorCode; };
		~CharException();
	};

}