/*
 * @Autor: Whx
 * @Date: 2020-10-25 11:14:25
 * @LastEditTime: 2020-10-25 11:22:55
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

inline void solve(int n)
{
    long long f[60];
    f[1] = 1, f[2] = 2, f[3] = 3;
    for (int i = 4; i < 55; i++)
        f[i] = f[i - 1] + f[i - 3];
    cout << f[n] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n, n)
        solve(n);
    return 0;
}
