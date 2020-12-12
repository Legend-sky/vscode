/*
 * @Autor: Whx
 * @Date: 2020-10-28 14:02:40
 * @LastEditTime: 2020-10-28 14:54:57
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n;
int dp[100005][12];
inline void solve(int n)
{
    memset(dp, 0, sizeof(dp));
    int x, t, m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> t;
        dp[t][x]++;
        if (t > m)
            m = t;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 10; j++)
        {
            dp[i][j] += max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i + 1][j + 1]));
        }
    }
    cout << dp[0][5] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n, n)
    {
        solve(n);
    }
    return 0;
}
