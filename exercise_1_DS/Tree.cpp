//Avishay Farkash 205918790
//Shai Axelrod 205544307
#include "Tree.h"

//Recursive function-Receives a string and returns a pointer to the node that contains it
Tree::Node* Tree::Search(string discussion, Node* current)
{
	if (current->content == discussion)//If it is in the current node-return pointer to it
		return current;
	for (auto it = current->responses.begin(); it != current->responses.end(); it++)//search if it's in one of the boys
	{
		Node* find = Search(discussion, *it);
		if (find != NULL)
			return find;
	}
	return NULL;
}

//Recursive function-Gets a string and returns a pointer to the father of the node that contains it
Tree::Node* Tree::seasrchFather(string discussion, Node* current)
{
	for (auto it = current->responses.begin(); it != current->responses.end(); it++)
	{
		if (Node* find = seasrchFather(discussion, *it))
			return find;

		if ((*it)->content == discussion)
			return current;
	}

	return NULL;
}

//Recursive function-Prints the tree hierarchically
void Tree::print(Node* current, int space)
{
	for (int i = 0; i < space * 3; i++)//Print space as needed
		cout << " ";

	cout << current->content << endl;//Print the contents of the node

	for (auto it = current->responses.begin(); it != current->responses.end(); it++)//Print his sons
		print(*it, space + 1);
}

//Recursive function-Gets a string and prints the route from the root to the node
void Tree::printMaslul(string discussion, Node* current)
{
	if (current->content != discussion)
		for (auto it = current->responses.begin(); it != current->responses.end(); it++)//Find out where the string is and continue printing according to the route
		{
			if (Search(discussion, *it) != NULL)
			{
				printMaslul(discussion, *it);
				if (current->content != discussion)
					cout << current->content;//print the current node
				if (current->content != root->content)
					cout << "=>";
				return;
			}
		}
}

Tree::Tree() { root = NULL; }//ctor

string Tree::getRootString() const { if (root) return root->content; else return ""; }  //getter-Returns the root contents

//Puts a new string at the root and delete the old tree
void Tree::setroot(string discussion)
{
	delete root;
	root = new Node;
	root->content = discussion;
}

Tree::~Tree()//dtor
{
	delete root;
	root = NULL;
}

//Receives a string and returns a pointer to the node that contains it
Tree::Node* Tree::Search(string discussion)
{
	return Search(discussion, root);//Calls a recursive function
}

//Gets a string and a response string on it, and adds the response to the tree
bool Tree::add(string father, string son)
{
	Node* fatherP = Search(father);//find the node of the father

	if (fatherP)//If there is such a string in the tree
	{
		Node* newrespones = new Node;
		newrespones->content = son;
		fatherP->responses.push_back(newrespones);
	}

	return fatherP;
}

//Gets a string and delete all of its sub-tree from the tree
bool Tree::remove(string discussion)
{
	if (root->content == discussion)//If you need to delete the root
	{
		delete root;
		return (root = NULL);

	}
	else
	{
		Node* toRemove = Search(discussion);//Find the node to delete
		if (toRemove)
		{
			Node* toRemoveFather = seasrchFather(discussion, root);//find its father

			toRemoveFather->responses.remove(toRemove);//delete from the tree
		}

		return toRemove;
	}
}

//Prints the tree hierarchically
void Tree::print()
{
	if (root)
		print(root, 0);//Calls a recursive function
}

//Gets a stringand prints the route from the root to the node
void Tree::printMaslul(string discussion)
{
	if (Search(discussion))
	{
		if (discussion != root->content)
			cout << "<=";
		printMaslul(discussion, root);//Calls a recursive function
	}
}

//Gets a string and prints its subtree
void Tree::printSubTree(string discussion)
{
	if (Node* rootToPrint = Search(discussion))
		print(rootToPrint, 0);//Calls a recursive function
}

