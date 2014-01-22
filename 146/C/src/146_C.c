/*
 ============================================================================
 Name        : 146_C.c
 Author      : Mark Fleres
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char* str)
{
	int n = strlen(str);
	int i = 0;
	int j = 0;
	char temp = 0;

	for (i=0; i<n-1; i++)
	{
		for (j=i+1; j<n; j++)
	    {
		    if (str[i] > str[j])
	        {
		        temp = str[i];
	            str[i] = str[j];
	            str[j] = temp;
	        }
	    }
    }
}

int main(void) {
	char* input_buffer = (char*)calloc(51,sizeof(char));
	char* output_buffer = (char*)calloc(51,sizeof(char));
	char* restOfCode = NULL;
	int lIndex = 0;
	int rIndex = 0;
	char nextPermutationExists = 0; /*false*/
	int input_length = 0;
	int i = 0;
	int j = 0;

	scanf("%s",input_buffer);

	while(*input_buffer != '#')
	{
		nextPermutationExists = 0;
		input_length = strlen(input_buffer);
		for(j = input_length - 1; j > 0 && nextPermutationExists == 0; j--)
		{
			for(i = j - 1; i >= 0 && nextPermutationExists == 0; i--)
			{
				if(input_buffer[j] > input_buffer[i])
				{
					nextPermutationExists = 1;
					lIndex = i;
					rIndex = j;
					/*printf("l: %i\nr: %i\n",i,j);*/
				}
			}
		}


		if ( nextPermutationExists == 0)
		{
			printf("No Successor\n");
		}
		else
		{

			memcpy(output_buffer,input_buffer,lIndex);

			output_buffer[lIndex] = input_buffer[rIndex];

			restOfCode = &output_buffer[lIndex+1];

			memcpy(restOfCode,&input_buffer[lIndex],rIndex - lIndex);

			memcpy(&restOfCode[rIndex-lIndex],&input_buffer[rIndex+1],50-rIndex-1);
			sortString(restOfCode);

			printf("%s\n",output_buffer);
		}

		scanf("%s",input_buffer);
	}

	free(input_buffer);
	free(output_buffer);
	return 0;
}
