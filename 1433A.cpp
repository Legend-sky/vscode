/*
 * @Autor: Whx
 * @Date: 2020-10-27 12:31:41
 * @LastEditTime: 2020-10-27 12:59:22
 */
#include <bits/stdc++.h>

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
    int ws = 1;
    cin >> n;
    while (n > 10)
    {
        n /= 10;
        ws++;
    }
    cout << (n - 1) * 10 + (1 + ws) * ws / 2 << endl;
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
