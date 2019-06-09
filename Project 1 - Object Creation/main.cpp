#include<iostream>
#include<string>
#include"BigDecimal.h"
#include"Char.h"
#include"CharException.h"

using std::string;
using std::cout;
using std::endl;
//using std::{SOMETHING};

using namespace projectOne;

int main()
{
	try {
		Char one('c');
	}
	catch (CharException e)
	{
		cout << e.what() << endl;
	}
	try {
		Char two(48);
	}
	catch (CharException e)
	{
		cout << e.what() << endl;
	}	
	try {
		Char three('48');
	}
	catch (CharException e)
	{
		cout << e.what() << endl;
	}
	//Char onne('d');
	//Char ondne('e');

	//Char *test = new Char();
	//Char five(67);
	//string tester = five.toString();
	//string maybe = one + onne;
	cout << "Done" << endl;

	return 0;
}


