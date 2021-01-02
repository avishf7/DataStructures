//Avishay Farkash 205918790
//Shai Axelrod 205544307
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#ifndef HUFFMAN_H
#define HUFFMAN_H
using namespace std;

class compareNode;




class HuffmanTree
{
	int characters = 0;
	string order;
	string structure;
	string encode;
	friend class compareNode;
	class HuffmanNode
	{
	public:
		HuffmanNode(string str, int frequency) :str(str), frequency(frequency) {}
		string str;
		int frequency;
		HuffmanNode* left;
		HuffmanNode* right;

	};
	HuffmanNode* root;
	HuffmanTree(string str);
	int	countCharacters(string str);
	HuffmanNode* buildTree(string str);
public:


	//priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
};

class compareNode
{
public:
	bool operator()(HuffmanTree::HuffmanNode* const& n1, HuffmanTree::HuffmanNode* const& n2)
	{
		return n1->frequency > n2->frequency;
	}
};


#endif