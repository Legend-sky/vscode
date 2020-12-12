/*
 * @Autor: Whx
 * @Date: 2020-11-14 15:00:24
 * @LastEditTime: 2020-11-14 15:24:55
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

int a, b, c, d;

inline void solve()
{
    cin >> a >> b >> c >> d;
    cout << max(a + b, c + d) << endl;
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
