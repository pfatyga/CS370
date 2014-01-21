/**
 *	Problem 146.
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

string getNextPermutation( string code )
{
	int lIndex, rIndex;
	bool nextPermutationExists = false;

	for ( int j = code.length() - 1; j > 0 && nextPermutationExists == false; j-- )
	{
		for ( int i = j - 1; i >= 0 && nextPermutationExists == false; i-- )
		{
			if ( code.at( j ) > code.at( i ) )
			{
				nextPermutationExists = true;
				lIndex = i;
				rIndex = j;
			}
		}
	}

	if ( !nextPermutationExists )
	{
		return "NONE";
	}

	// Insert char at j before i
	string part1 = code.substr( 0, lIndex );
	char part2 = code.at( rIndex );

	string part3 = code.substr( lIndex, rIndex - lIndex );
	string part4 = code.substr( rIndex + 1 );

	string restOfCode = part3 + part4;
	sort( restOfCode.begin(), restOfCode.end() );

	return part1 + part2 + restOfCode;

	//return code.substr( 0, lIndex ) + code.at( rIndex ) + code.substr( lIndex, rIndex - lIndex ) + code.substr( rIndex + 1 );
}

int main()
{
	string code = "";

	cin >> code;

	while ( code != "#" )
	{
		string nextCode = getNextPermutation( code );
		
		/*while ( nextCode != "NONE" )
		{
			cout << nextCode << "\n";
			nextCode = getNextPermutation( nextCode );
		}*/

		if ( nextCode == "NONE" )
		{
			cout << "No Successor\n";
		}
		else
		{
			cout << nextCode << "\n";
		}

		cin >> code;
	}

	return 0;
}
