#pragma once
#include<string>
#include<sstream>
#include<iostream>
#include"CharException.h"
using std::string;
using std::stringstream;
using std::hex;

namespace projectOne {
	class Char
	{
	private:
//data
		void count(int code);
		//int Ichar;
		char Cchar;
	public:
		static int COUNT;
//Constructors
		Char() { count(1); };
		Char(char c) : Cchar(c) { count(1); };
		Char(int c) : Cchar(static_cast<char>(c)) { count(1);}; //IM GOIN TO HAVE TO CHANGE ALL OF THIS SHIT.....
		Char(const Char &c) : Cchar(c.toChar()) { count(1); };
//mutators
		void equals(char c) { this->Cchar = c; };
		void equals(int c) { equals(static_cast<char>(c)); };
		void equals(const Char &c) { equals(c.toChar()); };

//accessors
		char toChar() const;
		int toInt() const;
		string toString();
		string toHexString();
		string operator +(char c);
		string operator +(const Char c);

		~Char() { count(0); };
	};
}