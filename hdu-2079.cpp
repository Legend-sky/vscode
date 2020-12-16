#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
/*int main()	15ms
{
	int n, m, t, a[10], b[12], dp[50];
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> a[i] >> b[i];
		dp[0] = 1;
		for (int i = 0; i < m; i++)
			for (int j = n; j >= a[i]; j--)
				for (int k = 1; k <= b[i]; k++)
					if (j - k * a[i] >= 0 && dp[j - k * a[i]] != 0)
						dp[j] = dp[j] + dp[j - k * a[i]];
		cout << dp[n] << endl;
	}
	return 0;
}*/
//2:dfs 124ms
int f[10];
int n, k, sum;
void dfs(int s, int t)
{
	if (s == n) sum++;
	if (s > n) return;
	for (int i = t + 1; i < 10; i++)
		for (int j = 1; j <= f[i]; j++)
			dfs(s + i * j, i);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		sum = 0;
		cin >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			f[a] = b;
		}
		for (int i = 1; i < 9; i++)
			for (int j = 1; j <= f[i]; j++)
				dfs(i * j, i);
		cout << sum << endl;
	}
}