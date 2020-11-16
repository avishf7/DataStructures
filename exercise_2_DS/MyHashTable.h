#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <cmath>
#include <iostream>
#include "Item.h"

template <class T, class K>
class MyHashTable
{
protected:
	Item<T, K>** table;
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

template<class T, class K>
int MyHashTable<T, K>::hash(K key, int i)
{
	return (h1(key) + i * h2(key)) % size;
}

template<class T, class K>
MyHashTable<T, K>::MyHashTable(int size)
{
	int j;
	bool isDiv = false, isFound = false;

	for (j = size; !isFound; isFound = !isDiv, j++)
		for (int i = 3; !isDiv && i <= sqrt(size); i += 2)
			isDiv = (j % i == 0);

	table = new Item<T, K> * [--j];
	this->size = j;
	for (int i = 0; i < size; i++)
		table[i] = new Item<T, K>();
}

template<class T, class K>
void MyHashTable<T, K>::print()
{
	for (int i = 0; i < size; i++)
		if (table[i]->flag == full)
		{
			std::cout << table[i]->key << ": ";
			std::cout << table[i]->data;
		}

}

template<class T, class K>
void MyHashTable<T, K>::update(T data, K key)
{
	int i = search(key);
	if (i != -1)
		table[i]->data = data;
	else
		std::cout << "ERROR\n";
}

template<class T, class K>
void MyHashTable<T, K>::remove(K key)
{
	int i = search(key);
	if (i != -1)
		table[i]->flag = deleted;
	else
		std::cout << "ERROR\n";
}

template<class T, class K>
void MyHashTable<T, K>::add(T data, K key)
{
	int h;
	for (int i = 0; i < size; i++)
		if (!table[h = hash(key, i)]->flag)
		{
			table[h] = new Item<T, K>(data, key, full);
			return;
		}
		else if (table[h]->flag == deleted)
		{
			table[h]->data = data;
			table[h]->key = key;
			table[h]->flag = full;
			return;
		}

	std::cout << "ERROR\n";
}

template<class T, class K>
int MyHashTable<T, K>::search(K key)
{
	int h;
	for (int i = 0; i < size; i++)
		if (!table[h = hash(key, i)]->flag)
			return -1;
		else if (table[h]->flag == full)
			return i;
	return -1;
}


#endif