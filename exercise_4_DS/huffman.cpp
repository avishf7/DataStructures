#include <list>
#include <algorithm>
#include <iostream>
#include "huffman.h"
using namespace std;

int HuffmanTree::countCharacters(string str)
{
	int characters = 0;
	list<char> l1;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (l1.end() ==  find(l1.begin(), l1.end(), str[i]))
		{
			l1.push_back(str[i]);
			characters++;
		}
		
	}
	return characters;
}

void HuffmanTree::buildTree(string str)
{
	priority_queue<HuffmanTree::HuffmanNode*, vector<HuffmanTree::HuffmanNode*>, compareNode> pQueue;
	
	vector<char> l1;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (l1.end() == find(l1.begin(), l1.end(), str[i]))
		{
			l1.push_back(str[i]);
		}
	}

	string strTemp;
	for (int i = 0; i < l1.size(); i++)
	{
		strTemp = l1[i];
		pQueue.push(new HuffmanNode(strTemp, count(str.begin(), str.end(), l1[i])));
	}

	for (int i = 1; i < pQueue.size() - 1; i++)
	{
		HuffmanNode* x = pQueue.top();
		pQueue.pop();
		
		HuffmanNode* y = pQueue.top();
		pQueue.pop();
	

		HuffmanNode * z = new HuffmanNode(x->str + y->str, x->frequency + y->frequency);
		z->left = x;
		z->right = y;
		pQueue.push(z);
	}
	root = pQueue.top();
	
}

void HuffmanTree::orderAndStruct(HuffmanNode* current)
{
	if (current->left == NULL)
	{
		structTree += "1";
		apearrStr += current->str;
		return;
	}

	structTree += "0";
	orderAndStruct(current->left);
	orderAndStruct(current->right);
}

string HuffmanTree::encode(string str,  string rout,  HuffmanNode* current)
{
	if (current->str == str)
		return rout;

	if((current->left->str.find(str)!= string::npos))
		return encode(str,rout + "0", current->left);
	if ((current->right->str.find(str) != string::npos))
		return encode(str, rout + "1", current->right);
}
