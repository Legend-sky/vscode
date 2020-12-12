/*
 * @Autor: Whx
 * @Date: 2020-10-28 16:43:47
 * @LastEditTime: 2020-10-28 16:55:50
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int dp[500][500];
char a[500], b[500];
inline void solve()
{
    memset(dp, 0, sizeof(dp));
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 1; i <= len_a; i++)
    {
        for (int j = 1; j <= len_b; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[len_a][len_b] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> a >> b)
        solve();
    return 0;
}
