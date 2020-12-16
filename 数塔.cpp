#include<iostream>
#include<algorithm>
using namespace std;
int t, n, f[105][105], dp[105][105];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				cin >> f[i][j];
		dp[0][0] = f[0][0];
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0) dp[i][j] = dp[i - 1][j] + f[i][j];
				else if (j == i) dp[i][j] = dp[i - 1][j - 1] + f[i][j];
				else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + f[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, dp[n - 1][i]);
		cout << ans << endl;
	}
}