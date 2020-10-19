#pragma once

#include "Tree.h"

class treeList
{
private:

	list<Tree> listOfTrees;

public:

	treeList() {};  // constructor

	//clean the list
	void clear()
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
			it->clear();
	}

	~treeList() //destructor
	{
		clear();
	}

	// Gets a string and adds to the tree list 
	// a new tree with a root containing that string
	void addNewTree(string discussion)
	{
		Tree tree;
		listOfTrees.push_back(tree);
		listOfTrees.back().setroot(discussion);	
	}

	// Gets a Tree object 
	// and deletes it from the list of trees 
	void remove(Tree tree)
	{
		listOfTrees.remove_if([&](const Tree t) { return t.getRootString() == tree.getRootString(); });;
	}

	// Gets a string and if it appears in the tree from the list of trees,
	// prints the arrival route and the sub-tree from that string
	void searchAndPrint(string discussion)
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
		{
				if ((*it).Search(discussion))
				{
					(*it).printMaslul(discussion);
					if (it->getRootString() != "")
						cout << endl;
					(*it).printSubTree(discussion);
				}
		}
	}

	// Gets 3 strings,
    // looking for a tree root that matches the first string,
    // and inserts the third string to be a son of the vertex 
	// which matching to the second string in the fit tree
	bool addResponse(string title, string father, string son)
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
		{
			if ((*it).getRootString() == title)
				return ((*it).add(father, son));
		}

		return false;
	}

	// Gets 2 strings,
	// looking for a tree root that matches the first string,
	// and removes the second string in the fit tree
	bool delResponse(string title, string son)
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
		{
			if ((*it).getRootString() == title)
				return ((*it).remove(son));
		}

		return false;
	}

	// Gets string and prints the tree whose root matches the same string
	bool printTree(string s)
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
		{
			if ((*it).getRootString() == s)
			{
				(*it).print();
				return true;
			}
		}
		return false;
	}

	// Gets 2 strings,
	// looking for a tree root that matches the first string,
	// and prints the sub-tree from that second string
	void printSubTree(string title, string val)
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
			if ((*it).getRootString() == title)
				(*it).printSubTree(val);
	}

	// print all the trees from the tree list
	void printAllTrees()
	{
		int i = 1;
		for (auto it = listOfTrees.begin() ; it != listOfTrees.end(); it++)
		{
			cout << "Tree #" << i++ << endl;
			(*it).print();
		}
	}

	// Gets two strings 
	// looking for a tree root that matches the first string,
	// and prints the arrival route and the sub-tree from the second string in this tree
	bool printPartOfTree(string tree, string discussion)
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
		{
			if ((*it).getRootString() == tree)
				if ((*it).Search(discussion))
				{
					(*it).printMaslul(discussion);
					(*it).printSubTree(discussion);
					return true;
				}
		}
		return false;
	}

};
