/*
 * @Author: Whx
 * @Date: 2020-12-02 17:25:23
 * @LastEditTime: 2020-12-02 17:28:22
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

int n, x, y;

inline void solve()
{
    cin >> x >> y;
    int ans = 0;
    if (x == y)
        ans = x * 2;
    else
        ans = x + y + abs(x - y) - 1;
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
