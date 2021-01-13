/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-13 10:36:53
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int t, n, res, a[210], i, j, s, k, l, r;
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i++)
		{
			cin >> s >> k;
			l = (min(s, k) + 1) / 2;
			r = (max(s, k) + 1) / 2;
			for (j = l; j <= r; j++)
				a[j]++;
		}
		res = a[1];
		for (i = 2; i <= 200; i++)
			res = max(res, a[i]);
		cout << res * 10 << endl;
	}
	return 0;
}