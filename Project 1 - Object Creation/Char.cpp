#include "Char.h"
#include<iostream>
namespace projectOne {
	int Char::COUNT = 0;
	//Char::Char()
	//{
	//}

	//Char::Char(char c)
	//{
	//}

	//Char::Char(int c)
	//{
	//}

	//Char::Char(const Char & c)
	//{
	//}

	//void Char::equals(const Char & c)
	//{
	//}

	//void Char::equals(char c)
	//{
	//}

	//void Char::equals(int c)
	//{
	//}
	
	void Char::count(int code)
	{

		if (code == 1) {
			Char::COUNT++;
		}
		else if(code == 0) {
			std::cout << "Char Class number " << Char::COUNT-- << " Deconstructed" << std::endl;
		}
		else {
			throw "Wrong";
		}
	}
	char Char::toChar() const
	{
		return 0;
	}

	int Char::toInt() const
	{
		return 0;
	}

	string Char::toString()
	{
		return string();
	}

	string Char::toHexString()
	{
		return string();
	}

	string Char::operator+(char c)
	{
		return string();
	}

	string Char::operator+(const Char c)
	{
		return string();
	}
}
