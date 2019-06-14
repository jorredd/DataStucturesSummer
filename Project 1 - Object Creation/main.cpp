// Jordan Redd
// CSIS 123A-3488
// 6/9/2019
// Prof. Stevenson
// Assignment 1	
/* Description:
	Looks through the Numbers.txt file and seperates the whole numbers and fractions into their own files.
*/
#include<iostream>
#include<string>
#include"BigDecimal.h"
#include"BigDecimalException.h"
#include"Char.h"
#include"CharException.h"
#include "Parser.h"
using std::string;
using std::cout;
using std::endl;
using namespace projectOne;

int main()
{
	//Tests to check if the exceptions work on the Char class by itself
	try {
		Char one('c');
		Char two(48);
		Char three('48');
		//Char willThrowException('fdfd');
	}
	catch (CharException e)
	{
		cout << e.what() << endl;
	}

	//checks for exceptions being thrown up from the BigDecimal Class
	try {
		Parser parse("numbers", "WholeNumbers", "Fractions");
	}
	catch (BigDecimalException e)
	{
		cout << e.what() << endl;
	}


	cout << "Done" << endl;
	return 0;
}


