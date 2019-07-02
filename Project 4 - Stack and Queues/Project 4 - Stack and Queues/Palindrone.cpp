// Jordan Redd
// CSIS 123A-3488
// 6/30/2019
// Prof. Stevenson
// Assignment 4
/* Description:
	Uses the Queue to create a Palindrome checker. This file has one method that handles evrything for this class
	The Parser() metho handles the Reading and Writing and Parses through the read text saving each Char to Stack
	and a Queue to be tested against.
*/

#include "Palindrone.h"

Palindrone::Palindrone()
{
}
//calls the Parser function
Palindrone::Palindrone(string input, string output)
{
	Parser(input, output);
}


Palindrone::~Palindrone()
{
}
// Parser("inputName", "Output")  First Parm is name of file to open and second Param is output file name desired
void Palindrone::Parser(string inputName, string output)
{
	
	Queue<string> palindrome; // Queue that is gong to be used to hold each line that is a palidrone
	string input; // saves the read files lines of text here
	ifstream infile(inputName + ".txt"); // open the file
	int lineCount = 0; //used later for the writing
	if (!infile) throw exception("Error opening file for reading"); // f something goes wrong throw a exception
	while (getline(infile, input))
	{
		Queue<char> front; // queue used chars
		Stack<char> back;	// stack used for Chars
		Queue<char> front_noSpace; // this will have no space chars in it
		Stack<char> back_noSpace;// this will have no space chars in it
		string* in = new string(); //string that will contain the line of text to push into the palidrome
		bool flag = false;
		int charCount = 0; //used for calculations on how many chars are in a string after whitespace is removed
		//grab a whole line from the file
		for (int c = 0; c < input.length(); c++)
		{
			char peek = input[c]; // variable i use for testing
			front.enqueue(tolower(input[c])); // to lowers the input so there are no casing issues
			back.push(tolower(input[c])); // to lowers the input so there are no casing issues
			if (input[c] != ' ') // only insert if there are no spaces
			{
				charCount++;
				front_noSpace.enqueue(tolower(input[c])); // to lowers the input so there are no casing issues
				back_noSpace.push(tolower(input[c])); // to lowers the input so there are no casing issues
			}
		}

		// Perform the comparasion on that line
		for (int h = 0; h < input.length(); h++)
		{
			if (front.peek() == ' ' && back.peek() != ' ' || front.peek() != ' ' && back.peek() == ' ') // Checks if either front or back contains a space and handles accordingly
			{
				if (front.peek() == ' ')
				{
					in->push_back(front.dequeue());
					continue;
				}
				if (back.peek() == ' ')
				{
					in->push_back(back.pop());
					continue;
				}
			}
 			if (front.peek() == back.peek()) // if front and back are equal we are going to add it to the string reference 
			{
				int condition = h;
				if (input.length() - condition  == 1)
				{
					back.push(back.peek()); 
					front.enqueue(front.peek()); 
				}
				in->push_back(front.dequeue()); //using the String classes Push_back function to add whats in the queue to it
				back.pop(); // pop so the front and back lists can stay parallel 
				if (input.length() - condition  == 1) break;
			}
			else
			{
				flag = true; // if there is not a match break and set this flag to true
				break;
			}
		}
			if(flag) continue; // restarts the loop if the flag is true
			lineCount++;
			palindrome.enqueue(*in); 
			delete in; //deletes the string so we can start fresh the next loopS
	}
	cout << "File Parsed Successfully" << endl;
	infile.close(); //close the file being read

	ofstream outfile(output + ".txt"); //create the file you want to hold the palidromes in
	if (!outfile) throw exception("Could not Open File to be created"); //if it doesnt open throw this exception
	for (int i = 0; i < lineCount; i++) //using th elinecount variable we create a loop and add all of the found paridromes into the file
	{
		int condition = i;
		if (lineCount - condition == 1) palindrome.enqueue(palindrome.peek()); 
		string p = palindrome.dequeue(); //pulls out the values from the palidrome so we can add it to the outfile
		outfile << p << endl; //writes to the file
	}
	outfile.close(); //closes the file
}
