#include <iostream>

using namespace std;

int main() {
	int num_testcases = 0;
	cin >> num_testcases;
	
	for(int i = 0; i < num_testcases; i++)
	{
		int N = 0;	//number of days of predicted stock prices
		cin >> N;
		int *prices = new int[N];
		int input;

		//get input and find max
		for(int j = 0; j < N; j++)
		{
			cin >> input;
			prices[j] = input;
		}

		int *next_max = new int[N+1];
		next_max[N] = -1;

		for(int i = N - 1; i >= 0; i--)
			next_max[i] = max(prices[i], next_max[i+1]);

		long profit = 0;
		long num_stocks = 0;
		//iterate from beginning to max
		for(int i = 0; i < N; i++)
		{
			int price = prices[i];
			int max_price = next_max[i+1];

			if(price > max_price)
			{
				profit += num_stocks * price;
				num_stocks = 0;
			}
			else if (price < max_price)
			{
				num_stocks += 1;
				profit -= price;
			}
		}

		cout << profit << '\n';

	}
	return 0;
}
