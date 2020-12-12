/*
 * @Author: Whx
 * @Date: 2020-12-02 23:15:38
 * @LastEditTime: 2020-12-02 23:27:13
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

int n, x, a[505];

inline void solve()
{
    cin >> n >> x;
    int las = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
            las = i;
    }
    for (int i = 0; i <= las; i++)
    {
        if (a[i] > x)
        {
            ++cnt;
            swap(x, a[i]);
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            cnt = -1;
            break;
        }
    }
    cout << cnt << endl;
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
