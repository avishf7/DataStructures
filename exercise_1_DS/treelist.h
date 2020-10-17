#pragma once

#include "Tree.h"

class treelist
{
private:
	list<Tree> listOfTrees;
public:
	treelist() {};

	void clear()
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
			listOfTrees.erase(it);
	}

	~treelist()
	{
		clear();
	}

	void add()
	{
		Tree tree;
		listOfTrees.push_back(tree);
	}

	void remove(Tree tree)
	{
		listOfTrees.remove(tree);
	}

	void searchAndPrint(string tree, string discussion)
	{
		for (auto it = listOfTrees.begin(); it != listOfTrees.end(); it++)
		{
				if ((*it).Search(discussion))
				{
					(*it).printMaslul(discussion);
					(*it).printSubTree(discussion);
				}
		}
	}

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
