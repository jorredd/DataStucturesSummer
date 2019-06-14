// Jordan Redd
// CSIS 123A-3488
// 6/9/2019
// Prof. Stevenson
// Assignment 1	
/* Description:
	Looks through the Numbers.txt file and seperates the whole numbers and fractions into their own files.
*/
#pragma once
#include "CharException.h"
using namespace projectOne;
namespace projectOne {
	class BigDecimalException : public CharException
	{
	private:
		string message;
	public:
		BigDecimalException();
		BigDecimalException(string message) : message(message) {}
		virtual const char *what() { return message.c_str(); }
		~BigDecimalException();
	};

}