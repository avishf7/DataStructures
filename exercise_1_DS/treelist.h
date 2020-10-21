//Avishay Farkash 205918790
//Shai Axelrod 205544307
#ifndef TREELIST_H
#define TREELIST_H

#include "Tree.h"

class treeList
{
private:

	list<Tree> listOfTrees;
	

public:
	// constructor
	treeList() {};

	//destructor
	~treeList() { listOfTrees.clear(); }

	// Gets a string and adds to the tree list 
	// a new tree with a root containing that string
	void addNewTree(string discussion);
	
	// Gets a Tree object 
	// and deletes it from the list of trees 
	void remove(Tree::Node* root);

	// Gets a string and if it appears in the tree from the list of trees,
	// prints the arrival route and the sub-tree from that string
	bool searchAndPrint(string discussion);

	// Gets 3 strings,
	// looking for a tree root that matches the first string,
	// and inserts the third string to be a son of the vertex 
	// which matching to the second string in the fit tree
	bool addResponse(string title, string father, string son);

	// Gets 2 strings,
	// looking for a tree root that matches the first string,
	// and removes the second string in the fit tree
	bool delResponse(string title, string son);

	// Gets string and prints the tree whose root matches the same string
	bool printTree(string s);

	// Gets 2 strings,
	// looking for a tree root that matches the first string,
	// and prints the sub-tree from that second string
	void printSubTree(string title, string val);

	// print all the trees from the tree list
	void printAllTrees();

	// Gets two strings 
	// looking for a tree root that matches the first string,
	// and prints the arrival route and the sub-tree from the second string in this tree
	bool printPartOfTree(string tree, string discussion);
};

#endif