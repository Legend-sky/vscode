/*
 * @Autor: Whx
 * @Date: 2020-11-15 23:10:19
 * @LastEditTime: 2020-11-15 23:28:50
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

int n, m;
int a[20][20];

inline void solve()
{
    cin >> n >> m;
    bool f = false;
    int num_neg = 0, min_num = 101, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                f = true;
            else if (a[i][j] < 0)
                num_neg++;
            if (abs(a[i][j]) < min_num)
                min_num = abs(a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] < 0)
                a[i][j] = -1 * a[i][j];
            ans += a[i][j];
        }
    }
    if (f)
    {
        cout << ans << endl;
    }
    else
    {
        if (num_neg % 2 == 1)
            cout << ans - 2 * min_num << endl;
        else
            cout << ans << endl;
    }
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
