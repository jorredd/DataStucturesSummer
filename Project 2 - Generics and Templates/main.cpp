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
		Pair<int, string> Toyota_Car_0(0, "Supra MKIV");
		cout << "This is index: "<< Toyota_Car_0.getFirst() << ".\nAnd, this is the value at Index " << Toyota_Car_0.getFirst() << ": "<< Toyota_Car_0.getSecond() << endl;
	}
	catch (exception ePair)
	{
		cout << "So that didn't work... How about we just ignore that and continue on?" << endl;
	}

	//Linked List Test
	try {
		//LinkedList Test with using default constructor
		Pair<int, string> Lexus_Car_0(0, "LFA");
		Pair<int, string> Lexus_Car_1(1, "ISF");
		Pair<int, string> Lexus_Car_2(2, "RCF");

		LinkedList<Pair<int, string>> Lexus;
		Lexus.push_back(Lexus_Car_0);
		Lexus.push_back(Lexus_Car_1);
		Lexus.push_back(Lexus_Car_2);

		//Linked list test with using Overloaded Constructor
		Pair<int, string> Toyota_Car_0(0, "Supra MKIV");
		Pair<int, string> Toyota_Car_1(1, "GR Supra MKV");
		Pair<int, string> Toyota_Car_2(2, "GT86 TRD");

		LinkedList<Pair<int, string>> Toyotas(Toyota_Car_0);
		Toyotas.push_back(Toyota_Car_1);
		Toyotas.push_back(Toyota_Car_2);

		//cout << "Lets grab some data "; Lexus.printList(); 

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
			cout << "Lets grab some data " << endl; Testerson.printList();
		}
		catch (exception insertException)
		{
			cout << "So that didn't work... How about we just ignore that and continue on?" << endl;
		}
	}
	catch (exception ePair)
	{
		cout << "So that didn't work... How about we just ignore that and continue on?" << endl;
	}

	try {
		Pair<int, string> even2(2, "4");
		Pair<int, string> even4(4, "6");
		Pair<int, string> even6(6, "8");

		PairList<Pair<int, string>>PairListTest(even2);
		PairListTest.push_back(even4);
	}
	catch (exception pairListException)
	{

	}

	return int(0);
}