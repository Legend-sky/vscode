/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-10 14:25:35
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int lmax = 260000;
int a[lmax], b[lmax], num[500], v[500], i, j, k, last, last2;
int main()
{
	int n;
	while (cin >> n && n > 0)
	{
		for (i = 0; i < n; i++)
			cin >> v[i] >> num[i];
		a[0] = 1;
		last = 0;
		for (i = 0; i < n; i++)
		{
			last2 = last + v[i] * num[i];
			memset(b, 0, sizeof(int) * (last2 + 1));
			for (j = 0; j <= num[i]; j++)
				for (k = 0; k <= last; k++)
					b[k + j * v[i]] += a[k];
			memcpy(a, b, sizeof(int) * (last2 + 1));
			last = last2;
		}
		for (i = last / 2; i >= 0 && a[i] == 0; i--)
			;
		cout << last - i << ' ' << i << endl;
	}
	return 0;
}