#pragma once
#include<string>
#include<iostream>
using std::string;
namespace projectOne {
	class Char
	{
	private:
//data
	
		void count(int code);
		int Ichar;
		char Cchar;
	public:
		static int COUNT;
//Constructors
		Char() { count(1); };
		Char(char c) : Cchar(c) { count(1); };
		Char(int c) : Ichar(c) { count(1); };
		Char(const Char &c) : Cchar(c.toChar()) { count(1); };
//mutators
		void equals(const Char &c) { this->Cchar = c.toChar(); };
		void equals(char c) { this->Cchar = c; };
		void equals(int c) { this->Ichar = c; };
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