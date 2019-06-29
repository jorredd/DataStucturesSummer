#include "Stack.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include <istream>
#include<fstream>
#include <ostream>
using std::ifstream;
using std::ostream;
using std::cout;
using std::endl;
#pragma once


class Palindrone 
{
public:
	Palindrone();
	// Calls Parser("Input", "Output")  First Parm is name of file to open and second Param is output file name desired
	Palindrone(string input, string output);
	~Palindrone();
	// Parser("Input", "Output")  First Parm is name of file to open and second Param is output file name desired
	void Parser(string input, string output);
};

