//============================================================================
// Name        : 11512.cpp
// Author      : Peter
// Version     :
// Copyright   : 
// Description : UVA Problem 11512
//============================================================================

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

unsigned int deepest_level = 0;	//keep track of the deepest internal node with count >= 2
unsigned int deepest_count = 0;
char *deepest_string = new char[1];
char *current_string;
unsigned int char_index = 0;

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
		char_index++;
		if((it = children.find(c)) != children.end()) //if c exists in children just increment its count
		{
			it->second->increment_count();

			//keep track of the deepest internal node with count > 2
			if(it->second->level > deepest_level)
			{
				deepest_level = it->second->level;
				deepest_count = it->second->count;
				delete[] deepest_string;
				deepest_string = new char[char_index+1];
				strncpy(deepest_string, current_string, char_index);
				deepest_string[char_index] = '\0';
			}
			else if(it->second->level == deepest_level)
			{
				if(strcmp(current_string, deepest_string) <= 0)
				{
					deepest_count = it->second->count;
					delete[] deepest_string;
					deepest_string = new char[char_index+1];
					strncpy(deepest_string, current_string, char_index);
					deepest_string[char_index] = '\0';
				}
			}
			//////////////////////////////////////////////////////////

			return it->second;
		}
		else	//else create and add it to the children map
		{
			Trie_node *node = new Trie_node(c, this);
			children[c] = node;
			return node;
		}
	}

	Trie_node *insert(char *s)
	{
		Trie_node *root = this;
		current_string = s;
		char_index = 0;
		for(char *c = &s[0]; *c != '\0'; c++)
		{
			root = root->insert(*c);
		}
		return root;
	}

	//get the substring at this point
	char *substring()
	{
		if(parent == NULL)
			return NULL;
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
	int n = 0;
	cin >> n;
	scanf("\n");
	for(int i = 0; i < n; i++)
	{
		deepest_count = 0;
		deepest_level = 0;
		current_string = 0;
		deepest_string = 0;
		Trie_node *root = new Trie_node();
		char *s = new char[1001];
		cin >> s;
		for(char *c = &s[0]; *c != '\0'; c++)
			root->insert(c);
		//Trie_node::pre_order_print(root);
		//Trie_node max = Trie_node::max(root);
		if(deepest_count >= 2)
			cout << deepest_string << " " << deepest_count << '\n';
		else
			cout << "No repetitions found!\n";
	}
	return 0;
}
