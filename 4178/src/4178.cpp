//============================================================================
// Name        : 4178.cpp
// Author      : Peter
// Version     :
// Copyright   : 
// Description : Dezider's Fence - North American - Northeast - 2008/2009
//============================================================================

#include <iostream>
#include <vector>
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
	int ideal_minimum_distance;	//ideal minimum distance between each fence
	int max_distance_after_move;	//max distance after moving
	cin >> n;
	fence = new int[n];

	cin >> k;

	//get input
	for(int i = 0; i < n; i++)
		cin >> fence[i];

	size_of_fence = fence[n-1];

	ideal_minimum_distance = size_of_fence / (n-1);	//n-1 because that is how many spaces there are; ex: A -- B -- C, n = 3, spaces = 2

	//move fences
	for(int i = 1; i < (n-1); i++)
	{
		int target_position = i * ideal_minimum_distance;
		if(fence[i] == target_position)
			continue;
		else if(target_position > fence[i])
		{
			if(target_position - fence[i] <= k)
				fence[i] = target_position;
			else
				fence[i] += k;
		}
		else	//target_position < fence[i]
		{
			if(fence[i] - target_position <= k)
				fence[i] = target_position;
			else
				fence[i] -= k;
		}
	}

	max_distance_after_move = fence[1] - fence[0];	//initial value
	for(int i = 1; i < (n-1); i++)
		if(fence[i+1] - fence[i] > max_distance_after_move)
			max_distance_after_move = fence[i+1] - fence[i];

	cout << max_distance_after_move << '\n';

	delete[] fence;
	return 0;
}
