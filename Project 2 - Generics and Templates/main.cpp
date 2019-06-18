// Jordan Redd
// CSIS 123A-3488
// 6/16/2019
// Prof. Stevenson
// Assignment 2
/* Description:
	Creates a Pair class that holds two templated Values of the same type. Then we have a LinkedList class that acts as a container class for any type you want. From there we expand upond taht class with creating the PairList class
	that serves as a specialized LinkedList that  will hold Pairs<T> of the same tenmplated type.
*/

#include "LinkedList.h"
#include "Pair.h"
#include "PairList.h"
#include<exception> 
using std::exception;
#include<string> 
using std::string;
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	//Pair Test
	try {
		Pair<string> Toyota_Car_0("0", "Supra MKIV");
		cout << "Pair Test: \nThis is index: "<< Toyota_Car_0.getFirst() << ".\nAnd, this is the value at Index " << Toyota_Car_0.getFirst() << ": "<< Toyota_Car_0.getSecond() << endl << endl;
	}
	catch (exception ePair)
	{
		cout << "So that didn't work... How about we just ignore that and continue on?" << endl;
	}

	//Linked List Test
		try {
			//Int test... The linked list will just handle primitives. The PairList will have to be able to handle searching specifically for Pairs
			LinkedList<int> Test(1);
			Test.insert(1, 2);
			Test.insert(2, 3);
			Test.insert(1, 5);
			//String test
			LinkedList<string> Testerson("HEAD");
			Testerson.insert("HEAD", "Initially Inserted after head but will get pushed down");
			Testerson.insert("Initially Inserted after head but will get pushed down", "LAST");
			Testerson.insert("HEAD", "Pushes the long complicated one down");
			cout << "Lets grab some more data: " << endl; Testerson.printList();
		}
		catch (exception insertException)
		{
			cout << "So that didn't work... How about we just ignore that and continue on?" << endl;
		}
	


	try {
		//PairList Test with using all my mutatars
		Pair<string> Lexus_Car_0("0", "LFA");
		Pair<string> Lexus_Car_1("1", "ISF");
		Pair<string> Lexus_Car_2("2", "RCF");

		PairList<string> Lexus;
		Lexus.push_back(Lexus_Car_0);
		Lexus.push_back(Lexus_Car_1);
		Lexus.push_back(Lexus_Car_2);
		Lexus.addPair("3","GSF");
		cout << "Lets grab some data: " << endl;
		Lexus.printList();

		//PairlIST test with using Overloaded Constructor
		Pair<string> Toyota_Car_0("0", "Supra MKIV");
		Pair<string> Toyota_Car_1("1", "GR Supra MKV");
		Pair<string> Toyota_Car_2("2", "GT86 TRD");

		PairList<string> Toyotas(Toyota_Car_0);
		Toyotas.push_back(Toyota_Car_1);
		Toyotas.push_back(Toyota_Car_2);
		cout << "\nLets grab some data: " << endl;
		Toyotas.printList();

		cout << endl; //FORMATTING

		Pair<int> even2(2, 4);
		Pair<int> even4(4, 6);
		Pair<int> even6(6, 8);
		Pair<int> even8(8, 10);
		Pair<int> even10(12, 14);

		PairList<int>PairListTest(even2);
		PairListTest.push_back(even4);
		PairListTest.push_back(even6);
		PairListTest.push_back(even8);
		PairListTest.push_back(even10);

		cout << PairListTest.getSecond(2);
		cout << PairListTest.getFirst(4);
		cout << endl;
		//Test with deleting Pairs
		cout << "\nCheck this list" << endl;
		PairListTest.printList();
		PairListTest.deletePair(2, 4);
		PairListTest.deletePair(8, 10);
		cout << "\nAfter deleting a few of the Pairs we get this: " << endl;
		PairListTest.printList();
		
	}
	catch (exception pairListException)
	{
		cout << "So that didn't work... How about we just ignore that and continue on?" << endl;
	}

	return int(0);
}