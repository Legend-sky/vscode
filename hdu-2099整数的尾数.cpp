#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, n, i;
	while (cin >> a >> b && (a != 0 || b != 0))
	{
		for (i = 0; i < 100; i++)
		{
			n = a * 100 + i;
			if (n % b == 0)
			{
				cout << setfill('0') << setw(2) << i;
				break;
			}
		}
		for (i = i + 1; i < 100; i++)
		{
			n = a * 100 + i;
			if (n % b == 0)
			{
				cout << ' ';
				cout << setfill('0') << setw(2) << i;
			}
		}
		cout << endl;
	}
	return 0;
}