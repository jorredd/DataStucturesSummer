#include "HashTable.h"



HashTable::HashTable()
{
	this->TABLESIZE = 50;
	this->hashVect.resize(this->TABLESIZE);
	this->print.resize(this->TABLESIZE);
}

HashTable::HashTable(int tableSize)
{
	this->TABLESIZE = tableSize;
	this->hashVect.resize(this->TABLESIZE);
	this->print.resize(this->TABLESIZE);
}
void HashTable::parser()
{
	ifstream infile("HashData.txt");
	string input;
	if(!infile) throw exception("Error opening file for reading"); // if something goes wrong throw a exception 
	while (getline(infile, input))
	{
		int key = hash(input, this->TABLESIZE);
		this->hashVect.at(key).push(input);
		this->print.at(key).push(input);
		// cout << input << endl;
	}
}
string HashTable::parsedResponse(string response , int hash, int index)
{
	string parsedResponse = "";
	bool flag = false;
	for (int i = 0; i < response.size(); i++)
	{
		if (response[i] == ';' && !flag)
		{
			parsedResponse.append("(" + to_string(hash)  + " - " + to_string(index) + ")");
			flag = true;
			continue;
		}

		parsedResponse.push_back(response[i]);
	}
	return parsedResponse;
}
//Seachers for the persons name and if it is found then it returns 
string HashTable::searchName(string name)
{
	if (this->hashVect.empty()) throw exception("HASHTABLE IS EMPTY");
	vector< DblyLinkedList<string>> dup = hashVect;

	for (int i = 0; i < hashVect.size(); i++)
		dup.push_back(hashVect[i]);

	for (int i = 0; i < this->hashVect.capacity(); i++)
	{	
		try {
			string foundName;
			for (int c = 0; c < dup.at(i).LENGTH; c++)
			{
				if (c == dup.at(i).LENGTH - 1)
				{
					foundName = dup.at(i).peek();
				}
				else 
				{
					foundName = dup.at(i).pop();
				}

				if (name.size() > 0 && foundName.find(name) != -1 && foundName.find(name[name.size() - 1])) return parsedResponse(foundName, i, c);
			}
		}
		catch (exception e)
		{
			continue;
		}
	}

	return string("Not Found");
}

void HashTable::hash(double value)
{

}

int HashTable::hash(string key, int tablesize)
{
	int hashVal = 0;
	for (int i = 0; i < key.size(); i++)
		hashVal = 37 * hashVal + static_cast<int>(key[i]);

	hashVal %= tablesize;

	if (hashVal < 0)
		hashVal += tablesize;

	return hashVal;
}



int HashTable::search(double value)
{
	return 0;
}

void HashTable::printTable()
{
	if (this->hashVect.empty()) throw exception("HASHTABLE IS EMPTY");
	int count = 0;
	for (int i = 0; i < this->print.capacity(); i++)
	{
		print.at(i).printList();
		cout << count++;
	}
}


HashTable::~HashTable()
{
	
}
