/*
 * @Author: Whx
 * @Date: 2020-10-28 15:06:28
 * @LastEditTime: 2021-01-13 16:25:49
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int dp[2005][1005];
int w[2005];

inline void
solve(int n, int k)
{
    memset(dp, 0, sizeof(dp));
    memset(w, 0, sizeof(w));
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w + 1, w + n + 1);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i == j * 2)
                dp[i][j] = dp[i - 2][j - 1] + (w[i] - w[i - 1]) * (w[i] - w[i - 1]);
            else if (i > j * 2)
                dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (w[i] - w[i - 1]) * (w[i] - w[i - 1]));
        }
    }
    cout << dp[n][k] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1, k = 1;
    while (cin >> n >> k)
    {
        solve(n, k);
    }
    return 0;
}
