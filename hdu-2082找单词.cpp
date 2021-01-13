/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-11 15:21:40
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*int main()
{
	int n, x[27], dp[51];
	cin >> n;
	while (n--)
	{
		for (int i = 1; i <= 26; i++)
		{
			int a;
			cin >> a;
			x[i] = a;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= 26; i++)
			for (int j = 50; j >= i; j--) //从后往前，保证后面的答案都是由前面推出来的
				for (int k = 1; k <= x[i]; k++)
					if (j - k * i >= 0 && dp[j - k * i] != 0)
						dp[j] += dp[j - k * i];
		int sum = 0;
		for (int i = 1; i <= 50; i++)
			sum += dp[i];
		cout << sum << endl;
	}
	return 0;
}*/
int c1[55], c2[55];
int a[30], n;
void solve()
{

	for (int i = 1; i <= 26; i++)
	{
		cin >> a[i];
	}
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	for (int i = 0; i <= a[1]; i++)
	{
		c1[i] = 1;
	}
	for (int i = 2; i <= 26; i++)
	{
		for (int j = 0; j <= 50; j++)
		{
			for (int k = 0; j + k <= 50 && k <= a[i] * i; k += i)
			{
				c2[j + k] += c1[j];
			}
		}
		for (int j = 0; j <= 50; j++)
		{
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
	int sum = 0;
	for (int i = 1; i <= 50; i++)
	{
		sum += c1[i];
	}
	cout << sum << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		solve();
	}
	return 0;
}