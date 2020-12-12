/*
 * @Autor: Whx
 * @Date: 2020-10-28 18:36:53
 * @LastEditTime: 2020-10-28 18:40:55
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

inline void solve()
{
    char a[50];
    cin >> a;
    for (int i = 0; a[i]; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
    }
    cout << a << endl;
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
