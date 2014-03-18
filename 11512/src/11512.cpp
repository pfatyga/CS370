//============================================================================
// Name        : 11512.cpp
// Author      : Peter
// Version     :
// Copyright   : 
// Description : UVA Problem 11512
//============================================================================

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Trie_node {

	char c;
	unsigned int count;
	unsigned int level;
	Trie_node *parent;
	map <char, Trie_node *> children;

public:

	Trie_node()	//used for root only
	{
		c = 0;
		level = 0;
		count = 0;
		parent = NULL;
	}

	Trie_node(char c, Trie_node *parent)
	{
		this->c = c;
		this->level = parent->level + 1;
		this->count = 1;
		this->parent = parent;
	}

	void increment_count()
	{
		count++;
	}

	unsigned int getLevel()
	{
		return level;
	}

	unsigned int getCount()
	{
		return count;
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

	Trie_node *insert(string s)
	{
		Trie_node *root = this;
		for(char &c: s)
		{
			root = root->insert(c);
		}
		return root;
	}

	//get the substring at this point
	char *substring()
	{
		if(parent == NULL)
			return "";
		Trie_node *node = this;
		char *ret = new char[level+1];
		ret[level] = '\0';
		while(node->parent != NULL && node->level >= 1)
		{
			ret[node->level-1] = node->c;
			node = node->parent;
		}
		return ret;
	}

	friend std::ostream &operator<<(std::ostream &os, Trie_node const &node);

	inline bool operator<(const Trie_node& other_node) const
	{
		return level < other_node.level;
	}

	static Trie_node max(Trie_node *root)
	{
		vector<Trie_node *> bucket;
		for(map <char, Trie_node *>::iterator it = root->children.begin(); it != root->children.end(); it++)
		{
			if(it->second->count >= 2)
				bucket.push_back(it->second);
		}
		if(bucket.size() == 0)
			return *root;
		else
		{
			vector<Trie_node> child_bucket;
			for(vector <Trie_node *>::iterator it = bucket.begin(); it != bucket.end(); it++)
			{
				child_bucket.push_back(max(*it));
			}
			Trie_node max = *max_element(child_bucket.begin(), child_bucket.end());
			return max;
		}
	}

	static void pre_order_print(Trie_node *root)
	{
		if(root == NULL)
			return;
		cout << (*root) << '\n';
		for(map <char, Trie_node *>::iterator it = root->children.begin(); it != root->children.end(); it++)
			pre_order_print(it->second);
	}
};

std::ostream &operator<<(std::ostream &os, Trie_node const &node) {
	if(node.parent == NULL)
	{
		return os << "Trie Node: [Root]";
	}
	else
	{
		return os << "Trie Node: [" << node.c << ":" << node.level << ":" << node.count << "]";
	}
}

int main() {
	unsigned int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		Trie_node *root = new Trie_node();
		string s;
		cin >> s;
		for(unsigned int i = 0; i < s.length(); i++)
			root->insert(s.substr(i));
		//Trie_node::pre_order_print(root);
		Trie_node max = Trie_node::max(root);
		if(max.getCount() > 0)
			cout << max.substring() << " " << max.getCount() << '\n';
		else
			cout << "No repetitions found!\n";
	}
	return 0;
}
