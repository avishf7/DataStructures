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
	string apearrStr;
	string structTree;

	friend class compareNode;

	class HuffmanNode
	{
	public:
		HuffmanNode(string str = "", int frequency = 0) :str(str), frequency(frequency) ,left(NULL) ,right(NULL) {}
		string str;
		int frequency;
		HuffmanNode* left;
		HuffmanNode* right;

		~HuffmanNode() { delete left; delete right; }
	};
	HuffmanNode* root = NULL;

	~HuffmanTree() { delete root; }
	int	countCharacters(string str);
	void buildTree(string str);
	void orderAndStruct(HuffmanNode* current);
	string encode(string str,string rout , HuffmanNode* current);

	string rebuildTree( HuffmanNode* curr);
	
	
public:
	void printEncode(string str);
	void printDecode(string apearS, string orderT, string code);
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