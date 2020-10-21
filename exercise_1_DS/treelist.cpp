//Avishay Farkash 205918790
//Shai Axelrod 205544307
#include "treelist.h"

void treeList::addNewTree(string discussion)
{
	Tree tree;
	listOfTrees.push_front(tree);
	listOfTrees.front().setroot(discussion);

}

void treeList::remove(Tree::Node* root)
{
	for (list<Tree>::iterator it = listOfTrees.begin(); it != listOfTrees.end(); it++)
		if ((*it).root == root)
			listOfTrees.erase(it);
}

bool treeList::searchAndPrint(string discussion)
{
	bool flag = false; //flag to check if exists one appearance of the discussion

	for (list<Tree>:: iterator it = listOfTrees.begin(); it != listOfTrees.end(); it++)
	{
		if ((*it).Search(discussion))
		{
			flag = true;
			if (it->getRootString() != "")
				cout << endl;
			(*it).printSubTree(discussion);
			(*it).printMaslul(discussion);
		}
	}
	return flag;
}

bool treeList::addResponse(string title, string father, string son)
{
	for (list<Tree>:: iterator it = listOfTrees.begin(); it != listOfTrees.end(); it++)
	{
		if ((*it).getRootString() == title)
			return ((*it).add(father, son));
	}

	return false;
}

bool treeList::delResponse(string title, string son)
{
	for (list<Tree>:: iterator it = listOfTrees.begin(); it != listOfTrees.end(); it++)
	{
		if ((*it).getRootString() == title)
		{
			if (title != son)                 
				return ((*it).remove(son));   

			// if the node we want to delete is a root
			// remove the tree from the tree list
			remove(it->root);
			return true;
		}
	}

	return false;
}

bool treeList::printTree(string s)
{
	for (list<Tree>:: iterator it = listOfTrees.begin(); it != listOfTrees.end(); it++)
	{
		if ((*it).getRootString() == s)
		{
			(*it).print();
			return true;
		}
	}
	return false;
}

void treeList::printSubTree(string title, string val)
{
	for (list<Tree>:: iterator it = listOfTrees.begin(); it != listOfTrees.end(); it++)
		if ((*it).getRootString() == title)
			(*it).printSubTree(val);
}

void treeList::printAllTrees()
{
	int i = 1;
	for (list<Tree>:: iterator it = listOfTrees.begin(); it != listOfTrees.end(); it++)
	{
		cout << "Tree #" << i++ << endl;
		(*it).print();
		cout << endl;
	}
}

bool treeList::printPartOfTree(string tree, string discussion)
{
	for (list<Tree>:: iterator it = listOfTrees.begin(); it != listOfTrees.end(); it++)
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
