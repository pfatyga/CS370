#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL (void*)0
#endif

//returns most common string in array of strings with length length
char *mode(char **strings, int length) {

}

//returns all substrings with length n
char **getSubstrings(char *string, int n) {

}

int main(int argc, char** argv)
{
//	char input_buffer[101];
//	char* current_instruction;
//	int x_max = 0;
//	int y_max = 0;
//	int x_coord = 0;
//	int y_coord = 0;
//	int i = 0;
//	char direction;
//	char* scent = NULL;

	int i = 0;
	int n = 0;
	int num_substrings = 0;
	char **substrings;
	char string[10000];

	while(scanf("%d %s", &n, string) == 2) {
		num_substrings = strlen(string) - (n-1);
		substrings = calloc(num_substrings*sizeof(char *));
		for(i = 0; i < num_substrings; i++)
			substrings[i] = calloc((n+1)*sizeof(char));

		printf("length: %d, string = %s, num_substrings = %d\n", n, string, num_substrings);
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
