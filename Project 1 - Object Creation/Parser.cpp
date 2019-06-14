// Jordan Redd
// CSIS 123A-3488
// 6/9/2019
// Prof. Stevenson
// Assignment 1	
/* Description:
	Looks through the Numbers.txt file and seperates the whole numbers and fractions into their own files. 
*/
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include "BigDecimal.h"
#include "BigDecimalException.h"

using  std::string;
using std::to_string;
using  std::cout;
using  std::endl;
using  std::ifstream;
using  std::ofstream;
using projectOne::BigDecimal;
using projectOne::BigDecimalException;
//does nothing..
namespace projectOne {
	Parser::Parser()
	{
	};

	//Parser(string "FileToBeParsed", string "OutfileForChars", string "OutfileForChars")
	Parser::Parser(string fileName, string parsedInts, string parsedChars)
	{
		parseFile(fileName);
		writeFile(parsedInts, parsedChars);
	};

	//Calls two overloaded writeFile functions then it says goodbye...
	Parser::~Parser()
	{
		log("Mr. Stark, I don't feel so good...");
	};

	//Reads the Numbers.txt file and determins if the number on each line is a Char or a Char and stores them in the respective <Vector>
	void Parser::parseFile(string fileName)
	{
		ifstream infile(fileName + ".txt");
		if (!infile)
		{
			log("Error opening file for reading");
			exit(-1);
		}
		string input;
		while (getline(infile, input))
		{
			if (input.find(".") != -1)
			{
				BigDecimal convert;
				try {
					 convert.equals(input);
				}
				catch (BigDecimalException e)
				{
					throw e;
				}
				this->back->push_back(BigDecimal(to_string(convert.fraction())));
				this->front->push_back(BigDecimal(to_string(convert.wholeNumber())));
			}
		}
		infile.close();
		log("File Parsed Successfully");
	};

	//Takes what you want the file names of the parsed input for Chars and Chars to be and then creates those files with the parsd input all happening from within this function
	void Parser::writeFile(string parsedInts, string parsedChars)
	{
		//Create an instance of ofstream and open parsedInts.txt 
		ofstream ints(parsedInts + ".txt");


		//Make sure the file was opened
		if (!ints)
		{
			log("Error opening file ");
			exit(0);
		}

		vector <BigDecimal>::iterator I;
		for (I = this->front->begin(); I < this->front->end(); I++)
		{
			ints << I->toString() << endl;
		}

		ints.close(); // closes the file

		ofstream Chars(parsedChars + ".txt");

		vector <BigDecimal>::iterator D;
		for (D = this->back->begin(); D < this->back->end(); D++)
		{
			Chars << D->toString() << endl;
		}
		Chars.close(); //closes the file
	};


	//helper function that i use to cout... reduces finger stretching
	void Parser::log(string say)
	{
		cout << say << endl;
	};
}