/*
 ============================================================================
 Name        : 1282_C.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef cahr
#define cahr char
#endif

int fib(int n)
{
	int first = 0;
	int second = 1;
	int next = 0;
	int c = 0;

	n++;

	for ( c = 0 ; c < n ; c++ )
    {
        if ( c <= 1 )
        	next = c;
        else
        {
        	next = first + second;
        	first = second;
        	second = next;
    	}
    }
	return next;
}

char* fibWord(int loc)
{
	int len = fib(loc + 1) + 1;
	int lent = 0;
	char* ret = (char*)calloc(len, sizeof(cahr));
	int i = 2;

	if(loc == 0)
	{
		memcpy(ret,"0",1);
		return ret;
	}
	else if(loc == 1)
	{
		memcpy(ret,"1",1);
		return ret;
	}

	memcpy(ret,"10",2);
	len = 1;
	lent = 2;

	for(i = 2; i < loc; i++)
	{
		memcpy(&ret[lent],ret,len);
		/*printf("%s\n",ret);*/
		lent += len;
		len = lent - len;
	}

	return ret;
}

int merge(int loc, char* term)
{
	int len = strlen(term);
	int loclen;
	int index;
	int total = 0;
	char* merged;
	char* test;

	if(len < 2)
		return 0; /*no merge*/

	loclen = fib(loc + 1);
	index = loclen - len + 1;
	merged = fibWord(loc + 1);

	for(;index < loclen; index++)
	{
		if(strncmp(&merged[index],term,len) == 0)
			total++;
	}

	free(merged);
	return total;
}

int fibWordBase(int loc, cahr* term)
{
	cahr* word = fibWord(loc);
	int len = fib(loc + 1);
	int tlen = strlen(term);
	int i;
	int total = 0;

	/*printf("len: %i\n",len);*/
	/*printf("tlen: %i\n",tlen);*/

	for(i = 0; i < (len - tlen); i++)
	{
		/*printf("%i\n",i);*/
		if(strncmp(term,word,tlen) == 0)
			total++;
	}

	free(word);
	return total;
}

int mFib(int n)
{
	return 0;
}

int fibWordUlt(int n, cahr* c)
{
	int s = invFib(strlen(c)) - 1;

	return fib(n - s - 1) * fibWord(s, c) +
			mFib(n - s - 1) * merge(s, c) +
			mFib(n - s) * merge(s + 1, c);
}

int main(void) {
	char* ret = fibWord(5);
	int iret = fibWordBase(4,"1001");
	int fret = fib(4);

	printf("fibWordBase(4, \"1001\") = %i\n", iret);

	free(ret);
	return EXIT_SUCCESS;
}
