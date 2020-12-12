/*
 * @Autor: Whx
 * @Date: 2020-11-08 09:47:39
 * @LastEditTime: 2020-11-08 10:23:35
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

struct rest
{
    ll a, b;
} rest[200005];
int n;
bool cmp(struct rest &A, struct rest &B)
{
    return A.a < B.a;
}
inline void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rest[i].a;
    for (int i = 0; i < n; i++)
        cin >> rest[i].b;
    sort(rest, rest + n, cmp);
    ll ans = rest[n - 1].a;
    ll ans_b = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (rest[i].a > rest[i].b)
        {
            ans_b += rest[i].b;
            ans = min(ans, max(rest[i - 1].a, ans_b));
        }
        else
            break;
    }
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
