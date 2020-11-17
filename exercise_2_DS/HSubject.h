//Avishay Farkash 205918790
//Shai Axelrod 205544307
#ifndef HSUBJECT_H
#define HSUBJECT_H
#include <list>
#include<string>
#include "MyHashTable.h"

//hash table with key of string type and data of  string list  type
class HSubject : public MyHashTable < std::list<std::string>, std::string >
{
	int h1(std::string key);//hash function h1
	int h2(std::string key);//hash function h2(For skips in case of a collision)
public:
	HSubject(int size) : MyHashTable(size) {}//ctor that gets the table size
	void printS(std::string subject);//Printing data of a particular key
	void addSubjectAndTitle(std::string subject, std::string title);//Entering new data into the table
	void printN(std::string subject, int n);//Printing n first data strings of a particular key
	void startNewTable();//Initialize a table to the state of an empty table
	void print();//Print all the data of all the keys in the table
};

#endif

