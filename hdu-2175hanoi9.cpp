/*
列一下表
1 1
2 2   2^1
3 1
4 3   2^2
5 1
6 2
7 1
8 4   2^3
9 1
10 2
11 1
12 3
13 1
14 2
15 1
16 5  2^4
*/
#include<iostream>
using namespace std;
int main()
{
	int n, i;
	unsigned long long m, a[65];
	a[0] = 0;
	a[1] = 1;
	for (i = 2; i <= 64; i++)
		a[i] = a[i - 1] * 2 + 1;
	while (cin >> n >> m && (n || m))
	{
		for (i = 1; i <= n; i++)
		{
			if (m % 2 == 1) break;
			m /= 2;
		}
		cout << i << endl;
	}
	return 0;
}