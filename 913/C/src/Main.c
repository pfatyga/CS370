#include <stdio.h>

int main()
{
	unsigned long long n;

	while (scanf("%llu", &n) == 1)
	{
		
		if (n % 2)
		{
			if (n == 1)
			{
				printf("1\n");
			}
			else
			{
				n = (n + 1) / 2;
				printf("%llu\n", (6 * n * n - 9));
			}
		}
		else
		{
			printf("0\n");
		}
	}

	return 0;
}
