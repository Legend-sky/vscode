#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[100010][12];		//��i���jλ���ϵ��ڱ�
int main()
{
	int n, x, t;
	while (scanf_s("%d", &n) != EOF && n) {
		int i, j, m = 0;
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < n; i++) {
			scanf_s("%d %d", &x, &t);
			dp[t][x]++;
			if (t > m) m = t;
		}
		for (i = m - 1; i >= 0; i--) {
			for (j = 0; j <= 10; j++) {
				dp[i][j] += max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i + 1][j + 1]));		//��������������...
			}
		}
		cout << dp[0][5] << endl;
	}
	return 0;
}