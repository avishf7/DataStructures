#include "HSubject.h"

using namespace std;


int HSubject::h1(string key)
{
	unsigned int sum = 0;
	for (int i = 0; i < key.length(); i++)
		sum=(sum += key[i] * (unsigned int)pow(128, i)) % size;
	return sum % size;
}

int HSubject::h2(string key)
{
	unsigned int sum = 0;
	for (int i = 0; i < (int)key.length(); i++)
		sum = (sum += key[i] * (unsigned int)pow(128, i)) % (size - 1);
	return 1 + (sum % (size - 1));
}

void HSubject::printS(string subject)
{
	int index = search(subject);
	if (index != -1)
	{
		for (list<string>::iterator it = table[index]->data.begin(); it != table[index]->data.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	else
	{
		cout << "ERROR\n";
	}
}

void HSubject::addSubjectAndTitle(string subject, string title)
{
	int index = search(subject);
	if (index != -1)
	{
		table[index]->data.push_front(title);
		return;
	}
	list<string> l1;
	l1.push_front(title);
	this->add(l1, subject);
}

void HSubject::printN(string subject, int n)
{
	int index = search(subject);
	if (index != -1)
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

void HSubject::startNewTable()
{
	for (int i = 0; i < size; i++)
		table[i]->flag = empty;
}

void HSubject::print()
{
	for (int i = 0; i < size; i++)
		if (table[i]->flag == full)
		{
			cout << table[i]->key << ":";
			printS(table[i]->key);
		}

}


