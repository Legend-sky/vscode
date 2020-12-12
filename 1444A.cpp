/*
 * @Autor: Whx
 * @Date: 2020-11-08 10:29:07
 * @LastEditTime: 2020-11-08 11:05:08
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

ll p, q, ans;
void check(ll x)
{
    ll tmp = p;
    while (tmp % q == 0)
        tmp /= x;
    ans = max(ans, tmp);
}
inline void solve()
{

    cin >> p >> q;
    ans = 1;
    for (ll i = 2; i * i <= q; i++)
    {
        if (q % i == 0)
        {
            check(q / i);
            check(i);
        }
    }
    check(q);
    cout << ans << '\n';
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
