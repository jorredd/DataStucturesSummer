#include "Palindrone.h"

Palindrone::Palindrone()
{
}
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

	Queue<char> front;
	Stack<char> back;
	Queue<string> palindrome;
	ifstream infile(inputName + ".txt");

	if (!infile) throw exception("Error opening file for reading");

	infile.seekg(0, infile.end);
	const int cap = infile.tellg();
	infile.seekg(0, infile.beg);
	int count = 0;
	

	char input[200];
	string in;
	while (infile.getline(input, 200))
	{
		//grab a whole line from the file
		for (int c = 0; c < 200; c++)
		{
			char peek = input[c];
			if (input[c] == '\0') break;
		
			input[c] = tolower(input[c]);
			front.enqueue(input[c]);
			back.push(input[c]);
			count++;
		}
		// Perform the comparasion on that line
		for (int c = 0; c < count; c++) 
		{
			if (front.peek() == back.peek())
			{
				if (count - c == 1)
				{
					back.push(back.peek()); //HACKY AS HOLY FUCK
					front.enqueue(front.peek()); //HACKY AS HOLY FUCK
				}
				in.push_back(back.pop());
				front.dequeue();
				if (count - c == 1) break;
			}
			else
			{
				break;
			}
		}
		palindrome.enqueue(in); //string isnt clearing prooperly and is throwing everything off
		in.clear();
	}
	palindrome.expose();
	cout << "File Parsed Successfully" << endl;
	infile.close();
}
