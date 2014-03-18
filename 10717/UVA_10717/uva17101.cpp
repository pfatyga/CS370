#include <limits.h>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	int r;

	while ( b != 0) {
	    r = a % b;
	    a = b;
		b = r;
	}

    return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main()
{
	int n;
	int t;
	int i;
	int mine;
	int mlow;
	int mhigh;
	int low;
	int high;
	//int* coins;
	vector<int> coins;
	int h;
	int a, b, c, d;

	while(1)
	{
		//scanf("%i %i",&n,&t);
		cin >> n >> t;
		if(!n && !t)
			return 0;

		//coins = (int*)calloc(n,sizeof(int));
		coins = vector<int>(n);

		for(i = 0; i < n; i++)
		{
			//scanf("%i",&coins[i]);
			cin >> coins[i];
		}

		for(i = 0; i < t; i++)
		{
			low = 0;
			high = INT_MAX;
			//scanf("%i",&h);
			cin >> h;

			for(a = 0; a < n; a++)
				for(b = a + 1; b < n; b++)
					for(c = b + 1; c < n; c++)
						for(d = c + 1; d < n; d++)
						{
							mine = lcm(lcm(coins[a],coins[b]),lcm(coins[c],coins[d]));
							mlow = (h / mine) * mine;
							if(h % mine)
								mhigh = mlow + mine;
							else
								mhigh = mlow;
							if(mlow > low)
								low = mlow;
							if(mhigh < high)
								high = mhigh;
						}
			//printf("%i %i\n", low, high);
			cout << low << " " << high << endl;
		}

		//free(coins);
	}
	return 0;
}