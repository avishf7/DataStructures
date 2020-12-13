#include "Trie.h"

void Trie::Insert(string str)
{
	insert(str, root);

}

bool Trie::Delete(string str)
{
	TrieNode* last = Search(str);

	if (!last)
		return false;

	last->isEndWord = false;

	for (auto i = last; i->father != NULL && i->count == 0;)
	{
		i->father->children[str[str.length() - 1]-97] = NULL;
		i->father->count--;
		last = i;
		i = i->father;
		delete last;
		str = str.substr(0, str.length() - 1);
	}

	return true;
}

Trie::TrieNode* Trie::Search(string str)
{
	return Search(str, root);
}

bool Trie::PrintAllWordsFromPrefix(string str)
{
	if (!SearchPrefix(str,root))
		return false;
	else
		PrintAllWordsFromPrefix(str, SearchPrefix(str, root));
	return true;



}

Trie::TrieNode* Trie::SearchPrefix(string str, TrieNode* node)
{
	if (str.length() == 0)
		return node;

	char ch = str[0];
	if (node->children[ch - 97] == NULL)
		return	NULL;
	return SearchPrefix(str.substr(1, str.length() - 1), node->children[ch - 97]);
}


Trie::TrieNode* Trie::Search(string str, TrieNode* node)
{
	if (str.length() == 0)
		if (node->isEndWord == true)
			return node;
		else
			return	NULL;
	char ch = str[0];
	if (node->children[ch - 97] == NULL)
		return	NULL;
	return Search(str.substr(1, str.length() - 1), node->children[ch - 97]);
}

void Trie::insert(string str, TrieNode* node)
{
	if (str.length() == 0)
		return;

	char ch = str[0];


	if (node->children[ch - 97] == NULL)
	{
		node->children[ch - 97] = new TrieNode(node);
		node->count++;
	}

	if (str.length() == 1)
		node->children[ch - 97]->isEndWord = true;


	insert(str.substr(1, str.length() - 1), node->children[ch - 97]);
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
