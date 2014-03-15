//============================================================================
// Name        : 11512.cpp
// Author      : Peter
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Trie_node {
	char c;
	unsigned int count;
	Trie_node *parent;
	map <char, Trie_node *> children;
public:

	Trie_node()	//used for root only
	{
		c = 0;
		count = 0;
		parent = NULL;
	}

	Trie_node(char c, Trie_node *parent)
	{
		this->c = c;
		this->count = 1;
		this->parent = parent;
	}

	void increment_count()
	{
		count++;
	}

	Trie_node *insert(char c)
	{
		map <char, Trie_node *>::iterator it;
		if((it = children.find(c)) != children.end()) //if c exists in children just increment its count
		{
			it->second->increment_count();
			return it->second;
		}
		else	//else create and add it to the children map
		{
			Trie_node *node = new Trie_node(c, this);
			children[c] = node;
			return node;
		}
	}

	void *insert(string s)
	{
		Trie_node *root = this;
		for(char &c: s)
		{
			root = root->insert(c);
		}
	}

	friend std::ostream &operator<<(std::ostream &os, Trie_node const &node);

	static void pre_order_traverse(Trie_node *root)
	{
		if(root == NULL)
			return;
		cout << (*root) << '\n';
		for(map <char, Trie_node *>::iterator it = root->children.begin(); it != root->children.end(); it++)
			pre_order_traverse(it->second);
	}
};

std::ostream &operator<<(std::ostream &os, Trie_node const &node) {
	if(node.parent == NULL)
	{
		return os << "Trie Node: [Root]";
	}
	else
	{
		return os << "Trie Node: [" << node.c << ":" << node.count << "]";
	}
}

int main() {
	Trie_node *root = new Trie_node();
	string s;
	cin >> s;
	root->insert(s);
	cin >> s;
	root->insert(s);
	cin >> s;
	root->insert(s);
	cin >> s;
	root->insert(s);
	cin >> s;
	root->insert(s);
	Trie_node::pre_order_traverse(root);
	return 0;
}
