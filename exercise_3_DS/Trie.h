//Avishay Farkash 205918790
//Shai Axelrod 205544307
#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <iostream>
using namespace std;

//Word management tree
class Trie
{
protected:
	//node in trie
	class TrieNode
	{
	public:
		bool isEndWord = false;
		TrieNode* children[26] = { NULL };
		TrieNode* father;
		int count = 0;// number of children that not NULL

		TrieNode(TrieNode* father = NULL) :father(father) {}
	};

	TrieNode* root = new TrieNode();

public:

	//Receives a string 
	//and sends to a recursive function, that will 
	//insert the string into the word management tree 
	//each letter individually.
	void Insert(string str);
	//Gets a string 
	//and deletes or cancels (changes the value of IsEndOfWord to false) 
	//The string obtained from the  word management tree
	// and returns false In case the string does not exist
	//otherwise return true.
	bool Delete(string str);
	
	bool Search(string str);//shai
	bool PrintAllWordsFromPrefix(string str);//shai

private:

	TrieNode* find(string str, TrieNode* node);//shai
	//recursive function, that will
	//insert the string into the word management tree 
	//each letter individually.
	void insert(string str, TrieNode* node);

	void PrintAllWordsFromPrefix(string str, TrieNode* node);//shai

	//A recursive function that gets a string(not necessarily a whole word)
	//and searches for it in the word management tree
	//and returns the node that represents the end of the prefix,
	//in case the string does not exist returns NULL.
	TrieNode* findPrefix(string str, TrieNode* node);
	
};

#endif

