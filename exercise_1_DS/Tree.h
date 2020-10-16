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
		for (int i = 0; i < space * 3; i++)
			cout << " ";

		cout << current->content << endl;

		for (auto it = current->responses.begin(); it != current->responses.end(); it++)
		{
			Node* find = Search(discussion, *it);
			if (find == NULL)
				continue;
			printMaslul(discussion, *it, space + 1);
		}
	}
public:
	Tree() { root = NULL; }

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

	void add(string father, string son)
	{
		Node* newrespones = new Node;
		newrespones->content = son;
		Search(father)->responses.push_back(newrespones);
	}

	void remove(string discussion)
	{
		if (root->content == discussion)
		{
			delete root;
			root = NULL;
		}
		else
		{
			Node* toRemove = Search(discussion);
			Node* toRemoveFather = seasrchFather(discussion, root);

			toRemoveFather->responses.remove(toRemove);
		}
	}

	void print()
	{
		print(root, 0);
	}
	void printMaslul(string discussion)
	{
		if (Search(discussion))
			printMaslul(discussion, root, 0);
	}
	void printSubTree(string discussion)
	{
		print(Search(discussion), 0);
	}
};




