#ifndef HSubject_h
#define HSubject_h
#include <list>
#include<string>
#include "MyHashTable.h"

using namespace std;

class HSubject : public MyHashTable<list<string>, string>
{ 

	int h1(string key);
	int h2(string key);
public:


	HSubject(int size) : MyHashTable(size) {}
	void printS(string subject);
	void addSubjectAndTitle(string subject, string title);
	void printN(string subject, int n);
	void startNewTable();
	void print();

};

#endif