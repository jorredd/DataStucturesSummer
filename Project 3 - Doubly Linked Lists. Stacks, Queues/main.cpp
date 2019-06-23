#include "Stack.h"
#include "Queue.h"
#include "RPN_Calculator.h"

int main()
{
	try 
	{
		Stack<int> Stest;
		Stest.push(1);
		Stest.push(2);
		Stest.push(3);
		int Sval = Stest.pop();
		Stest.pop();


		Queue<int> Qtest;
		
		Qtest.enqueue(1);
		Qtest.enqueue(2);
		Qtest.enqueue(3);
		int inttest = Qtest.dequeue();
		Qtest.dequeue();
	}
	catch (exception e)
	{
		cout <<  e.what() << endl;
	}
	try {
		RPN_Calculator calc("12.5   2    +  3.4   52 *    56  ");
		//ddwrggr
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
	


	return 0;
}