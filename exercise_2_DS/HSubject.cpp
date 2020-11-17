//Avishay Farkash 205918790
//Shai Axelrod 205544307
#include "HSubject.h"
using namespace std;

int HSubject::h1(string key)//hash function h1
{
	//Treat the string as a number in base 128 (each character translates to ascii code)-Return at base 10 the value obtained (modulo table size)
	unsigned int sum = 0;
	for (int i = 0; i < key.length(); i++)
		sum = (sum += key[i] * (unsigned int)pow(128, i)) % size;
	return sum % size;
}

int HSubject::h2(string key)//hash function h2-(For skips in case of a collision)
{
	//Treat the string as a number in base 128 (each character translates to ascii code)-Return at base 10 the value obtained (modulo (table size-1))
	unsigned int sum = 0;
	for (int i = 0; i < (int)key.length(); i++)
		sum = (sum += key[i] * (unsigned int)pow(128, i)) % (size - 1);
	return 1 + (sum % (size - 1));
}

void HSubject::printS(string subject)//Printing data of a particular key
{
	int index = search(subject);//Find the position of the organ according to the key
	if (index != -1)
	{
		for (list<string>::iterator it = table[index]->data.begin(); it != table[index]->data.end(); it++)//print all his list
			cout << *it << " ";
		cout << endl;
	}
	else//If there is no such key in the table
	{
		cout << "ERROR\n";
	}
}

void HSubject::addSubjectAndTitle(string subject, string title)//Entering new data into the table
{
	int index = search(subject);//Find the position of the organ according to the key
	if (index != -1)//If the key already exists - add the new string to the data
	{
		table[index]->data.push_front(title);
		return;
	}
	list<string> l1;//else-Enter the new key and his data
	l1.push_front(title);
	this->add(l1, subject);
}

void HSubject::printN(string subject, int n)//Printing n first data strings of a particular key
{
	int index = search(subject);//Find the position of the organ according to the key
	if (index != -1)//If the key already exists -Go through the list and print the first n strings
	{
		int i = 0;
		for (list<string>::iterator it = table[index]->data.begin(); it != table[index]->data.end() && i < n; it++, i++)
			cout << *it << " ";
		cout << endl;
	}
	else
	{
		cout << "ERROR\n";
	}
}

void HSubject::startNewTable()//Initialize a table to the state of an empty table
{
	for (int i = 0; i < size; i++)//For each Cell in table, mark it as "empty"
		table[i]->flag = (state)0;
}

void HSubject::print()//Print all the data of all the keys in the table
{
	for (int i = 0; i < size; i++)//For each Cell in table
		if (table[i]->flag == full)//if it marked ass full
		{
			cout << table[i]->key << ":";//print the key
			printS(table[i]->key);//Print the data of the current key

		}
}


