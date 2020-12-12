/*
 * @Autor: Whx
 * @Date: 2020-11-13 22:16:50
 * @LastEditTime: 2020-11-13 22:20:34
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

int n, x, a[60], b[60];
bool f;
bool cmp(int a, int b)
{
    return a > b;
}

inline void solve()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n, cmp);
    f = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] + b[i] > x)
        {
            f = false;
            break;
        }
    }
    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
