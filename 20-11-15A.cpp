/*
 * @Autor: Whx
 * @Date: 2020-11-15 22:39:20
 * @LastEditTime: 2020-11-15 22:58:35
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

inline void solve()
{
    cin >> n;
    cout << n << endl;
    for (int i = 1; i < n; i++)
    {
        cout << i << " ";
    }
    cout << n << endl;
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
