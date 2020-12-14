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

	void Insert(string str);
	bool Delete(string str);
	
	bool Search(string str);//shai
	bool PrintAllWordsFromPrefix(string str);//shai

private:

	TrieNode* find(string str, TrieNode* node);//shai
	void insert(string str, TrieNode* node);
	void PrintAllWordsFromPrefix(string str, TrieNode* node);//shai
	TrieNode* findPrefix(string str, TrieNode* node);
	
};

#endif

