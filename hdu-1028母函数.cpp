#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int lmax = 200;
int c1[lmax], c2[lmax];
int dp_solve(int x)
{
	int dp[121][121], i, j;		//dp[i][j]表示用1~j面值组成i的方案数
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= 120; i++)
		dp[1][i] = dp[i][1] = 1;
	for (i = 2; i <= 120; i++) {
		for (j = 2; j <= 120; j++) {
			if (i > j)
				dp[i][j] = dp[i][j - 1] + dp[i - j][j];		//前者是不选j，后者选j
			else if (i == j)
				dp[i][j] = dp[i][j - 1] + 1;
			else
				dp[i][j] = dp[i][i];
		}
	}
	return dp[x][x];
}
int completebag(int x)
{
	int dp[121];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= 120; i++) {
		for (int j = i; j <= 120; j++) {
			dp[j] += dp[j - i];
		}
	}
	return dp[x];
}
int main()
{
	int n, i, j, k;
	while (cin >> n) {
		for (i = 0; i <= n; i++) {
			c1[i] = 1;
			c2[i] = 0;
		}
		for (i = 2; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				for (k = 0; k + j <= n; k += i) {
					c2[j + k] += c1[j];
				}
			}
			for (j = 0; j <= n; j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[n] << endl;
		cout << dp_solve(n) << endl;
		cout << completebag(n) << endl;
	}
	return 0;
}