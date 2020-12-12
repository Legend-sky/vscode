/*
 * @Author: Whx
 * @Date: 2020-11-15 23:35:39
 * @LastEditTime: 2020-11-16 19:29:51
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

ll n, W, cnt, sum;
ll a[N], k[N], r[N];
bool cmp(int i, int j)
{
    return a[i] < a[j];
}
inline void solve()
{
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        k[i] = i;
    }
    // sort(k + 1, k + n + 1, cmp);     从小到大就会错，从大到小就对
    // sum = cnt = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (sum + a[k[i]] > W)
    //         continue;
    //     sum += a[k[i]];
    //     r[++cnt] = k[i];
    // }
    sort(k + 1, k + n + 1, cmp);
    sum = cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum + a[k[i]] > W)
            continue;
        sum += a[k[i]];
        r[++cnt] = k[i];
    }
    if (sum * 2 >= W)
    {
        cout << cnt << endl;
        for (int i = 1; i <= cnt; i++)
            cout << r[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
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
