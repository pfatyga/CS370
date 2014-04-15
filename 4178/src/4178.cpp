//============================================================================
// Name        : 4178.cpp
// Author      : Peter
// Version     :
// Copyright   : 
// Description : Dezider's Fence - North American - Northeast - 2008/2009
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

struct fence_post {
	int actual_position;
	int target_position;
};

int main() {
	int n;	//number of fence posts
	int k;	//amount each fence can be moved
	int *fence;	//array of fences
	int size_of_fence;	//difference of first and last
	float ideal_minimum_distance;	//ideal minimum distance between each fence
	int max_distance_after_move;	//max distance after moving
	cin >> n;
	fence = new int[n];

	cin >> k;

	//get input
	for(int i = 0; i < n; i++)
		cin >> fence[i];

	size_of_fence = fence[n-1];

	ideal_minimum_distance = (float)size_of_fence / (float)(n-1);	//n-1 because that is how many spaces there are; ex: A -- B -- C, n = 3, spaces = 2

	//move fences
	for(int i = 1; i < (n-1); i++)
	{
		int target_position = round(i * ideal_minimum_distance);
		if(fence[i] == target_position)
			continue;
		else if(target_position > fence[i])	//if it's before target position move left
		{
			if(target_position - fence[i] <= k)	//if we can reach it
			{
				if(fence[i+1] <= target_position)	//account for next fence being in the way
					fence[i] = fence[i+1]-1;
				else
					fence[i] = target_position;
			}
			else	//we cant reach, move as close as possible
			{
				if(fence[i+1] <= fence[i]+k)
					fence[i] = fence[i+1]-1;
				else
					fence[i] += k;
			}
		}
		else	//target_position < fence[i]; if it's after target position move right
		{
			if(fence[i] - target_position <= k)	//if we can reach it
			{
				if(fence[i-1] >= target_position)	//account for previous fence being in the way
					fence[i] = fence[i-1]+1;
				else
					fence[i] = target_position;
			}
			else
			{
				if(fence[i-1] >= fence[i]-k)
					fence[i] = fence[i-1]+1;
				else
					fence[i] -= k;
			}
		}
	}

	max_distance_after_move = fence[1] - fence[0];	//initial value
	for(int i = 1; i < (n-1); i++)
		if(fence[i+1] - fence[i] > max_distance_after_move)
			max_distance_after_move = fence[i+1] - fence[i];

	/*//PRINT OUT MOVED FENCES
	cout << fence[0];
	for(int i = 1; i < n; i++)
		cout << " " << fence[i];
	cout << '\n';*/

	cout << max_distance_after_move << '\n';

	delete[] fence;
	return 0;
}
