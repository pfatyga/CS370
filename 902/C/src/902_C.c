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

char *maxWord(t_node *root) {
	return 0;
}

void print_tree_internal(t_node *root, char *currentBranch) {
	//printf("c: %c, currentBranch: %s\n", root->c, currentBranch);
	if(root == NULL)
		return;	
	if(root->c == 0) {
		print_tree_internal(root->child, currentBranch);
		return;
	}
	char *newBranch = (char *)calloc(strlen(currentBranch)+2, sizeof(char));
	strcpy(newBranch, currentBranch);
	newBranch[strlen(newBranch)] = root->c;	//append c to currentBranch
	if(root->child == NULL) {
		//this is a leaf node so print
		printf("%s: %i\n", newBranch, root->count);
		free(newBranch);		

	} else {
		//not a leaf node, continue recursion down child branch
		print_tree_internal(root->child, newBranch);
	}
	
	if(root->sibling == NULL) {
		//already handled children and no siblings so we can free currentBranch
		free(currentBranch);
		return;
	} else {
		//continue recursion on siblings
		print_tree_internal(root->sibling, currentBranch);
	}

}

void printTree(t_node *root) {
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
			//go through siblings of child
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
	//int num_substrings = 0;
	//char **substrings;
	char string[10000];
    	t_node *root = calloc(1, sizeof(t_node));


	while(scanf("%d %s", &n, string) == 2) {
        	for(i = 0; i <= (strlen(string) - n); i++) {
			t_node *temp = root;
			int j = i + n;	//abcdefg -> if n = 3 and i = 2 then we want to go through the letters cde so we have to loop from i to j
			printf("%i to %i\n", i, j);
			for(k = i; k < j; k++) {
				printf("Adding %c\n", string[k]);
				temp = add(temp, string[k]);
			}
			printTree(root);
			printf("--------------------------\n");
		}
		printTree(root);
		//num_substrings = strlen(string) - (n-1);
		//if(num_substrings <= 0)  {
		//	printf("Error: N larger than string\n");
		//	continue;
		//}

		//generate all substrings of length n
		//substrings = (char **)calloc(num_substrings, sizeof(char *));
		//for(i = 0; i < num_substrings; i++)
		//	substrings[i] = (char *)calloc((n+1), sizeof(char));
		//for(i = 0; i < num_substrings; i++)
		//	strncpy(substrings[i], &string[i], n);
		
		//TODO: calculate mode of all substrings



		//printf("length: %d, string = %s, num_substrings = %d\n", n, string, num_substrings);
		//printf("Substrings:\n");
		//for(i = 0; i < num_substrings; i++)
		//	printf("%s\n", substrings[i]);
	}


//	if(scanf("%d %d\n",&x_max,&y_max) != 2)
//		return 1;
//	if(x_max < 0 || y_max < 0)
//		return 1;
//	/*printf("Scanned %i %i\n",x_max,y_max), fflush(stdout);*/
//	scent = (char*)calloc((y_max+1)*(x_max+1),sizeof(char));
//	while(scanf("%d %d %c\n", &x_coord, &y_coord, &direction) == 3)
//	{
//		/*printf("Scanned %i %i %c\n",x_coord,y_coord,direction), fflush(stdout);*/
//		scanf("%s\n",input_buffer);
//		/*printf("Scanned %s\n",input_buffer), fflush(stdout);*/
//
//		i = 0;
//		current_instruction = &input_buffer[i];
//		while(*current_instruction != '\0' && *current_instruction != 'D')
//		{
//			/*printf("Current Instruction: %c\n",*current_instruction);*/
//			switch(*current_instruction)
//			{
//				case 'L':
//					switch(direction)
//					{
//						case 'N':
//							direction = 'W';
//							break;
//						case 'S':
//							direction = 'E';
//							break;
//						case 'E':
//							direction = 'N';
//							break;
//						case 'W':
//							direction = 'S';
//							break;
//					}
//					break;
//				case 'R':
//					switch(direction)
//					{
//						case 'N':
//							direction = 'E';
//							break;
//						case 'S':
//							direction = 'W';
//							break;
//						case 'E':
//							direction = 'S';
//							break;
//						case 'W':
//							direction = 'N';
//							break;
//					}
//					break;
//				case 'F':
//					switch(direction)
//					{
//						case 'N':
//							if(++y_coord > y_max)
//							{
//								if(test_and_add(x_coord, y_max, x_max, y_max, scent))
//									input_buffer[i+1] = 'D';
//								y_coord = y_max;
//							}
//							break;
//						case 'S':
//							if(--y_coord < 0)
//							{
//								if(test_and_add(x_coord, 0, x_max, y_max, scent))
//									input_buffer[i+1] = 'D';
//								y_coord = 0;
//							}
//							break;
//						case 'E':
//							if(++x_coord > x_max)
//							{
//								if(test_and_add(x_max, y_coord, x_max, y_max, scent))
//									input_buffer[i+1] = 'D';
//								x_coord = x_max;
//							}
//							break;
//						case 'W':
//							if(--x_coord < 0)
//							{
//								if(test_and_add(0, y_coord, x_max, y_max, scent))
//									input_buffer[i+1] = 'D';
//								x_coord = 0;
//							}
//							break;
//					}
//					break;
//			} /*switch(&current_instruction)*/
//
//			/*printf("Current loc (%i, %i, %c)\n",x_coord,y_coord,direction);*/
//
//			current_instruction = &input_buffer[++i];
//		} /*while(&current_instruction != '\0')*/
//
//		/*return result*/
//		printf("%i %i %c", x_coord, y_coord, direction);
//		if(*current_instruction == 'D')
//			printf(" LOST");
//		printf("\n"), fflush(stdout);
//
//	} /*while(scanf("%d %d %c\n", &x_coord, &y_coord, &direction) == 3)*/
//
//	free(scent);
	return 0;
}
