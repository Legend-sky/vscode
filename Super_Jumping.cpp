/*
 * @Autor: Whx
 * @Date: 2020-10-28 14:56:26
 * @LastEditTime: 2020-10-28 15:04:56
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int dp[1005], a[1005];
inline void solve(int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (cin >> T, T)
    {
        solve(T);
    }
    return 0;
}
