#include <stdio.h>

int main(int argc, char** argv)
{
	char input[13];
	int op[6] = {5, 4, 3, 2, 1, 0}; /* 5 - x */
	int a[6][6] = {	{8, 2, 4, 1, 3, 8},
					{3, 8, 0, 5, 8, 2},
					{1, 5, 8, 8, 0, 4},
					{4, 0, 8, 8, 5, 1},
					{2, 8, 5, 0, 8, 3},
					{8, 3, 1, 4, 2, 8}}; /* looks pretty */
	char* base;
	char* rot;
	char* f = "FALSE";
	char* t = "TRUE";
	char* ret;
	int i, j;

	while(scanf("%s\n",input) > 0)
	{
		base = input;
		rot = &input[6];
		ret = f;

		for(i = 0; i < 6; i++)
		{
			if(base[0] == rot[i] && base[5] == rot[op[i]])
			{
				for(j = 0; j < 6; j++)
				{
					if(j != i && j != op[i] && base[1] == rot[j] && base[4] == rot[op[j]] &&
						base[2] == rot[a[i][j]] && base[3] == rot[op[a[i][j]]])
					{
						ret = t;
						i = 6;
						j = 6;
					}
				}
			}
		}
		printf("%s\n", ret);
	}

	return 0;
}