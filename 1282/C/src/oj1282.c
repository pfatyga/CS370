#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int fib(int n)
{
	unsigned long long int first = 0;
	unsigned long long int second = 1;
	unsigned long long int next = 0;
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
	char* ret = (char*)calloc(len, sizeof(char));
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

int fibWordBase(int loc, char* term)
{
	char* word = fibWord(loc);
	int len = fib(loc + 1);
	int tlen = strlen(term);
	int i;
	int total = 0;

	for(i = 0; i <= (len - tlen); i++)
	{
		if(strncmp(&term[i],word,tlen) == 0)
			total++;
	}

	free(word);
	return total;
}

unsigned long long int mFib(int n)
{
	unsigned long long int first = 0;
	unsigned long long int second = 0;
	unsigned long long int next = 0;
	int c = 0;
	char alt = 0;

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

unsigned long long int fibWordUlt(int n, char* c)
{
	int s = invFib(strlen(c)) - 1;
	char* test;

	if(!strcmp(c,"1"))
		return fib(n);
	else if(!strcmp(c,"0"))
	{
		if(n != 0)
			return fib(n - 1);
		else
			return 1;
	}
	/*else if(!strcmp(c,"-"))
	{
		test = fibWord(n);
		printf("%s\n",test);
		free(test);
		return 0;
	}*/

	return fib(n - s + 1) * fibWordBase(s, c) +
			mFib(n - s) * merge(s, c) +
			mFib(n - s - 1) * merge(s + 1, c);
}

int main(void) {
	unsigned long long int fin;
	int n;
	char input_buffer[200000];
	int c = 1;

	while(scanf("%i\n%s",&n,input_buffer) == 2)
	{
		fin = fibWordUlt(n,input_buffer);
		printf("Case %i: %llu\n", c,fin);
		c++;
	}
	return 0;
}
