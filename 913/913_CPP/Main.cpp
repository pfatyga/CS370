#include <iostream>

using namespace std;

int main()
{
	unsigned long long n;

	while (!cin.eof())
	{
		cin >> n;
		
		if (n % 2)
		{
			if (n == 1)
			{
				cout << 1 << endl;
			}
			else
			{
				n = (n + 1) / 2;
				cout << 6 * n * n - 9 << endl;
			}
		}
		else
		{
			cout << 0 << endl;
		}
	}

	return 0;
}