/*
 * @Author: Whx
 * @Date: 2020-11-17 23:04:39
 * @LastEditTime: 2020-11-17 23:18:14
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n, k;
int a[200005];
ll ans = 0;

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n * k; i++)
        cin >> a[i];
    ans = 0;
    for (int i = n * k - n / 2; i >= n * k - (n / 2 + 1) * k; i -= (n / 2 + 1))
        ans += a[i];
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        solve();
    }
    return 0;
}
