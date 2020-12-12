/*
 * @Autor: Whx
 * @Date: 2020-10-28 18:31:26
 * @LastEditTime: 2020-10-28 18:34:37
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n, m, a[1005];
bool cmp(int a, int b)
{
    return a > b;
}

inline void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, cmp);
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
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
