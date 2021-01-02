
#include "huffman.h"

HuffmanTree::HuffmanTree(string str)
{
	countCharacters(str);
	root = buildTree(str);
}

int HuffmanTree::countCharacters(string str)
{
	characters = 0;
	list<char> l1;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (l1.end == find(l1.begin, l1.end, str[i]))
		{
			l1.push_back(str[i]);
			characters++;
		}
		
	}
}

HuffmanTree::HuffmanNode* HuffmanTree::buildTree(string str)
{
	list<char> l1 = new list<char>();
	for (int i = 0; i < str.length(); i++)
	{
		if (l1.end == find(l1.begin, l1.end, str[i]))
		{
			l1.push_back(str[i]);
		}
	}
	priority_queue<HuffmanTree::HuffmanNode*, vector<HuffmanTree::HuffmanNode*>, compareNode> pQueue;
	for each (char ch in l1)
	{
		int count = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ch)
				count++;
		}
		
		pQueue.push(HuffmanTree::HuffmanNode * (ch, count));
	}

	return null;
}