// Jordan Redd
// CSIS 123A-3488
// 6/30/2019
// Prof. Stevenson
// Assignment 4
/* Description:
	Uses the Queue to create a Palindrome checker.
*/

#include "Palindrone.h"

int main()
{
	try 
	{
		//The first parameter is the file to be tested and the second is the file that you want to save the returned values to
		Palindrone test("pal", "palidromesFound");
	}
	catch (exception e)
	{
		//exception handling
		cout << e.what() << endl;
	}
	return 0;
}