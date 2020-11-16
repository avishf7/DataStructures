#ifndef HSUBJECT_H
#define HSUBJECT_H

#include <list>
#include<string>
#include "MyHashTable.h"



class HSubject : public MyHashTable < std::list<std::string>, std::string >
{
	int h1(std::string key);
	int h2(std::string key);
public:


	HSubject(int size) : MyHashTable(size) {}
	void printS(std::string subject);
	void addSubjectAndTitle(std::string subject, std::string title);
	void printN(std::string subject, int n);
	void startNewTable();
	void print();

};

#endif

