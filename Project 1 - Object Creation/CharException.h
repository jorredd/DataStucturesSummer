#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;

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