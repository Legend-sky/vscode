#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, b[35], dp[35][35];
int dfs(int n, int t, bool ismax)
{
	if (!n) return 1;
	if (!ismax && dp[n][t] != -1) return dp[n][t];
	int m, res = 0;
	if (ismax) m = b[n];
	else m = 9;
	for (int i = 0; i <= m; i++)
	{
		if (i != 4 && !(t == 6 && i == 2)) res += dfs(n - 1, i, ismax && i == m);
	}
	if (!ismax) dp[n][t] = res;
	return res;
}
int solve(int x)
{
	int len;
	for (len = 0; x; x /= 10)
	{
		b[++len] = x % 10;
	}
	b[len + 1] = 0;
	return dfs(len, -1, true);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		memset(b, 0, sizeof(b));
		cout << solve(m) - solve(n - 1) << endl;
	}
	return 0;
}