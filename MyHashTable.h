#pragma once

#include <iostream>
#include "Item.h"
using namespace std;

template <class T, class K>
class MyHashTable
{
protected:	
	Item<T,K>** table;
	int size;


	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
	int hash(K key, int i);
public:
	MyHashTable(int size);

	~MyHashTable()
	{
		for (int i = 0; i < size; i++)
			delete table[i];
		delete[] table;
	}

	void print();
	void update(T data, K key);
	void remove(K key);
	void add(T data, K key);
	int search(K key);

};

class MyHashTable
{
};

