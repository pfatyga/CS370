//============================================================================
// Name        : 4864.cpp
// Author      : Peter
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int NumberOfSetBits(int i)
{
	int num_of_set_bits = 0;
	while(i != 0)
	{
		if(i & 1 == 1)
			num_of_set_bits++;
		i >>= 1;
	}
	return num_of_set_bits;
}

/*int NumberOfSetBits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}*/

int K(int i) {
	int k = 1;	//start with 1 because when it gets to 1 it should get incremented
	while((i = NumberOfSetBits(i)) != 1)
			k++;
	return k;
}

int K_values[65] = {0, 0, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 2, 1, 2, 2, 3, 2, 3, 3, 2, 2, 3, 3, 2, 3, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 2, 2, 3, 3, 2, 3, 2, 2, 3, 2, 3, 3, 2, 3, 2, 2, 3, 3, 2, 2, 3, 2, 3, 3, 3, 1 };

int main() {
	/*for(int i = 100000; i <= 100500; i++)
		cout << NumberOfSetBits(i) << "\n";*/
	int LO, HI, X;
	cin >> LO >> HI >> X;
	while(LO != 0 && HI != 0 && X != 0)
	{
		int num_X_equal_K = 0;
		while(LO <= HI)
		{
			/*if(LO < 64)
			{
				if(K_values[LO] == X)
					num_X_equal_K++;
			}
			else
			{*/
				if((K_values[NumberOfSetBits(LO)] + 1) == X)
					num_X_equal_K++;
			//}
			LO++;
		}
		cout << num_X_equal_K << '\n';
		cin >> LO >> HI >> X;
	}
	return 0;
}
