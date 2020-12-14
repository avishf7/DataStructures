//Avishay Farkash 205918790
//Shai Axelrod 205544307
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
	if (!(node = findPrefix(str, root)))//If there is no such string in the tree
		return false;
	else//Call the recursive function that will do the printing
		PrintAllWordsFromPrefix(str, node);
	return true;
}

void Trie::PrintAllWordsFromPrefix(string str, TrieNode* node)
{
	if (node->isEndWord)//If the string is a word in the tree
		cout << str << endl;
	for (int i = 0; i < 26; i++)//For each son - send the string with the appropriate letter
	{
		if (node->children[i])//if this son isnt null
		{
			string newstr = str + (char)(i + 97);
			PrintAllWordsFromPrefix(newstr, node->children[i]);
		}
	}

}

bool Trie::Search(string str)
{
	if (!find(str, root))//if "find" returned null-There is no such string in the tree
		return false;
	return true;
}

Trie::TrieNode* Trie::find(string str, TrieNode* node)
{
	if (str.length() == 0)//If you have reached the end of the string
		if (node->isEndWord == true)//If it's a word in the tree
			return node;
		else//If it isnt a word in the tree
			return	NULL;
	//If you have not reached the end of the word - continue to row in the direction of the trajectory of the string recursively
	char ch = str[0];
	if (node->children[ch - 97] == NULL)//If the continuation of the string is not in the tree
		return	NULL;
	return find(str.substr(1, str.length() - 1), node->children[ch - 97]);
}




