//============================================================================
// Name        : 11512.cpp
// Author      : Peter
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
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

	bool operator <(const Trie_node& other)
	{
		return this->level > other.level;
	}

	friend std::ostream &operator<<(std::ostream &os, Trie_node const &node);

	static vector<Trie_node *> greater_than_two(Trie_node *root)
	{
		vector<Trie_node *> bucket;
		if(root->count >= 2)
			bucket.push_back(root);
		for(map <char, Trie_node *>::iterator it = root->children.begin(); it != root->children.end(); it++)
		{
			vector<Trie_node *> child_bucket = greater_than_two(it->second);
			for(vector<Trie_node *>::iterator it = child_bucket.begin(); it != child_bucket.end(); it++)
				bucket.push_back(*it);
		}
		return bucket;
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
		vector<Trie_node *> all_greater_than_two = Trie_node::greater_than_two(root);
		if(all_greater_than_two.size() == 0)
			cout << "No repetitions found!\n";
		else
		{
			unsigned int max_level = 0;
			vector<Trie_node *> max;
			for(vector<Trie_node *>::iterator it = all_greater_than_two.begin(); it != all_greater_than_two.end(); it++)
			{
				if((*it)->getLevel() > max_level)
				{
					max.clear();
					max.push_back(*it);
					max_level = (*it)->getLevel();
				}
				else if((*it)->getLevel() == max_level)
					max.push_back(*it);
			}
			vector<pair<string, unsigned int>> max_substrings;
			for(vector<Trie_node *>::iterator it = max.begin(); it != max.end(); it++)
			{
				max_substrings.push_back(make_pair((*it)->substring(), (*it)->getCount()));
			}
			sort(max_substrings.begin(), max_substrings.end());
			cout << max_substrings[0].first << " " << max_substrings[0].second << '\n';
		}
	}
	return 0;
}
