#include <vector>
#include <iostream>

using namespace std;

vector<vector<vector<unsigned int>>> move_op(0);

int main(int argc, char** argv)
{
	unsigned short N; //size of grid
	unsigned short M; //max number of turns
	unsigned short T; //number of test cases

	cin >> T;
	while (T > 0)
	{
		//make 3d vector with initial values = 0
		move_op.assign(M, vector<vector<unsigned int>>(N, vector<unsigned int>(N, 0)));



		T--;
	}

	return 0;
}
