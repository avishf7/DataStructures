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

	
};
