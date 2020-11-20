//Avishay Farkash 205918790
//Shai Axelrod 205544307

#ifndef ITEM_H
#define ITEM_H

// Represents the status of one item in the table:
enum state { empty, full, deleted };

// Each enter in the hash table is a item object that include the key
// Which determines the index and the data 
template <class T, class K>
class Item
{
public:
	T data;
	K key;
	state flag;

	//CTOR
	Item() {} 

	//CTOR - Initializes all fields
	Item(T d, K k, state f) { data = d; key = k; flag = f; }
};

#endif
