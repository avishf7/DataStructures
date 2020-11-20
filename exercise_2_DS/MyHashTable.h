//Avishay Farkash 205918790
//Shai Axelrod 205544307

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


	virtual int h1(K key) = 0; //Determining a starting point(abstract)
	virtual int h2(K key) = 0; //Skip function((abstract)
	int hash(K key, int i); 
public:
	
	MyHashTable(int size);

	//DTOR
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

// hash function
template<class T, class K>
int MyHashTable<T, K>::hash(K key, int i)
{
	return (h1(key) + i * h2(key)) % size;
}

// CTOR - Finds a prime number greater than the size 
// and initializes the table to be the size of the same number
template<class T, class K>
MyHashTable<T, K>::MyHashTable(int size)
{
	int j;
	bool isDiv = false, isFound = false;

	for (j = size; !isFound; isFound = !isDiv, isDiv = false, j++)
		if (!(isDiv = !(j % 2 != 0)))
			for (int i = 3; !isDiv && i <= sqrt(size); i += 2)
				isDiv = (j % i == 0); // if the number is divided that means that not a prime number

	table = new Item<T, K> * [--j];
	this->size = j;
	//Initializes the entire table
	for (int i = 0; i < j; i++)
		table[i] = new Item<T, K>();
}

// Print all the data of all the keys 
// in the table that not empty or deleted
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

// Updates the data on a specific item
template<class T, class K>
void MyHashTable<T, K>::update(T data, K key)
{
	int i = search(key);
	if (i != -1)
		table[i]->data = data;
	else
		std::cout << "ERROR\n";
}

// Deletes the data in a specific item (changes its state to deleted)
template<class T, class K>
void MyHashTable<T, K>::remove(K key)
{
	int i = search(key);
	if (i != -1)
		table[i]->flag = deleted;
	
}

// Adds a new item to the table
template<class T, class K>
void MyHashTable<T, K>::add(T data, K key)
{
	int h;
	for (int i = 0; i < size; i++)
		if (!(table[h = hash(key, i)]->flag) || table[h]->flag == deleted)
		{
			table[h]->data = data;
			table[h]->key = key;
			table[h]->flag = full;
			return;
		}

	std::cout << "ERROR\n";
}

// Returns the index of an item in the table 
// and if it is not found returns 1
template<class T, class K>
int MyHashTable<T, K>::search(K key)
{
	int h;
	for (int i = 0; i < size; i++)
		if (!(table[h = hash(key, i)]->flag))
			return -1;
		else if (table[h]->flag == full)
			return h;
	return -1;
}


#endif