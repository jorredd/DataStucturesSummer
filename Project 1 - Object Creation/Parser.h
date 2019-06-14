// Jordan Redd
// CSIS 123A-3488
// 3/35/19
// Prof. Rickman
// Assignment 9		
/* Description:
	header file.

*/
#pragma once
#ifndef PARSER
#define PARSER


#include <vector>
#include "Char.h"
#include"BigDecimal.h"

using std::vector;
using std::string;
using projectOne::Char;
using projectOne::BigDecimal;
namespace projectOne {
	class Parser
	{
	private:
		//Pointers
		vector<BigDecimal> *front = new vector<BigDecimal>();
		vector<BigDecimal> *back = new vector<BigDecimal>();
	public:
		Parser();
		//Parser(string "FileToBeParsed", string "OutfileForChars", string "OutfileForChars")
		Parser(string fileName, string parsedInts, string parsedChars);

		//runs the two WriteFile overloads
		~Parser();
		//Reads the file and sends the data to the Vector
		void parseFile(string fileName);

		//Writes the Parsed data to a new file
		void writeFile(string parsedInts, string parsedChars);


		//Helper function
		void log(string say);
	};

#endif // !PARSER
}