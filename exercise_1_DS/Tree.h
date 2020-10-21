//Avishay Farkash 205918790
//Shai Axelrod 205544307
#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>
#include <list>
using namespace std;
class Tree//Multi-boy tree-Represents a forum discussion
{
private:

	class Node//node in tree
	{
	public:
		string content;//Content of the discussion
		list<Node*>responses;//the responses
		~Node()//detor-Deletes the entire subtree of this node
		{
			for (auto it = responses.begin(); it != responses.end(); it++)
				delete* it;
		}
	};

	Node* root;//the root of the tree

	//Recursive function-Receives a string and returns a pointer to the node that contains it
	Node* Search(string discussion, Node* current);
	
	//Recursive function-Gets a string and returns a pointer to the father of the node that contains it
	Node* seasrchFather(string discussion, Node* current);
	
	//Recursive function-Prints the tree hierarchically
	void print(Node* current, int space);
	
	//Recursive function-Gets a string and prints the route from the root to the node
	void printMaslul(string discussion, Node* current);
	
public:

	Tree();//ctor
	
	~Tree();//dtor
	
	string getRootString() const;  //getter-Returns the root contents

	//Puts a new string at the root and delete the old tree
	void setroot(string discussion);
	
	//Receives a string and returns a pointer to the node that contains it
	Node* Search(string discussion);
	
	//Gets a string and a response string on it, and adds the response to the tree
	bool add(string father, string son);
	
	//Gets a string and delete all of its sub-tree from the tree
	bool remove(string discussion);
	
	//Prints the tree hierarchically
	void print();
	
	//Gets a stringand prints the route from the root to the node
	void printMaslul(string discussion);
	
	//Gets a string and prints its subtree
	void printSubTree(string discussion);
	
	friend class treeList;
};

#endif