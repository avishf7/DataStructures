#pragma once
#include <string>
#include <iostream>
#include <list>
using namespace std;
class Tree
{
private:

	class Node
	{
	public:
		string content;
		list<Node*>responses;
		~Node()
		{
			for (auto it = responses.begin(); it != responses.end(); it++)
				delete* it;
		}
	};

	Node* root;

	Node* Search(string discussion, Node* current)
	{
		if (current->content == discussion)
			return current;
		for (auto it = current->responses.begin(); it != current->responses.end(); it++)
		{
			Node* find = Search(discussion, *it);
			if (find != NULL)
				return find;
		}
		return NULL;
	}

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


	void print(Node* current, int space)
	{
		for (int i = 0; i < space * 3; i++)
			cout << " ";

		cout << current->content << endl;

		for (auto it = current->responses.begin(); it != current->responses.end(); it++)
			print(*it, space + 1);
	}

	void printMaslul(string discussion, Node* current, int space)
	{
		cout << current->content;

		for (auto it = current->responses.begin(); it != current->responses.end(); it++)
		{
			Node* find = Search(discussion, *it);
			if (find == NULL)
				continue;
			cout << "->";
			printMaslul(discussion, *it, space + 1);
		}
	}
public:
	Tree() { root = NULL; }

	string getRootString() { return root->content; } //getter

	void setroot(string discussion)
	{
		delete root;
		root = new Node;
		root->content = discussion;
	}

	~Tree()
	{
		delete root;
		root = NULL;
	}

	Node* Search(string discussion)
	{
		return Search(discussion, root);
	}

	bool add(string father, string son)
	{
		Node* fatherP = Search(father);

		if (fatherP)
		{
			Node* newrespones = new Node;
			newrespones->content = son;
			fatherP->responses.push_back(newrespones);
		}

		return fatherP;
	}

	bool remove(string discussion)
	{
		if (root->content == discussion)
		{
			delete root;
			return (root = NULL);

		}
		else
		{
			Node* toRemove = Search(discussion);
			if (toRemove)
			{
				Node* toRemoveFather = seasrchFather(discussion, root);

				toRemoveFather->responses.remove(toRemove);
			}

			return toRemove;
		}
	}

	void print()
	{
		if (root)
			print(root, 0);
	}
	void printMaslul(string discussion)
	{
		if (Search(discussion))
			printMaslul(discussion, root, 0);
	}
	void printSubTree(string discussion)
	{
		if (Node* rootToPrint = Search(discussion))
			print(rootToPrint, 0);
	}
};




