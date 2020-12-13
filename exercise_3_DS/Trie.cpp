#include "Trie.h"

void Trie::Insert(string str)
{
	insert(str, root);

}

bool Trie::Delete(string str)
{
	TrieNode* last;

	if (!(last = Search(str)))
		return false;

	last->isEndWord = false;

	for (auto i = last; i != NULL, i->count == 0;)
		{
			i->father->children[str[str.length() - 1]] = NULL;
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
	return search(str, root);
}

Trie::TrieNode* Trie::search(string str, TrieNode* node)
{
	if (str.length() == 0)
		if (node->isEndWord == true)
			return node;
		else
			return	NULL;
	char ch = str[0];
	if (node->children[ch - 97] == NULL)
		return	NULL;
	search(str.substr(1, str.length() - 1), node->children[ch - 97]);
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
