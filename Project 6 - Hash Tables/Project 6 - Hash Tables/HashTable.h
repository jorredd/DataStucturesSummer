#pragma once
#include <string>
#include<vector>
#include "LinkedList.h"
#include <iostream>
#include <istream>
#include<fstream>
#include <ostream>
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::string;
using std::to_string;
using std::vector;
using std::cout;
using std::endl;
class HashTable
{
private:
   int TABLESIZE = 0;
   vector<DblyLinkedList<string>> hashVect;
   vector<DblyLinkedList<string>> print;
public:
	HashTable();
	HashTable(int TableSize);
	string searchName(string name);
	string parsedResponse(string response, int hash, int index);
	void hash(double value);// stores a value in the hash table. If the location is already occupied the value should be added to the end of the list on that particular chain.
	int hash(string key, int tablesize);
	int search(double value); //returns the number of occurrences the value appears in the table.
	void parser();
	void printTable(); // prints all of the values in the table to the screen.
	~HashTable();
};

