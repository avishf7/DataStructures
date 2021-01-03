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
		if (l1.end() == find(l1.begin(), l1.end(), str[i]))
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
	int toLoop = pQueue.size() - 1;;
	for (int i = 0; i < toLoop; i++)
	{
		HuffmanNode* x = pQueue.top();
		pQueue.pop();

		HuffmanNode* y = pQueue.top();
		pQueue.pop();

		if (y->frequency == x->frequency)
			swap(x, y);

		HuffmanNode* z = new HuffmanNode(x->str + y->str, x->frequency + y->frequency);
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



string HuffmanTree::encode(string str, string rout, HuffmanNode* current)
{
	if (current->str == str)
		return rout;

	if ((current->left->str.find(str) != string::npos))
		return encode(str, rout + "0", current->left);
	if ((current->right->str.find(str) != string::npos))


		return encode(str, rout + "1", current->right);
}

string HuffmanTree::rebuildTree(HuffmanNode* curr)
{
	if (structTree == "")
	{
		curr->str = apearrStr[0];
		apearrStr = apearrStr.substr(1, apearrStr.size() - 1);
		return curr->str;
	}

	if (structTree[0] == '0')
	{
		curr->left = new HuffmanNode();
		curr->right = new HuffmanNode();
		structTree = structTree.substr(1, structTree.size() - 1);
		curr->str += rebuildTree(curr->left);
		curr->str += rebuildTree(curr->right);
		return curr->str;
	}
	if (structTree[0] == '1')
	{
		curr->str = apearrStr[0];
		apearrStr = apearrStr.substr(1, apearrStr.size() - 1);
		structTree = structTree.substr(1, structTree.size() - 1);
		return curr->str;

	}
}


void HuffmanTree::printEncode(string str)
{
	cout << "The encoded string is:" << endl;
	cout << countCharacters(str) << endl;
	buildTree(str);
	orderAndStruct(root);
	cout << apearrStr << endl;
	cout << structTree << endl;
	for (int i = 0; i < (int)str.length(); i++)
	{
		string curremtChar; curremtChar += str[i];
		cout << encode(curremtChar, "", root);

	}
	cout << "\n";

	delete root;
	this->apearrStr = "";
	this->structTree = "";
}

void HuffmanTree::printDecode(string apearS, string orderT, string code)
{
	apearrStr = apearS;
	structTree = orderT;

	root = new HuffmanNode();
	rebuildTree(root);

	HuffmanNode* curr = root;
	cout << "The decoded string is: ";
	for (int i = 0; i < code.size()+1; i++)
		if (curr->left == NULL)
		{
			cout << curr->str;
			curr = root;
			i--;
		}
		else if (code[i] == '0')
			curr = curr->left;
		else
			curr = curr->right;
	cout << endl;
	delete root;
	this->apearrStr = "";
	this->structTree = "";
}


