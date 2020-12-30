//Avishay Farkash 205918790
//Shai Axelrod 205544307
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#ifndef HUFFMAN_H
#define HUFFMAN_H


class compareNode;




class HuffmanTree
{
	friend class compareNode;
	class HuffmanNode
	{
	public:
		string str;
		int frequency;

		HuffmanNode* left;
		HuffmanNode* right;

	};

	HuffmanNode* root;
	
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