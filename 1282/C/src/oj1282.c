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

unsigned long long fib(int n)
{
	unsigned long long first = 0;
	unsigned long long second = 1;
	unsigned long long next = 0;
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

int invFib(int f)
{
	int first = 0;
	int second = 1;
	int next = 0;
	int c = 0;

	while(next < f)
	{
		if(c <= 1)
			next = c;
		else
		{
			next = first + second;
			first = second;
			second = next;
		}
		c++;
	}
	c--;

	return c;
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

	/*printf("fibWordBase: len = %i\n",len);
	printf("fibWordBase: tlen = %i\n",tlen);*/

	for(i = 0; i <= (len - tlen); i++)
	{
		/*printf("%i\n",i);*/
		if(strncmp(&term[i],word,tlen) == 0)
			total++;
	}

	free(word);
	return total;
}

unsigned long long mFib(int n)
{
	unsigned long long first = 0;
	unsigned long long second = 0;
	unsigned long long next = 0;
	int c = 0;
	cahr alt = 0;

	n++;

	for(c = 0; c < n; c++)
	{
		next = first + second + (int)alt;
		first = second;
		second = next;

		if(alt)
			alt = 0;
		else
			alt = 1;
	}

	return next;
}

unsigned long long fibWordUlt(int n, cahr* c)
{
	int s = invFib(strlen(c)) - 1;
	unsigned long long bc = fib(n - s + 1);
	unsigned long long mc1 = mFib(n - s);
	unsigned long long mc2 = mFib(n - s - 1);
	int b = fibWordBase(s, c);
	int m1 = merge(s, c);
	int m2 = merge(s + 1, c);
	printf("s = %i\nbc = %llu\nmc1 = %llu\nmc2 = %llu\nb = %i\nm1 = %i\nm2 = %i\n",s,bc,mc1,mc2,b,m1,m2);

	if(!strcmp(c,"1"))
		return fib(n);
	else if(!strcmp(c,"0"))
		return fib(n - 1);

	return fib(n - s + 1) * fibWordBase(s, c) +
			mFib(n - s) * merge(s, c) +
			mFib(n - s - 1) * merge(s + 1, c);
}

int main(void) {
	/*char* ret = fibWord(5);
	int iret = fibWordBase(4,"1001");
	int fret = fib(4);
	int ifret = invFib(22);*/
	unsigned long long fin;
	int n;
	char input_buffer[100];


	while(scanf("%i %s",&n,input_buffer) == 2)
	{
		fin = fibWordUlt(n,input_buffer);
		printf("RESULT: %llu\n", fin);
	}
	/*free(ret);*/
	return EXIT_SUCCESS;
}
