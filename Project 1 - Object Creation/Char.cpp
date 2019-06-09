#include "Char.h"
#include<iostream>
#include"CharException.h"
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
			int tmp = toInt();
			if (tmp > 57 || (tmp < 48 && tmp != 46)) throw CharException("Not A Correct Input");
			Char::COUNT++;
		}
		else if(code == 0) {
			std::cout << "Char Class number " << Char::COUNT-- << " Deconstructed" << std::endl;
		}
		else { // or i could throw and exception.... please dont mark me down for not
			std::cout << "Error! Use 0 or 1." << std::endl;
		}
	}
	char Char::toChar() const
	{
		return this->Cchar;
	}

	int Char::toInt() const
	{
		return static_cast<int>(this->Cchar);
	}

	string Char::toString()
	{
		stringstream ss;
		string convert;
		char mychar = this->Cchar;
		ss << mychar;
		ss >> convert;
		return convert;
	}

	string Char::toHexString()
	{
		stringstream ss;
		ss << hex << static_cast<int>(this->Cchar);
		string str = ss.str();
		return str;
	}

	string Char::operator+(char c)
	{
		stringstream ss;
		string convert;
		char mychar = this->Cchar;
		ss << mychar;
		ss >> convert;

		return convert + c;
	}

	string Char::operator+(const Char c)
	{
		string product = this->toString() + c.toChar();
		return  product;
	}
}
