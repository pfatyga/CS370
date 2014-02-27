#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	vector<vector<vector<unsigned long long>>> move_op(0); //dynamic programming 3d vector base
	vector<vector<bool>> pawns(0);
	int N; //size of grid
	int M; //max number of turns
	int T; //number of test cases
	int S;
	int t_r; //turns remaining
	int x; //x position of leaper
	int y; //y position of leaper
	string input; //for parsing the input board
	int i, j; //for loops
	int k, l;

	cin >> T;
	//cout << "got T" << endl;
	while (T > 0) //each test case uses seperate grid and move_op sizes & data
	{
		//cout << "input S M S" << endl;
		cin >> N >> M >> S;
		//cout << "got input" << endl;
		//make 3d vector with size [M,N,N] and all initial values = 0
		move_op.assign(M, vector<vector<unsigned long long>>(N, vector<unsigned long long>(N)));
		//2d vector with size [N,N] and all initial values = false;
		pawns.assign(N, vector<bool>(N, false));
		//cout << "vectors made" << endl;
		//parse input board
		for (j = 0; j < N; j++)
		{
			//cout << "j = " << j << endl;
			cin >> input;
			//cout << "got str input" << endl;
			for (i = 0; i < N; i++)
			{
				//cout << "i = " << i << endl;
				if (input[i] == 'P')
				{
					pawns[i][j] = true;
					//cout << "P(" << i << "," << j << ")" << endl;
				}
				else if (input[i] == 'L')
				{
					x = i;
					y = j;
					//cout << "L(" << x << "," << y << ")" << endl;
				}
			}
		}

		//oh god, the nested loops (where the fairy magic happens)
		for (t_r = 0; t_r < M; t_r++)
		{
			//cout << "t_r = " << t_r << endl;
			for (i = 0; i < N; i++) //x value of space to fill
			{
				//cout << " i = " << i << endl;
				for (j = 0; j < N; j++) //y value of space to fill
				{
					//cout << " j = " << j << endl;
					if (!pawns[i][j]) //test for pawns at start location
					{
						for (k = -S; k <= S; k++) //x offset of space to add
						{
							//cout << "  k = " << k << endl;
							for (l = -(S - abs(k)); l <= (S - abs(k)); l++) //y offset of space to add
							{
								//cout << "  l = " << l << endl;
								if (i + k >= 0 && j + l >= 0 && //test lower bounds 
									i + k < N  && j + l < N  && //test upper bounds
									!pawns[i + k][j + l]) //test for pawns
								{
									//cout << "   HELLO! :D" << endl;
									if (!t_r) //lowest level
										move_op[t_r][i][j]++;
									else //not lowest level
										move_op[t_r][i][j] += move_op[t_r - 1][i + k][j + l];
								}
							}
						}
					}
				}
			}
		}

		cout << move_op[M - 1][x][y] << endl;

		T--;
	}
	//cout << "done" << endl;
	//cin.ignore();
	//cin.ignore();
	return 0;
}
