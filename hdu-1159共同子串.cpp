#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[500], b[500];
int dp[500][500];
int main()
{
	int i, j;
	int n1, n2;
	while (cin >> a >> b) {
		n1 = strlen(a);
		n2 = strlen(b);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n1; i++) {
			for (j = 1; j <= n2; j++) {
				if (a[i - 1] == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		cout << dp[n1][n2] << endl;
	}
}