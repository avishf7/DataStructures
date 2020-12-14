#include "Trie.h"
#include <iostream>
using namespace std;

void Trie::Insert(string str)
{
	insert(str, root);
}

void Trie::insert(string str, TrieNode* node)
{
	//Stops when reaching the end of inserting the string 
	//or inserting an empty string
	if (str.length() == 0)
		return;

	char ch = str[0];


	if (node->children[ch - 97] == NULL)
	{
		//Inserts a character into the tree 
		//in case there is no character in the track
		node->children[ch - 97] = new TrieNode(node);
		node->count++;
	}

	//Changes the flag after inserting the last letter:
	if (str.length() == 1)
		node->children[ch - 97]->isEndWord = true;

	insert(str.substr(1, str.length() - 1), node->children[ch - 97]);
}

bool Trie::Delete(string str)
{
	TrieNode* last = find(str,root);

	if (!last)
		return false;

	//Change the flag for a case where there are other words in the tree
	//that contain the deleted word
	last->isEndWord = false; 

	//Deletes all characters that have been prompted to delete
	//in case there are no more words using characters:
	for (TrieNode* i = last; i->father != NULL && i->count == 0;)
	{
		i->father->children[str[str.length() - 1] - 97] = NULL;
		i->father->count--;
		last = i;
		i = i->father;
		delete last;
		str = str.substr(0, str.length() - 1);
	}

	return true;
}



Trie::TrieNode* Trie::findPrefix(string str, TrieNode* node)
{
	if (str.length() == 0)//We reached a node representing the end of the string
		return node;

	char ch = str[0];
	if (node->children[ch - 97] == NULL)//One letter is missing
		return	NULL;
	return findPrefix(str.substr(1, str.length() - 1), node->children[ch - 97]);
}

bool Trie::PrintAllWordsFromPrefix(string str)
{
	TrieNode* node;
	if (!(node = findPrefix(str, root)))
		return false;
	else
		PrintAllWordsFromPrefix(str, node);
	return true;
}
void Trie::PrintAllWordsFromPrefix(string str, TrieNode* node)
{
	if (node->isEndWord)
		cout << str << endl;
	for (int i = 0; i < 26; i++)
	{
		if (node->children[i])
		{
			string newstr = str + (char)(i + 97);
			PrintAllWordsFromPrefix(newstr, node->children[i]);
		}
	}

}

bool Trie::Search(string str)
{
	if (!find(str, root))
		return false;
	return true;
}

Trie::TrieNode* Trie::find(string str, TrieNode* node)
{
	if (str.length() == 0)
		if (node->isEndWord == true)
			return node;
		else
			return	NULL;
	char ch = str[0];
	if (node->children[ch - 97] == NULL)
		return	NULL;
	return find(str.substr(1, str.length() - 1), node->children[ch - 97]);
}




