#pragma once
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
	Node* Search(string discussion, Node* current)
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
	Node* seasrchFather(string discussion, Node* current)
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
	void print(Node* current, int space)
	{
		for (int i = 0; i < space * 3; i++)//Print space as needed
			cout << " ";

		cout << current->content << endl;//Print the contents of the node

		for (auto it = current->responses.begin(); it != current->responses.end(); it++)//Print his sons
			print(*it, space + 1);
	}

	//Recursive function-Gets a string and prints the route from the root to the node
	void printMaslul(string discussion, Node* current)
	{
		cout << current->content;//print the current node

		for (auto it = current->responses.begin(); it != current->responses.end(); it++)//Find out where the string is and continue printing according to the route
		{
			if (Search(discussion, *it) != NULL)
			{
				cout << "->";
				printMaslul(discussion, *it);
				return;
			}
		}
	}
public:

	Tree() { root = NULL; }//ctor

	string getRootString() const { return root->content; }  //getter-Returns the root contents

	//Puts a new string at the root and delete the old tree
	void setroot(string discussion)
	{
		delete root;
		root = new Node;
		root->content = discussion;
	}

	~Tree()//dtor
	{
		delete root;
		root = NULL;
	}

	//Receives a string and returns a pointer to the node that contains it
	Node* Search(string discussion)
	{
		return Search(discussion, root);//Calls a recursive function
	}

	//Gets a string and a response string on it, and adds the response to the tree
	bool add(string father, string son)
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
	bool remove(string discussion)
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
	void print()
	{
		if (root)
			print(root, 0);//Calls a recursive function
	}

	//Gets a stringand prints the route from the root to the node
	void printMaslul(string discussion)
	{
		if (Search(discussion))
			printMaslul(discussion, root);//Calls a recursive function
	}

	//Gets a string and prints its subtree
	void printSubTree(string discussion)
	{
		if (Node* rootToPrint = Search(discussion))
			print(rootToPrint, 0);//Calls a recursive function
	}
};
