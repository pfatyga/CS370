#include <stdio.h>
#include <math.h>

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
                /*map 1,3,5,7,9,11 to 1,2,3,4,5,6,7*/
                n = (n / 2) + 1;    /*integer division truncates*/
                /*map 1,2,3,4,5,6,7 to 1,7,17,31,49,71*/
                unsigned long long last_num = 2 * n * n - 1;
                /*5 + 3 + 1 = 9 = 5 * 3 - 6*/				
				printf("%llu\n", (last_num * 3 - 6));
			}
		}
		else
		{
			printf("0\n");
		}
	}

	return 0;
}
