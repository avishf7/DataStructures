//Avishay Farkash 205918790
//Shai Axelrod 205544307
#include <iostream>
#include <queue>
#include <list>
#include <string>
#ifndef HUFFMAN_H
#define HUFFMAN_H
using namespace std;

class compareNode;

/// <summary>
/// Class for encoding and decoding text by the Huffman tree
/// </summary>
class HuffmanTree
{
	string apearrStr;//order of the characters in the string
	string structTree;//The structure of the tree
	
	friend class compareNode;//Class for encoding and decoding text by the Huffman tree
	/// <summary>
	/// class for singel node in the tree
	/// </summary>
	class HuffmanNode
	{
	public:
		HuffmanNode(string str = "", int frequency = 0) :str(str), frequency(frequency) ,left(NULL) ,right(NULL) {}//ctor
		string str;//the string of the node/Descendants of the node
		int frequency;//the  frequency of the node/Descendants of the node
		HuffmanNode* left;//left son
		HuffmanNode* right;//right son

		~HuffmanNode() { delete left; delete right; }//dtor
	};
	HuffmanNode* root = NULL;//root of the tree

	~HuffmanTree() { delete root; }//dtor
 
	int	countCharacters(string str);//The function receives a string and returns the number of different characters in it
	
	void buildTree(string str);//The function gets a string and builds the Huffman tree for it
	
	void orderAndStruct(HuffmanNode* current);// A recursive function for finding the structure of the tree and the order of the leaves in the tree
	
	string encode(string str,string rout , HuffmanNode* current);// A recursive function that receives a char and encrypts it according to the Huffman tree

	string rebuildTree( HuffmanNode* curr);
	
	
public:
	void printEncode(string str);
	
	void printDecode(string apearS, string orderT, string code);
};

/// <summary>
/// Class for comparing two nodes
/// </summary>
class compareNode
{
public:
	bool operator()(HuffmanTree::HuffmanNode* const& n1, HuffmanTree::HuffmanNode* const& n2)//The comparison function
	{
		return n1->frequency > n2->frequency;
	}
};


#endif