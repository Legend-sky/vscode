#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int w[105][105], dp[105][105];
	int n, c, i, j;
	cin >> c;
	while (c--)
	{
		memset(w, 0, sizeof(w));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= i; j++)
				cin >> w[i][j];
		dp[1][1] = w[1][1];
		for (i = 2; i <= n; i++)
		{
			dp[i][1] = dp[i - 1][1] + w[i][1];
			for (j = 2; j < i; j++)
				dp[i][j] = max(dp[i - 1][j] + w[i][j], dp[i - 1][j - 1] + w[i][j]);
			dp[i][i] = dp[i - 1][i - 1] + w[i][i];
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = max(res, dp[n][i]);
		cout << res << endl;
	}
	return 0;
}