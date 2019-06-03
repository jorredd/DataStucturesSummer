#pragma once
#include<string>
using std::string;
namespace projectOne {
	class Char
	{
	public:
//data
		Char();
		Char(char c);
		Char(int c);
		Char(const Char &c);
//mutators
		void equals(const Char &c);
		void equals(char c);
		void equals(int c);
//accessors
		char toChar() const;
		int toInt() const;
		string toString();
		string toHexString();
		string operator +(char c);
		string operator +(const Char c);

		~Char();
	};
}