/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-13 10:07:14
 */
#include <iostream>
using namespace std;
int main()
{
	int res, i, n, a[105];
	while (cin >> n && n)
	{
		for (i = 0; i < n; i++)
			cin >> a[i];
		res = a[0] * 6 + 5;
		for (i = 1; i < n; i++)
		{
			if (a[i - 1] < a[i])
				res = res + (a[i] - a[i - 1]) * 6 + 5;
			else
				res = res + (a[i - 1] - a[i]) * 4 + 5;
		}
		cout << res << endl;
	}
}
