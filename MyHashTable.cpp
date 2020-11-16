#pragma once

#include "MyHashTable.h"
#include <cmath>
#include <iostream>

using namespace std;

template<class T, class K>
int hash(K key, int i)
{
	return (h1(key) + i * h2(key)) % size;
}

template<class T, class K>
int search(K key)
{
	int h;
	for (int i = 0; i < size; i++)
		if (!table[h = hash(key, i)]->flag)
			return -1;
		else if (table[h]->flag == full)
			return i;
	return -1;
}

template<class T, class K>
void add(T data, K key)
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

	cout << "ERROR\n";
}

template<class T, class K>
void remove(K key)
{
	int i = search(key);
	if (i != -1)
		table[i]->flag = deleted;
	else
		cout << "ERROR\n";

}

template<class T, class K>
void update(T data, K key)
{
	int i = search(key);
	if (i != -1)
		table[i]->data = data;
	else
		cout << "ERROR\n";
}

template<class T, class K>
void print()
{
	for (int i = 0; i < size; i++)
		if (table[i]->flag == full)
		{
			cout << table[i]->key << ": ";
			cout << table[i]->data;
		}
}

template<class T, class K>
MyHashTable(int size)
{
	int j;
	bool isDiv = false, isFound = false;

	for (j = size; !isFound; isFound = !isDiv, j++)
		for (int i = 3; !isDiv && i <= sqrt(size); i += 2)
			isDiv = (j % i == 0);

	table = new Item<T, K> * [--j];
	this->size = j;
	for (int i = 0; i < this->size; i++)
		table[i] = new Item<T, K>();
}
