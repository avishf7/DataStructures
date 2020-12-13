//Avishay Farkash 205918790
//Shai Axelrod 205544307
#ifndef TRIE_H
#define TRIE_H
#include <string>
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
	void PrintAllWordsFromPrefix(TrieNode*);
private:
	TrieNode* search(string str, TrieNode* node);
	bool insert(string str, TrieNode* node);
	

};

#endif

