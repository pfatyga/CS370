//============================================================================
// Name        : 4215.cpp
// Author      : Peter
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int input = 0;
	cin >> input;
	while(input != 0)
	{
		int squares = 0;
		for(;input > 0; input--)
			squares += input*input;
		cout << squares << '\n';
		cin >> input;
	}
	return 0;
}
