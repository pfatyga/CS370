#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NULL
#define NULL (void*)0
#endif

typedef struct s_node {
	char c;
	int count;
	struct s_node* child;
	struct s_node* sibling;
} t_node;

typedef struct s_word {
	char *word;
	int count;
} t_word;

t_word *max_word_internal(t_node *root, t_word *current_branch) {
	if(root == NULL)
		return NULL;	
	if(root->c == 0) {
		return max_word_internal(root->child, current_branch);		
	}
	t_word *new_branch = (t_word *)calloc(1, sizeof(t_word));
	char *new_branch_word = (char *)calloc(strlen(current_branch->word)+2, sizeof(char));
	strcpy(new_branch_word, current_branch->word);
	new_branch_word[strlen(new_branch_word)] = root->c;	/*append c to currentBranch*/
	new_branch->word = new_branch_word;
	new_branch->count = root->count;	
	if(root->child == NULL && root->sibling == NULL) 
	{
		free(current_branch->word);
		free(current_branch);
		return new_branch;
	}
	else if(root->child == NULL)
	{	/*compare new_branch to sibling*/
		t_word *sibling_branch = max_word_internal(root->sibling, current_branch);
		if(sibling_branch->count > new_branch->count)
		{
			return sibling_branch;
		}
		else
		{
			return new_branch;
		}
	}
	else if(root->sibling == NULL)
	{
		free(current_branch->word);
		free(current_branch);
		return max_word_internal(root->child, new_branch);
	}
	else	/*neither are NULL*/
	{
		t_word *sibling_branch = max_word_internal(root->sibling, current_branch);
		t_word *this_branch = max_word_internal(root->child, new_branch);
		if(sibling_branch->count > this_branch->count)
		{			
			return sibling_branch;
		}
		else
		{			
			return this_branch;
		}
	}
}

t_word *max_word(t_node *root) {
	t_word *empty_root_word = (t_word *)calloc(1, sizeof(t_word));
	empty_root_word->word = (char *)calloc(1, sizeof(char));
	return max_word_internal(root, empty_root_word);
}

void free_tree(t_node *root) {
	if(root == NULL)
		return;
	if(root->c == 0)
	{
		free_tree(root->child);
		return;
	}
	free_tree(root->child);
	free_tree(root->sibling);
	free(root);
}

void print_tree_internal(t_node *root, char *currentBranch) {
	/*printf("c: %c, currentBranch: %s\n", root->c, currentBranch);*/
	if(root == NULL)
		return;	
	if(root->c == 0) {
		print_tree_internal(root->child, currentBranch);
		return;
	}
	char *newBranch = (char *)calloc(strlen(currentBranch)+2, sizeof(char));
	strcpy(newBranch, currentBranch);
	newBranch[strlen(newBranch)] = root->c;	/*append c to currentBranch*/
	if(root->child == NULL) {
		/*this is a leaf node so print*/
		printf("%s: %i\n", newBranch, root->count);
		free(newBranch);		

	} else {
		/*not a leaf node, continue recursion down child branch*/
		print_tree_internal(root->child, newBranch);
	}
	
	if(root->sibling == NULL) {
		/*already handled children and no siblings so we can free currentBranch*/
		free(currentBranch);
		return;
	} else {
		/*continue recursion on siblings*/
		print_tree_internal(root->sibling, currentBranch);
	}

}

void print_tree(t_node *root) {
	print_tree_internal(root, (char *)calloc(1, sizeof(char)));
}

t_node *add(t_node *root, char c) {
	t_node *new_node;
	if(root->child == NULL) {
		new_node = (t_node *)calloc(1, sizeof(t_node));
		new_node->c = c;
		new_node->count = 1;
		new_node->child = NULL;
		new_node->sibling = NULL;
		root->child = new_node;
		return root->child;
	} else {
		if(root->child->c == c) {
			root->child->count++;
			return root->child;
		} else {
			/*go through siblings of child*/
			root = root->child;
			while(root->sibling != NULL) {
				root = root->sibling;
				if(root->c == c) {
					root->count++;
					return root;
				}
			}
			new_node = (t_node *)calloc(1, sizeof(t_node));
			new_node->c = c;
			new_node->count = 1;
			new_node->child = NULL;
			new_node->sibling = NULL;
			root->sibling = new_node;
			return root->sibling;
		}
			
	}
}

int main(int argc, char** argv)
{

	int i = 0;
	int n = 0;
	int k = 0;
	char string[1000000];	/*max size of input unknown*/
    	t_node *root = (t_node *)calloc(1, sizeof(t_node));


	while(scanf("%d %s", &n, string) == 2) {
		
        	for(i = 0; i <= (strlen(string) - n); i++) {
			t_node *temp = root;
			int j = i + n;	/*abcdefg -> if n = 3 and i = 2 then we want to go through the letters cde so we have to loop from i to j*/
			/*printf("%i to %i\n", i, j);*/
			for(k = i; k < j; k++) {
				/*printf("Adding %c\n", string[k]);*/
				temp = add(temp, string[k]);
			}
			/*print_tree(root);*/
			/*printf("--------------------------\n");*/
		}
		/*print_tree(root);*/
		t_word *max = max_word(root);
		printf("%s\n", max->word);
		free_tree(root);
		
	}
	return 0;
}
