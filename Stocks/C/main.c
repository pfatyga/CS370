#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main() {
	int i;
	int j;
	int N;
	int *prices;
	int *next_max;
	int num_testcases = 0;
	long long profit = 0;
	long num_stocks = 0;
	scanf("%d", &num_testcases);
	
	for(i = 0; i < num_testcases; i++)
	{

		scanf("%d", &N);
		prices = (int *)malloc(N*sizeof(int));

		for(j = 0; j < N; j++)
		{
			scanf("%d", &prices[j]);
		}

		next_max = (int *)malloc((N+1)*sizeof(int));
		next_max[N] = -1;

		for(j = N - 1; j >= 0; j--)
			next_max[j] = max(prices[j], next_max[j+1]);

		
		for(j = 0; j < N; j++)
		{
			int price = prices[j];
			int max_price = next_max[j+1];

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

		printf("%llu\n", profit);
		profit = 0;
		num_stocks = 0;
		free(prices);
		free(next_max);

	}
	return 0;
}
