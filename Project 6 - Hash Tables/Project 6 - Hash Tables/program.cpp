#include <iostream>
#include"HashTable.h"

using namespace std;

const int TABLESIZE = 20;
void initTable(int table[], int tableSize);
int hashFunc(int key, int tableSize);
int hashFunc(double key, int tableSize); 
int hashFuncImproved(string key, int tablesize);
int probe(int start, int table[], int tablesize);
int main()
{
	int table[TABLESIZE];

	initTable(table, TABLESIZE);
	int index = hashFunc(22, TABLESIZE);
	table[index] = 22;

	index = probe(index, table, TABLESIZE);



	HashTable tmp(53);
	tmp.parser();
	string name;
	cout << "Enter Name:";
	cin >> name;
	string hope = tmp.searchName(name);
	cout << hope << endl;
	tmp.printTable(); 
	return 0;
}

void initTable(int table[], int tableSize)
{
	for (int i = 0; i < tableSize; i++)
	{
		table[i] = -1;
	}

}
int hashFunc(int key, int tableSize)
{
	return key % tableSize;
}
int hashFunc(double key, int tableSize)
{
	return static_cast<int>(key) % tableSize;
}



int hashFuncImproved(string key, int tablesize)
{
	int hashVal = 0;
	for (int i = 0; i < key.size(); i++)
		hashVal = 37 * hashVal + static_cast<int>(key[i]);

	hashVal %= tablesize;

	if (hashVal < 0)
		hashVal += tablesize;

	return hashVal;
}

int probe(int start, int table[], int tablesize)
{
	for (int i = start; i < tablesize; i++)
	{
		if (table[i] == -1) return i;
	}
	return -1;
}