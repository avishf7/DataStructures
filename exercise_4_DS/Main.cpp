//Avishay Farkash 205918790
//Shai Axelrod 205544307
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "huffman.h"

using namespace std;

int main()
{
	int choice;

	string word;

	string n;
	string letters;
	string order;
	string code;

	HuffmanTree* t = new HuffmanTree();
	cout << "enter 1 to encode a text\n";
	cout << "enter 2 to decode a text\n";
	cout << "enter 3 to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:

			cout << "enter the original text" << endl;
			cin >> word;

			t->printEncode(word);

			break;
		case 2:
			cout << "enter n ";
			cin >> n;
			cout << "enter the letters ";
			cin >> letters;
			cout << "enter the encoded structure ";
			cin >> order;
			cout << "enter the encoded text ";
			cin >> code;

			t->printDecode(letters, order, code);
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 

		}

	} while (choice != 3);
	return 0;
}