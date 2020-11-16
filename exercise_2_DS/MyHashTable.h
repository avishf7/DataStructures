#pragma once

#include "Item.h"
template <class T, class K>
class MyHashTable
{
	Item<T,K>** table;
	int size;

private:
	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
	int hash(K key, int i);
	


public:
	MyHashTable(int size);

	~MyHashTable()
	{
		for (size_t i = 0; i < size-1; i++)
			delete table[i];
		delete[] table;
	}

	int search(K key);
	void add(T data, K key);
	void remove(T data, K key);
	void update(T data, K key);
	void print();
};



