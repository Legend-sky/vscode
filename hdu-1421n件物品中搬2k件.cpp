#include<iostream>
#include<algorithm>
using namespace std;
int a[2020];
int dp[2020][2020];			//dp[i][j]表示前i件物品取j对的最优解
int main()
{
	int n, k, i, j;
	while (cin >> n >> k) {
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		for (i = 2; i <= n; i++) {
			for (j = 1; j <= k; j++) {
				if (i == 2 * j) {
					dp[i][j] = dp[i - 2][j - 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
				}
				else if (i > 2 * j) {
					dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]));
				}
			}
		}
		cout << dp[n][k] << endl;
	}
}