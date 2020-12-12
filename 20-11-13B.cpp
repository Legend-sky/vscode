/*
 * @Autor: Whx
 * @Date: 2020-11-13 22:49:31
 * @LastEditTime: 2020-11-13 23:03:50
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

int n;
int b[1005];
bool f;

inline void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b + n);
    f = false;
    for (int i = 1; i < n; i++)
    {
        if (b[i] == b[i - 1])
        {
            f = true;
            break;
        }
    }
    if (f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
