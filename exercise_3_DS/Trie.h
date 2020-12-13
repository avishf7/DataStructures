//Avishay Farkash 205918790
//Shai Axelrod 205544307
#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <iostream>
using namespace std;

class Trie
{
protected:
	class TrieNode
	{
	public:
		bool isEndWord = false;
		TrieNode* children[26] = { NULL };
		TrieNode* father;
		int count = 0;

		TrieNode(TrieNode* father = NULL) :father(father) {}
	};

	TrieNode* root = new TrieNode();

public:



	void Insert(string str);
	bool Delete(string str);
	TrieNode* Search(string str);
	bool PrintAllWordsFromPrefix(string str);
private:
	TrieNode* Search(string str, TrieNode* node);
	void insert(string str, TrieNode* node);
	void PrintAllWordsFromPrefix(string str, TrieNode* node);
	TrieNode* SearchPrefix(string str, TrieNode* node);
};

#endif

