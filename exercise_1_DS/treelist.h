#include "Tree.h"

class treelist
{
private:
	list<Tree> listoftrees;
public:
	treelist() {};
	void clear()
	{
		for (auto it = listoftrees.begin(); it != listoftrees.end(); it++)
			listoftrees.erase(it);
	}
	void add()
	{
		Tree tree;
		listoftrees.push_back(tree);
	}
	void remove(Tree tree)
	{
		listoftrees.remove(tree);
	}
};
